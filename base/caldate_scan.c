/*
 * $Log: caldate_scan.c,v $
 * Revision 1.2  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.1  2016-01-28 01:41:30+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "caldate.h"

unsigned int
caldate_scan(char *s, struct caldate *cd)
{
	int             sign = 1;
	char           *t = s;
	unsigned long   z;
	unsigned long   c;

	if (*t == '-') {
		++t;
		sign = -1;
	}
	z = 0;
	while ((c = (unsigned char) (*t - '0')) <= 9) {
		z = z * 10 + c;
		++t;
	}
	cd->year = z * sign;

	if (*t++ != '-')
		return 0;
	z = 0;
	while ((c = (unsigned char) (*t - '0')) <= 9) {
		z = z * 10 + c;
		++t;
	}
	cd->month = z;

	if (*t++ != '-')
		return 0;
	z = 0;
	while ((c = (unsigned char) (*t - '0')) <= 9) {
		z = z * 10 + c;
		++t;
	}
	cd->day = z;

	return t - s;
}

void
getversion_caldate_scan_c()
{
	static char    *x = "$Id: caldate_scan.c,v 1.2 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
