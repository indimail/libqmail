/*
 * $Log: builtinoflmacros.h,v $
 * Revision 1.1  2020-05-13 06:02:51+05:30  Cprogrammer
 * Initial revision
 *
 */

#ifndef _BUILTIN_MACROS_H
#define _BUILTIN_MACROS_H
#include "hasbltnofl.h"
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
#endif /*- #ifndef _BUITLIN_MACROS_H */
