/*
 * $Log: scan_ushort.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2020-11-22 23:52:25+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.2  2004-10-22 20:30:08+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-01-02 23:51:30+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "scan.h"

unsigned int
scan_ushort(register const char *s, register unsigned short *u)
{
	register unsigned int pos;
	unsigned long   result;
	pos = scan_ulong(s, &result);
	*u = result;
	return pos;
}

void
getversion_scan_ushort_c()
{
	const char     *x = "$Id: scan_ushort.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
