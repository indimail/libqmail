/*
 * $Log: stralloc_catb.c,v $
 * Revision 1.7  2020-11-22 23:52:49+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.6  2020-05-13 07:26:46+05:30  Cprogrammer
 * fix possible integer overflow
 *
 * Revision 1.5  2019-07-19 14:08:10+05:30  Cprogrammer
 * fixed data type of length argument of stralloc_catb()
 *
 * Revision 1.4  2004-10-22 20:30:46+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-10-09 23:33:34+05:30  Cprogrammer
 * prevent inclusion of function prototypes for stralloc functions
 *
 * Revision 1.2  2004-07-17 21:23:56+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "stralloc.h"
#include "byte.h"
#include "error.h"
#include "builtinoflmacros.h"

int
stralloc_catb(stralloc *sa, const char *s, unsigned int n)
{
	unsigned int    i;

	if (!sa->s)
		return stralloc_copyb(sa, s, n);
	if (__builtin_add_overflow(n, 1, &i)) {
		errno = error_nomem;
		return 0;
	}
	if (!stralloc_readyplus(sa, i))
		return 0;
	byte_copy(sa->s + sa->len, n, s);
	sa->len += n;
	sa->s[sa->len] = 'Z'; /*- ``offensive programming'' */
	return 1;
}

void
getversion_stralloc_catb_c()
{
	const char     *x = "$Id: stralloc_catb.c,v 1.7 2020-11-22 23:52:49+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
