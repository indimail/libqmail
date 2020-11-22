/*
 * $Log: stralloc_opyb.c,v $
 * Revision 1.7  2020-11-22 23:53:03+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.6  2020-05-13 07:27:07+05:30  Cprogrammer
 * fix possible integer overflow
 *
 * Revision 1.5  2019-07-19 14:08:46+05:30  Cprogrammer
 * fixed data type of length argument of stralloc_copyb()
 *
 * Revision 1.4  2004-10-22 20:30:51+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-10-09 23:34:13+05:30  Cprogrammer
 * prevent inclusion of function prototypes for stralloc functions
 *
 * Revision 1.2  2004-07-17 21:24:05+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "stralloc.h"
#include "byte.h"
#include "error.h"
#include "builtinoflmacros.h"

int
stralloc_copyb(stralloc *sa, const char *s, unsigned int n)
{
	unsigned int    i;

	if (__builtin_add_overflow(n, 1, &i)) {
		errno = error_nomem;
		return 0;
	}
	if (!stralloc_ready(sa, i))
		return 0;
	byte_copy(sa->s, n, s);
	sa->len = n;
	sa->s[n] = 'Z'; /*- ``offensive programming'' */
	return 1;
}

void
getversion_stralloc_opyb_c()
{
	static char    *x = "$Id: stralloc_opyb.c,v 1.7 2020-11-22 23:53:03+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
