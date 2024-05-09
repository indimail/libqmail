/*
 * $Log: taia_uint.c,v $
 * Revision 1.3  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.2  2004-10-22 20:31:33+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2003-12-31 19:32:21+05:30  Cprogrammer
 * Initial revision
 *
 *
 * Public domain. 
 */

#include "taia.h"

/*
 * XXX: breaks tai encapsulation 
 */

void
taia_uint(struct taia *t, unsigned int s)
{
	t->sec.x = s;
	t->nano = 0;
	t->atto = 0;
}

void
getversion_taia_uint_c()
{
	const char     *x = "$Id: taia_uint.c,v 1.3 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
