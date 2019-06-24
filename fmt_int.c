/*
 * $Log: fmt_int.c,v $
 * Revision 1.1  2019-06-24 21:34:09+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

#ifndef lint
static char     rcsid[] = "$Id: fmt_int.c,v 1.1 2019-06-24 21:34:09+05:30 Cprogrammer Exp mbhangui $";
#endif

unsigned int fmt_int(char *dest, int i)
{
	if (i < 0) {
		if (dest)
			*dest++='-';
		return (fmt_uint(dest, (unsigned int) -i) + 1);
	} else
	return (fmt_uint(dest, (unsigned int) i));
}
