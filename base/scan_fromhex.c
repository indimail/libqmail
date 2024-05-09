/*
 * $Log: scan_fromhex.c,v $
 * Revision 1.2  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.1  2020-07-01 16:57:48+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "scan.h"

int
scan_fromhex(unsigned char c)
{
	c = (unsigned char) (c - '0');
	if (c <= 9)
		return c;
	c = (unsigned char) (c & ~0x20);
	c = (unsigned char) (c - ('A' - '0'));
	if (c < 6)
		return c + 10;
	return -1;
}

void
getversion_scan_fromhex_c()
{
	const char     *x = "$Id: scan_fromhex.c,v 1.2 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
