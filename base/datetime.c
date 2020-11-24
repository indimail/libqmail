/*
 * $Log: datetime.c,v $
 * Revision 1.4  2020-11-24 13:33:09+05:30  Cprogrammer
 * fix leap second handling
 *
 * Revision 1.3  2004-10-22 20:24:15+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:18:13+05:30  Cprogrammer
 * added RCS log
 *
 * 19950925 
 */
#include "caltime.h"
#include "datetime.h"
#include "tai.h"

void datetime_tai(struct datetime *dt, datetime_sec dts)
{
	int             yday, wday;
	struct tai      t;
	struct caltime  ct;

	tai_unix(&t, dts);
	caltime_utc(&ct, &t, &wday, &yday);
	dt->hour = ct.hour;
	dt->min = ct.minute;
	dt->sec = ct.second;
	dt->wday = wday;
	dt->yday = yday;
	dt->year = ct.date.year - 1900;
	dt->mon = ct.date.month - 1;
	dt->mday = ct.date.day;
}

void
getversion_datetime_c()
{
	static char    *x = "$Id: datetime.c,v 1.4 2020-11-24 13:33:09+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
