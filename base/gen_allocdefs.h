/*
 * $Log: gen_allocdefs.h,v $
 * Revision 1.7  2020-11-22 23:51:19+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.6  2020-11-22 20:31:11+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.5  2020-05-13 06:06:42+05:30  Cprogrammer
 * moved overflow macros to builtinoflmacros.h
 *
 * Revision 1.4  2020-05-12 11:18:19+05:30  Cprogrammer
 * set errno to error_nomem on overflow
 *
 * Revision 1.3  2020-05-11 19:08:48+05:30  Cprogrammer
 * https://github.com/notqmail/notqmail/pull/128 (fix overflow CVE-2005-1513)
 *
 * Revision 1.2  2004-06-18 22:59:00+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef GEN_ALLOC_DEFS_H
#define GEN_ALLOC_DEFS_H
#include "builtinoflmacros.h"
#include "error.h"

#define GEN_ALLOC_readyplus(ta,type,field,len,a,base,ta_rplus) \
static int ta_rplus ## _internal (ta *x, unsigned int n, unsigned int pluslen) \
{ \
  unsigned int nlen; \
  if (x->field) { \
    if (__builtin_add_overflow(n, pluslen, &n)) { \
        errno = error_nomem; \
      return 0; } \
    if (n > x->a) { \
      unsigned int nnum; \
      if (__builtin_add_overflow(n, (n >> 3) + base, &nnum)) { \
        errno = error_nomem; \
        return 0; } \
      if (__builtin_mul_overflow(nnum, sizeof(type), &nlen)) { \
        errno = error_nomem; \
        return 0; } \
      if (!alloc_re((char *) &x->field,x->a * sizeof(type),nlen)) { \
        errno = error_nomem; \
        return 0; } \
      x->a = nnum; \
      return 1; } \
    return 1; } \
  x->len = 0; \
  if (__builtin_mul_overflow(n, sizeof(type), &nlen)) { \
    errno = error_nomem; \
    return 0; } \
  if (!(x->field = (type *) alloc(nlen))) \
    return 0; \
  x->a = n; \
  return 1; } \
int ta_rplus(ta *x, unsigned int n) \
{ return ta_rplus ## _internal (x, n, x->len); }

/*-
 * this needs a GEN_ALLOC_readyplus call before as it reuses the internal helper
 * function.
 */
#define GEN_ALLOC_ready(ta,type,field,len,a,base,ta_ready) \
int ta_ready(ta *x, unsigned int n) \
{ return ta_ready ## plus_internal (x, n, 0); }

#define GEN_ALLOC_append(ta,type,field,len,a,base,ta_rplus,ta_append) \
int ta_append(ta *x, const type *i) \
{ if (!ta_rplus(x,1)) return 0; x->field[x->len++] = *i; return 1; }

#endif
