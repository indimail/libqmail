/*
 * $Log: builtin_overflow.c,v $
 * Revision 1.1  2020-05-09 14:21:15+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifdef HAVE_CONFIG_H
#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif
#endif
#include "hasbltnoverflow.h"

#ifndef HAS_BUILTIN_OVERFLOW
int
__builtin_add_overflow(unsigned int a, unsigned int b, unsigned int *result)
{
	if (a > INT_MAX - b || b > INT_MAX - a) 
		return -1; 
	*result = a + b;
	return 0;
}

int
__builtin_mul_overflow(unsigned int a, unsigned int b, unsigned int *result)
{
	*result = a * b;
	if (b && a != (*result / b))
		return 1;
	if (a && b != (*result / a))
		return 1;
	return 0;
}
#endif
