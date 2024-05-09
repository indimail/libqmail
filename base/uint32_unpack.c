/*
 * $Log: uint32_unpack.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2020-11-23 00:18:58+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.2  2020-08-03 18:20:29+05:30  Cprogrammer
 * added getversion()
 *
 * Revision 1.1  2008-09-15 22:11:24+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "uint32.h"

void
uint32_unpack(const char s[4], uint32 *u)
{
	uint32          result;

	result = (unsigned char) s[3];
	result <<= 8;
	result += (unsigned char) s[2];
	result <<= 8;
	result += (unsigned char) s[1];
	result <<= 8;
	result += (unsigned char) s[0];

	*u = result;
}

void
uint32_unpack_big(const char s[4], uint32 *u)
{
	uint32          result;

	result = (unsigned char) s[0];
	result <<= 8;
	result += (unsigned char) s[1];
	result <<= 8;
	result += (unsigned char) s[2];
	result <<= 8;
	result += (unsigned char) s[3];

	*u = result;
}

void
getversion_uint32_unpack_c()
{
	const char     *x = "$Id: uint32_unpack.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
