/*
 * $Log: leapsecs_init.c,v $
 * Revision 1.3  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.2  2004-10-22 20:26:03+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-05-14 00:44:49+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "leapsecs.h"

static int      flaginit = 0;

int
leapsecs_init()
{
	if (flaginit)
		return 0;
	if (leapsecs_read() == -1)
		return -1;
	flaginit = 1;
	return 0;
}

void
getversion_leapsecs_init_c()
{
	const char     *x = "$Id: leapsecs_init.c,v 1.3 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
