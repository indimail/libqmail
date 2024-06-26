/*
 * $Log: byte_diff.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2020-11-22 23:49:11+05:30  Cprogrammer
 * changed argument to const char *
 *
 * Revision 1.3  2004-10-22 20:22:34+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:16:41+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "byte.h"

int
byte_diff(register const char *s, register unsigned int n, register const char *t)
{
	for (;;) {
		if (!n)
			return 0;
		if (*s != *t)
			break;
		++s;
		++t;
		--n;
		if (!n)
			return 0;
		if (*s != *t)
			break;
		++s;
		++t;
		--n;
		if (!n)
			return 0;
		if (*s != *t)
			break;
		++s;
		++t;
		--n;
		if (!n)
			return 0;
		if (*s != *t)
			break;
		++s;
		++t;
		--n;
	}
	return ((int) (unsigned int) (unsigned char) *s) - ((int) (unsigned int) (unsigned char) *t);
}

void
getversion_byte_diff_c()
{
	const char     *x = "$Id: byte_diff.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
