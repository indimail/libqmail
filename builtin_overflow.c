/*
 * $Log: builtin_overflow.c,v $
 * Revision 1.3  2020-05-09 18:44:03+05:30  Cprogrammer
 * renamed functions __builtin_xxx_overflow() with xxx_overflow()
 *
 * Revision 1.2  2020-05-09 17:40:39+05:30  Cprogrammer
 * use intermediary long long variable to hold result for checking overflow
 *
 * Revision 1.1  2020-05-09 14:21:15+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif
#include "hasbltnoverflow.h"

#ifndef HAS_BUILTIN_OVERFLOW
static inline int
check_ofl(unsigned long long val, unsigned int *res)
{
	if (val >> 32)
		return 1;
	*res = (unsigned int)val;
	return 0;
}

int
add_overflow(unsigned int a, unsigned int b, unsigned int *res)
{
	unsigned long long val = a;

	val += b;
	return check_ofl(val, res);
}

int
mul_overflow(unsigned int a, unsigned int b, unsigned int *res)
{
	unsigned long long val = a;

	val *= b;
	return check_ofl(val, res);
}
#endif
