/*
 * $Log: case_startb.c,v $
 * Revision 1.4  2020-11-22 23:50:31+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2004-10-22 20:23:18+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:17:13+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "case.h"

int
case_startb(register const char *s, unsigned int len, register const char *t)
{
	register unsigned char x;
	register unsigned char y;

	for (;;) {
		y = *t++ - 'A';
		if (y <= 'Z' - 'A')
			y += 'a';
		else
			y += 'A';
		if (!y)
			return 1;
		if (!len)
			return 0;
		--len;
		x = *s++ - 'A';
		if (x <= 'Z' - 'A')
			x += 'a';
		else
			x += 'A';
		if (x != y)
			return 0;
	}
}

void
getversion_case_startb_c()
{
	static char    *x = "$Id: case_startb.c,v 1.4 2020-11-22 23:50:31+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
