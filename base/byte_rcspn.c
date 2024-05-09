/*
 * $Log: byte_rcspn.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2020-11-22 23:50:05+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.2  2004-10-22 20:23:01+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-08-15 19:52:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "byte.h"

unsigned int
byte_rcspn(register const char *s, register unsigned int n, register const char *c)
{
	unsigned int    ret, pos, i;

	for (ret = n, pos = 0; *c; ++c) {
		if ((i = byte_rchr(s + pos, n - pos, *c) + pos) < n)
			ret = pos = i;
	}
	return ret;
}

void
getversion_byte_rcspn_c()
{
	const char     *x = "$Id: byte_rcspn.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
