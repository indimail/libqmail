/*
 * $Log: caltime_tai.c,v $
 * Revision 1.3  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.2  2004-10-22 20:23:12+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-06-16 01:19:53+05:30  Cprogrammer
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
caltime_tai(struct caltime *ct, struct tai *t)
{
	long            day;
	long            s;

	/*
	 * XXX: check for overflow? 
	 */

	day = caldate_mjd(&ct->date);

	s = ct->hour * 60 + ct->minute;
	s = (s - ct->offset) * 60 + ct->second;

	t->x = day * 86400ULL + 4611686014920671114ULL + (long long) s;

	leapsecs_add(t, ct->second == 60);
}

void
getversion_caltime_tai_c()
{
	const char     *x = "$Id: caltime_tai.c,v 1.3 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
