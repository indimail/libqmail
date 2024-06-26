/*
 * $Log: str_len.c,v $
 * Revision 1.6  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.5  2022-01-30 19:36:27+05:30  Cprogrammer
 * fixed compiler warning
 *
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
	register const char *t;

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
	const char     *x = "$Id: str_len.c,v 1.6 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
