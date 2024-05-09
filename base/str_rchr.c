/*
 * $Log: str_rchr.c,v $
 * Revision 1.8  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.7  2022-01-30 19:36:34+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.6  2021-07-15 09:54:32+05:30  Cprogrammer
 * use const char * for str
 *
 * Revision 1.5  2021-06-10 10:50:36+05:30  Cprogrammer
 * fixed compiler warning
 *
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
	register const char  *t, *u;

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
	const char     *x = "$Id: str_rchr.c,v 1.8 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
