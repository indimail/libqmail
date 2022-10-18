/*
 * $Log: caltime_utc.c,v $
 * Revision 1.3  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.2  2004-10-22 20:23:13+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-05-14 00:44:20+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "tai.h"
#include "leapsecs.h"
#include "caldate.h"
#include "caltime.h"

/*
 * XXX: breaks tai encapsulation 
 */

void
caltime_utc(struct caltime *ct, struct tai *t, int *pwday, int *pyday)
{
	struct tai      t2 = *t;
	uint64          u;
	int             leap;
	long            s;

	/*
	 * XXX: check for overfow? 
	 */

	leap = leapsecs_sub(&t2);
	u = t2.x;

	u += 58486;
	s = u % 86400ULL;

	ct->second = (s % 60) + leap;
	s /= 60;
	ct->minute = s % 60;
	s /= 60;
	ct->hour = s;

	u /= 86400ULL;
	caldate_frommjd(&ct->date, /*XXX*/(long) (u - 53375995543064ULL), pwday, pyday);

	ct->offset = 0;
}

void
getversion_caltime_utc_c()
{
	static char    *x = "$Id: caltime_utc.c,v 1.3 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
