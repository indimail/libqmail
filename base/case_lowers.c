/*
 * $Log: case_lowers.c,v $
 * Revision 1.5  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.4  2004-10-22 20:23:17+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-07-17 21:17:10+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "case.h"

void
case_lowers(char *s)
{
	unsigned char   x;

	while ((x = *s)) {
		x -= 'A';
		if (x <= 'Z' - 'A')
			*s = x + 'a';
		++s;
	}
}

void
getversion_case_lowers_c()
{
	static char    *x = "$Id: case_lowers.c,v 1.5 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
