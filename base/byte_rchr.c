/*
 * $Log: byte_rchr.c,v $
 * Revision 1.5  2021-06-10 10:49:43+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.4  2020-11-22 23:50:01+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2004-10-22 20:32:22+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:16:50+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "byte.h"

unsigned int
byte_rchr(const char *s, register unsigned int n, int c)
{
	register char   ch;
	register const char  *t;
	register const char  *u;

	ch = c;
	t = s;
	u = 0;
	for (;;)
	{
		if (!n)
			break;
		if (*t == ch)
			u = t;
		++t;
		--n;
		if (!n)
			break;
		if (*t == ch)
			u = t;
		++t;
		--n;
		if (!n)
			break;
		if (*t == ch)
			u = t;
		++t;
		--n;
		if (!n)
			break;
		if (*t == ch)
			u = t;
		++t;
		--n;
	}
	if (!u)
		u = t;
	return u - s;
}

void
getversion_byte_rchr_c()
{
	static char    *x = "$Id: byte_rchr.c,v 1.5 2021-06-10 10:49:43+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
