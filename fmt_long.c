/*
 * $Log: fmt_long.c,v $
 * Revision 1.1  2019-06-24 21:40:57+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

#ifndef lint
static char     rcsid[] = "$Id: fmt_long.c,v 1.1 2019-06-24 21:40:57+05:30 Cprogrammer Exp mbhangui $";
#endif

unsigned int fmt_long(char *dest, long int i)
{
	if (i < 0) {
		if (dest)
			*dest++='-';
		return (fmt_ulong(dest, (unsigned long) -i) + 1);
	} else
	return (fmt_ulong(dest, (unsigned long) i));
}
