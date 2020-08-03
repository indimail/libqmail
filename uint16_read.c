/*
 * $Log: uint16_read.c,v $
 * Revision 1.1  2020-08-03 18:04:15+05:30  Cprogrammer
 * Initial revision
 *
 */
#define NO_UINT16_MACROS
#include "uint16.h"

uint16
uint16_read(const char *in)
{
	return (unsigned short)((((unsigned char) in[1]) << 8) | (unsigned char)in[0]);
}

uint16
uint16_read_big(const char *in)
{
	return (unsigned short)((((unsigned char) in[0]) << 8) + (unsigned char)in[1]);
}

void
getversion_read_c()
{
	static char    *x = "$Id: uint16_read.c,v 1.1 2020-08-03 18:04:15+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
