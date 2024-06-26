/*
 * $Log: case_lowerb.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:23:17+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:17:08+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "case.h"

void
case_lowerb(char *s, unsigned int len)
{
	unsigned char   x;

	while (len > 0) {
		--len;
		x = *s - 'A';
		if (x <= 'Z' - 'A')
			*s = x + 'a';
		++s;
	}
}

void
getversion_case_lowerb_c()
{
	const char     *x = "$Id: case_lowerb.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
