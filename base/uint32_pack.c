/*
 * $Log: uint32_pack.c,v $
 * Revision 1.3  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.2  2020-08-03 18:20:22+05:30  Cprogrammer
 * added getversion()
 *
 * Revision 1.1  2008-09-15 22:11:15+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "uint32.h"

void
uint32_pack(char s[4], uint32 u)
{
	s[0] = u & 255;
	u >>= 8;
	s[1] = u & 255;
	u >>= 8;
	s[2] = u & 255;
	s[3] = u >> 8;
}

void
uint32_pack_big(char s[4], uint32 u)
{
	s[3] = u & 255;
	u >>= 8;
	s[2] = u & 255;
	u >>= 8;
	s[1] = u & 255;
	s[0] = u >> 8;
}

void
getversion_uint32_pack_c()
{
	const char     *x = "$Id: uint32_pack.c,v 1.3 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
