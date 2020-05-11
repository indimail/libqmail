/*
 * $Log: gen_allocdefs.h,v $
 * Revision 1.3  2020-05-11 19:08:48+05:30  Cprogrammer
 * https://github.com/notqmail/notqmail/pull/128 (fix overflow CVE-2005-1513)
 *
 * Revision 1.2  2004-06-18 22:59:00+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef GEN_ALLOC_DEFS_H
#define GEN_ALLOC_DEFS_H
#include "hasbltnoverflow.h"

/*- From Rolf Eike Beer notqmail */
#ifndef HAS_BUILTIN_OVERFLOW
static inline int
check_ofl(unsigned long long val, unsigned int *res)
{
  if (val >> 32)
    return 1;
  *res = (unsigned int)val;
  return 0;
}

static inline int
add_overflow(unsigned int a, unsigned int b, unsigned int *res)
{
  unsigned long long val = a;

  val += b;
  return check_ofl(val, res);
}

static inline int
mul_overflow(unsigned int a, unsigned int b, unsigned int *res)
{
  unsigned long long val = a;

  val *= b;
  return check_ofl(val, res);
}
#define __builtin_add_overflow add_overflow
#define __builtin_mul_overflow mul_overflow
#endif /*- #ifndef HAS_BUILTIN_OVERFLOW */

#define GEN_ALLOC_readyplus(ta,type,field,len,a,base,ta_rplus) \
static int ta_rplus ## _internal (ta *x, unsigned int n, unsigned int pluslen) \
{ \
  unsigned int nlen; \
  if (x->field) { \
    if (__builtin_add_overflow(n, pluslen, &n)) \
      return 0; \
    if (n > x->a) { \
      unsigned int nnum; \
      if (__builtin_add_overflow(n, (n >> 3) + base, &nnum)) \
        return 0; \
      if (__builtin_mul_overflow(nnum, sizeof(type), &nlen)) \
        return 0; \
      if (!alloc_re(&x->field,x->a * sizeof(type),nlen)) \
        return 0; \
      x->a = nnum; \
      return 1; } \
    return 1; } \
  x->len = 0; \
  if (__builtin_mul_overflow(n, sizeof(type), &nlen)) \
    return 0; \
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
int ta_append(ta *x, type *i) \
{ if (!ta_rplus(x,1)) return 0; x->field[x->len++] = *i; return 1; }

#endif
