/*
 * $Log: str_diff.c,v $
 * Revision 1.4  2020-11-22 23:53:23+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2004-10-22 20:30:56+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:16+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "str.h"

int
str_diff(register const char *s, register const char *t)
{
	register char   x;

	for (;;) {
		x = *s;
		if (x != *t)
			break;
		if (!x)
			break;
		++s;
		++t;
		x = *s;
		if (x != *t)
			break;
		if (!x)
			break;
		++s;
		++t;
		x = *s;
		if (x != *t)
			break;
		if (!x)
			break;
		++s;
		++t;
		x = *s;
		if (x != *t)
			break;
		if (!x)
			break;
		++s;
		++t;
	}
	return ((int) (unsigned int) (unsigned char) x) - ((int) (unsigned int) (unsigned char) *t);
}

void
getversion_str_diff_c()
{
	static char    *x = "$Id: str_diff.c,v 1.4 2020-11-22 23:53:23+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
