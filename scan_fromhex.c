/*
 * $Log: $
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
	static char    *x = "$Id: $";

	x++;
}
