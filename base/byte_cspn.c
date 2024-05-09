/*
 * $Log: byte_cspn.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2020-11-22 23:49:07+05:30  Cprogrammer
 * changed argument to const char *
 *
 * Revision 1.2  2004-10-22 20:22:32+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-08-15 19:52:17+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "byte.h"

unsigned int
byte_cspn(register const char *s, register unsigned int n, register const char *c)
{
	while (*c)
		n = byte_chr(s, n, *c++);
	return n;
}

void
getversion_byte_cspn_c()
{
	const char     *x = "$Id: byte_cspn.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
