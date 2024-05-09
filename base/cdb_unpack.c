/*
 * $Log: cdb_unpack.c,v $
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:23:49+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:17:33+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "cdb.h"

uint32
cdb_unpack(unsigned char *buf)
{
	uint32          num;
	num = buf[3];
	num <<= 8;
	num += buf[2];
	num <<= 8;
	num += buf[1];
	num <<= 8;
	num += buf[0];
	return num;
}

void
getversion_cdb_unpack_c()
{
	const char     *x = "$Id: cdb_unpack.c,v 1.4 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
