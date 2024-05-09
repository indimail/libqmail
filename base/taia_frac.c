/*
 * $Log: taia_frac.c,v $
 * Revision 1.3  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.2  2004-10-22 20:31:29+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2003-12-31 19:32:14+05:30  Cprogrammer
 * Initial revision
 *
 *
 * Public domain. 
 */

#include "taia.h"

double
taia_frac(const struct taia *t)
{
	return (t->atto * 0.000000001 + t->nano) * 0.000000001;
}

void
getversion_taia_frac_c()
{
	const char     *x = "$Id: taia_frac.c,v 1.3 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
