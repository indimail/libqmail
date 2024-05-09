/*
 * $Log: taia_tai.c,v $
 * Revision 1.3  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.2  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.1  2016-01-28 23:43:18+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "taia.h"

void
taia_tai(const struct taia *ta, struct tai *t)
{
	*t = ta->sec;
}

void
getversion_taia_tai_c()
{
	const char     *x = "$Id: taia_tai.c,v 1.3 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
