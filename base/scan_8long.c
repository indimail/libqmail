/*
 * $Log: scan_8long.c,v $
 * Revision 1.2  2020-11-22 23:51:58+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.1  2020-09-30 09:11:42+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "scan.h"

unsigned int
scan_8long(register const char *s, register unsigned long *u)
{
	register unsigned int pos;
	register unsigned long result;
	register unsigned long c;

	pos = 0;
	result = 0;

	while ((c = (unsigned long) (unsigned char) (s[pos] - '0')) < 8) {
		result = result * 8 + c;
		++pos;
	}
	*u = result;
	return pos;
}

void
getversion_scan_8long_c()
{
	const char     *x = "$Id: scan_8long.c,v 1.2 2020-11-22 23:51:58+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
