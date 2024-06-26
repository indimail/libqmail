/*
 * $Log: leapsecs_sub.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.2  2004-10-22 20:26:05+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-05-14 00:44:53+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "leapsecs.h"
#include "tai.h"

/*
 * XXX: breaks tai encapsulation 
 */

extern struct tai *leapsecs;
extern int      leapsecs_num;

int
leapsecs_sub(struct tai *t)
{
	int             i;
	uint64          u;
	int             s;

	if (leapsecs_init() == -1)
		return 0;

	u = t->x;
	s = 0;

	for (i = 0; i < leapsecs_num; ++i) {
		if (u < leapsecs[i].x)
			break;
		++s;
		if (u == leapsecs[i].x) {
			t->x = u - s;
			return 1;
		}
	}

	t->x = u - s;
	return 0;
}

void
getversion_leapsecs_sub_c()
{
	const char     *x = "$Id: leapsecs_sub.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
