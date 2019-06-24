/*
 * $Log: scan_plusminus.c,v $
 * Revision 1.1  2019-06-24 21:42:36+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "scan.h"

#ifndef lint
static char     rcsid[] = "$Id: scan_plusminus.c,v 1.1 2019-06-24 21:42:36+05:30 Cprogrammer Exp mbhangui $";
#endif

unsigned int
scan_plusminus(char *src, signed int *dest)
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
