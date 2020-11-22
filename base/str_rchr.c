/*
 * $Log: str_rchr.c,v $
 * Revision 1.4  2020-11-22 23:53:50+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2004-10-22 20:31:00+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:23+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "str.h"

unsigned int
str_rchr(register const char *s, int c)
{
	register char   ch;
	register char  *t;
	register char  *u;

	ch = c;
	t = s;
	u = 0;
	for (;;)
	{
		if (!*t)
			break;
		if (*t == ch)
			u = t;
		++t;
		if (!*t)
			break;
		if (*t == ch)
			u = t;
		++t;
		if (!*t)
			break;
		if (*t == ch)
			u = t;
		++t;
		if (!*t)
			break;
		if (*t == ch)
			u = t;
		++t;
	}
	if (!u)
		u = t;
	return u - s;
}

void
getversion_str_rchr_c()
{
	static char    *x = "$Id: str_rchr.c,v 1.4 2020-11-22 23:53:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
