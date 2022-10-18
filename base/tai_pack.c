/*
 * $Log: tai_pack.c,v $
 * Revision 1.3  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.2  2004-10-22 20:31:34+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-06-16 01:20:00+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "tai.h"

void
tai_pack(char *s, struct tai *t)
{
	uint64          x;

	x = t->x;
	s[7] = x & 255;
	x >>= 8;
	s[6] = x & 255;
	x >>= 8;
	s[5] = x & 255;
	x >>= 8;
	s[4] = x & 255;
	x >>= 8;
	s[3] = x & 255;
	x >>= 8;
	s[2] = x & 255;
	x >>= 8;
	s[1] = x & 255;
	x >>= 8;
	s[0] = x;
}

void
getversion_tai_pack_c()
{
	static char    *x = "$Id: tai_pack.c,v 1.3 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
