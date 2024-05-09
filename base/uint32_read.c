/*
 * $Log: uint32_read.c,v $
 * Revision 1.1  2020-08-03 18:05:28+05:30  Cprogrammer
 * Initial revision
 *
 */
#define NO_UINT32_MACROS
#include "uint32.h"

uint32
uint32_read(const char *in)
{
	return (((uint32)(unsigned char)in[3])<<24) |
	  (((uint32)(unsigned char)in[2])<<16) |
	  (((uint32)(unsigned char)in[1])<<8) |
	  (uint32)(unsigned char)in[0];
}


uint32
uint32_read_big(const char *in)
{
	return (((uint32)(unsigned char)in[0])<<24) |
		(((uint32)(unsigned char)in[1])<<16) |
		(((uint32)(unsigned char)in[2])<<8) |
		(uint32)(unsigned char)in[3];
}

void
getversion_uint32_read_c()
{
	const char     *x = "$Id: uint32_read.c,v 1.1 2020-08-03 18:05:28+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
