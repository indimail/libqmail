/*
 * $Log: str_cpyb.c,v $
 * Revision 1.4  2020-11-22 23:53:16+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2018-04-25 21:37:41+05:30  Cprogrammer
 * BUG - Fixed extra copy
 *
 * Revision 1.2  2004-10-22 20:30:54+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-08-15 19:52:35+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "str.h"

unsigned int
str_copyb(register char *s, register const char *t, unsigned int max)
{
	register int    len;

	len = 0;
	while (max-- > 0) {
		if (!(*s = *t))
			return len;
		++s;
		++t;
		++len;
	}
	return len;
}

void
getversion_str_cpyb_c()
{
	const char     *x = "$Id: str_cpyb.c,v 1.4 2020-11-22 23:53:16+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
