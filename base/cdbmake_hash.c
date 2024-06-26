/*
 * $Log: cdbmake_hash.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:23:22+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:17:21+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "cdbmake.h"

uint32
cdbmake_hashadd(uint32 h, unsigned int c)
{
	h += (h << 5);
	h ^= (uint32) (unsigned char) c;
	return h;
}

void
getversion_cdbmake_hash_c()
{
	const char     *x = "$Id: cdbmake_hash.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
