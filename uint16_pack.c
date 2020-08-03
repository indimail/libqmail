/*
 * $Log: uint16_pack.c,v $
 * Revision 1.1  2003-12-31 19:47:31+05:30  Cprogrammer
 * Initial revision
 *
 */
#define NO_UINT16_MACROS
#include "uint16.h"

void
uint16_pack(char s[2], uint16 u)
{
	s[0] = u & 255;
	s[1] = u >> 8;
}

void
uint16_pack_big(char s[2], uint16 u)
{
	s[1] = u & 255;
	s[0] = u >> 8;
}
