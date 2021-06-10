/*
 * $Log: byte_chr.c,v $
 * Revision 1.5  2021-06-10 10:49:33+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.4  2020-11-22 23:48:14+05:30  Cprogrammer
 * changed argument to const char *
 *
 * Revision 1.3  2004-10-22 20:22:24+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:16:33+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "byte.h"

unsigned int
byte_chr(const char *s, register unsigned int n, int c)
{
	register char   ch;
	register const char  *t;

	ch = c;
	t = s;
	for (;;) {
		if (!n)
			break;
		if (*t == ch)
			break;
		++t;
		--n;
		if (!n)
			break;
		if (*t == ch)
			break;
		++t;
		--n;
		if (!n)
			break;
		if (*t == ch)
			break;
		++t;
		--n;
		if (!n)
			break;
		if (*t == ch)
			break;
		++t;
		--n;
	}
	return t - s;
}

void
getversion_byte_chr_c()
{
	static char    *x = "$Id: byte_chr.c,v 1.5 2021-06-10 10:49:33+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
