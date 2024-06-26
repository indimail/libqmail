/*
 * $Log: caldate_fmjd.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.2  2004-10-22 20:23:07+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-05-14 00:44:18+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "caldate.h"

void
caldate_frommjd(struct caldate *cd, long day, int *pwday, int *pyday)
{
	long            year;
	long            month;
	int             yday;

	year = day / 146097L;
	day %= 146097L;
	day += 678881L;
	while (day >= 146097L) {
		day -= 146097L;
		++year;
	}

	/*- year * 146097 + day - 678881 is MJD; 0 <= day < 146097 */
	/*- 2000-03-01, MJD 51604, is year 5, day 0 */

	if (pwday)
		*pwday = (day + 3) % 7;

	year *= 4;
	if (day == 146096L) {
		year += 3;
		day = 36524L;
	} else {
		year += day / 36524L;
		day %= 36524L;
	}
	year *= 25;
	year += day / 1461;
	day %= 1461;
	year *= 4;

	yday = (day < 306);
	if (day == 1460) {
		year += 3;
		day = 365;
	} else {
		year += day / 365;
		day %= 365;
	}
	yday += day;

	day *= 10;
	month = (day + 5) / 306;
	day = (day + 5) % 306;
	day /= 10;
	if (month >= 10) {
		yday -= 306;
		++year;
		month -= 10;
	} else {
		yday += 59;
		month += 2;
	}

	cd->year = year;
	cd->month = month + 1;
	cd->day = day + 1;

	if (pyday)
		*pyday = yday;
}

void
getversion_caldate_fmjd_c()
{
	const char     *x = "$Id: caldate_fmjd.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
