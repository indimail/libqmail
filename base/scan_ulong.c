/*
 * $Id: scan_ulong.c,v 1.9 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $
 */
#include "scan.h"

unsigned int
scan_ulong(register const char *s, register unsigned long *u)
{
	register unsigned int pos;
	register unsigned long result;
	register unsigned long c;

	pos = 0;
	result = 0;
	for (; s[pos]; pos++) {
		if ((c = (unsigned long) (unsigned char) (s[pos] - '0')) >= 10) {
			*u = result;
			return pos;
		}
		result = result * 10 + c;
	}
	*u = result;
	return pos;
}

void
getversion_scan_ulong_c()
{
	const char     *x = "$Id: scan_ulong.c,v 1.9 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}

/*
 * $Log: scan_ulong.c,v $
 * Revision 1.9  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.8  2023-11-30 15:18:26+05:30  Cprogrammer
 * incorrect conversion when string has non-numeric characters
 *
 * Revision 1.7  2020-11-22 23:52:18+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.6  2019-06-24 21:27:20+05:30  Cprogrammer
 * removed scan_int() to scan_int.c
 *
 * Revision 1.5  2004-10-24 21:39:31+05:30  Cprogrammer
 * *** empty log message ***
 *
 * Revision 1.4  2004-10-22 20:30:07+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-07-17 21:22:41+05:30  Cprogrammer
 * added RCS log
 *
 */
