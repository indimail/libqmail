/*
 * $Log: fmt_8long.c,v $
 * Revision 1.3  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.2  2019-07-18 10:07:55+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:32:58+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

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

void
getversion_fmt_8long_c()
{
	const char     *x = "$Id: fmt_8long.c,v 1.3 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
