/*
 * $Log: caldate_fmt.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.2  2004-10-22 20:23:08+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-06-16 01:19:50+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "caldate.h"

unsigned int
caldate_fmt(char *s, struct caldate *cd)
{
	long            x;
	int             i = 0;

	x = cd->year;
	if (x < 0)
		x = -x;
	do
	{
		++i;
		x /= 10;
	} while (x);
	if (s) {
		x = cd->year;
		if (x < 0) {
			x = -x;
			*s++ = '-';
		}
		s += i;
		do
		{
			*--s = '0' + (x % 10);
			x /= 10;
		} while (x);
		s += i;

		x = cd->month;
		s[0] = '-';
		s[2] = '0' + (x % 10);
		x /= 10;
		s[1] = '0' + (x % 10);

		x = cd->day;
		s[3] = '-';
		s[5] = '0' + (x % 10);
		x /= 10;
		s[4] = '0' + (x % 10);
	}
	return (cd->year < 0) + i + 6;
}

void
getversion_caldate_fmt_c()
{
	const char     *x = "$Id: caldate_fmt.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
