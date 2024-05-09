/*
 * $Log: cdbmake_pack.c,v $
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:23:23+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:17:25+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "cdbmake.h"

void
cdbmake_pack(unsigned char *buf, uint32 num)
{
	*buf++ = num;
	num >>= 8;
	*buf++ = num;
	num >>= 8;
	*buf++ = num;
	num >>= 8;
	*buf = num;
}

void
getversion_cdbmake_pack_c()
{
	const char     *x = "$Id: cdbmake_pack.c,v 1.4 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
