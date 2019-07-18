/*
 * $Log: scan_long.c,v $
 * Revision 1.2  2019-07-18 09:55:39+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:42:34+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "scan.h"

#ifndef lint
static char     rcsid[] = "$Id: scan_long.c,v 1.2 2019-07-18 09:55:39+05:30 Cprogrammer Exp mbhangui $";
#endif

unsigned int
scan_long(s, i)
	register char  *s;
	register long  *i;
{
	int             sign;
	unsigned long   u;
	register unsigned int len;

	len = scan_plusminus(s, &sign);
	s += len;
	len += scan_ulong(s, &u);
	if (sign < 0)
		*i = -u;
	else
		*i = u;
	return len;
}

void
getversion_scan_long_c()
{
	static char    *x = "$Id: scan_long.c,v 1.2 2019-07-18 09:55:39+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
