/*
 * $Log: scan_xlong.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2020-11-22 23:52:28+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.2  2005-06-15 22:35:48+05:30  Cprogrammer
 * added RCS version information
 *
 * Revision 1.1  2005-06-15 22:11:59+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "scan.h"

static int
fromhex(unsigned char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	else
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	else
	if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	return -1;
}

unsigned int
scan_xlong(const char *src, unsigned long *dest)
{
	register const char *tmp = src;
	register int    l = 0;
	register unsigned char c;
	while ((c = fromhex(*tmp)) < 16)
	{
		l = (l << 4) + c;
		++tmp;
	}
	*dest = l;
	return tmp - src;
}

void
getversion_scan_xlong_c()
{
	const char     *x = "$Id: scan_xlong.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
