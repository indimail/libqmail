/*
 * $Log: str_chr.c,v $
 * Revision 1.4  2020-11-22 23:53:09+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2004-10-22 20:30:53+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:11+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "str.h"

unsigned int
str_chr(register const char *s, int c)
{
	register char   ch;
	register char  *t;

	ch = c;
	t = s;
	for (;;) {
		if (!*t)
			break;
		if (*t == ch)
			break;
		++t;
		if (!*t)
			break;
		if (*t == ch)
			break;
		++t;
		if (!*t)
			break;
		if (*t == ch)
			break;
		++t;
		if (!*t)
			break;
		if (*t == ch)
			break;
		++t;
	}
	return t - s;
}

void
getversion_str_chr_c()
{
	static char    *x = "$Id: str_chr.c,v 1.4 2020-11-22 23:53:09+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
