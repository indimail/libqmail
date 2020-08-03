/*
 * $Log: uint16_unpack.c,v $
 * Revision 1.1  2003-12-31 19:47:31+05:30  Cprogrammer
 * Initial revision
 *
 */
#define NO_UINT16_MACROS
#include "uint16.h"

void
uint16_unpack(const char *in, uint16 *out)
{
	*out = (unsigned short)((((unsigned char) in[1]) << 8) + (unsigned char)in[0]);
}

void
uint16_unpack_big(const char *in,uint16 *out)
{
	*out = (unsigned short)((((unsigned char) in[0]) << 8) + (unsigned char)in[1]);
}
