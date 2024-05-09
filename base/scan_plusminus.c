/*
 * $Log: scan_plusminus.c,v $
 * Revision 1.4  2020-11-22 23:52:10+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2019-07-18 10:09:08+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.2  2019-07-18 09:55:43+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:42:36+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "scan.h"

unsigned int
scan_plusminus(const char *src, signed int *dest)
{
	*dest = 1;
	switch (*src)
	{
	case '-':
		*dest = -1;
	case '+':
		return 1;
	}
	return 0;
}

void
getversion_scan_plusminus_c()
{
	const char     *x = "$Id: scan_plusminus.c,v 1.4 2020-11-22 23:52:10+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
