/*
 * $Log: fmt_8long.c,v $
 * Revision 1.1  2019-06-24 21:32:58+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

#ifndef lint
static char     rcsid[] = "$Id: fmt_8long.c,v 1.1 2019-06-24 21:32:58+05:30 Cprogrammer Exp mbhangui $";
#endif

unsigned int
fmt_8long(char *dest, unsigned long i)
{
	register unsigned int len, tmp;
	/*- first count the number of bytes needed */
	for (len = 1, tmp = i; tmp > 7; ++len)
		tmp >>= 3;
	if (dest)
		for (tmp = i, dest += len;;) {
			*--dest = (char) ((tmp & 7) + '0');
			if (!(tmp >>= 3))
				break;
		}
	return len;
}
