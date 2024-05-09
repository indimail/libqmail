/*
 * $Log: tai_now.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.2  2004-10-22 20:31:33+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-05-14 00:45:17+05:30  Cprogrammer
 * Initial revision
 *
 */
#include <time.h>
#include "tai.h"

void
tai_now(struct tai *t)
{
	t->x = 4611686018427387914ULL + (uint64) time((long *) 0);
}

void
getversion_tai_now_c()
{
	const char     *x = "$Id: tai_now.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
