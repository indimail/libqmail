/*
 * $Log: taia_approx.c,v $
 * Revision 1.3  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.2  2004-10-22 20:31:28+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2003-12-31 19:32:12+05:30  Cprogrammer
 * Initial revision
 *
 *
 * Public domain. 
 */

#include "taia.h"

double
taia_approx(const struct taia *t)
{
	return tai_approx(&t->sec) + taia_frac(t);
}

void
getversion_taia_approx_c()
{
	const char     *x = "$Id: taia_approx.c,v 1.3 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
