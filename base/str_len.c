/*
 * $Log: str_len.c,v $
 * Revision 1.4  2020-11-22 23:53:47+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2004-10-22 20:30:59+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:22+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "str.h"

unsigned int
str_len(register const char *s)
{
	register char  *t;

	t = s;
	for (;;) {
		if (!*t)
			return t - s;
		++t;
		if (!*t)
			return t - s;
		++t;
		if (!*t)
			return t - s;
		++t;
		if (!*t)
			return t - s;
		++t;
	}
}

void
getversion_str_len_c()
{
	static char    *x = "$Id: str_len.c,v 1.4 2020-11-22 23:53:47+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
