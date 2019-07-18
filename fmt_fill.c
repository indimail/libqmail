/*
 * $Log: fmt_fill.c,v $
 * Revision 1.2  2019-07-18 10:06:24+05:30  Cprogrammer
 * *** empty log message ***
 *
 * Revision 1.1  2019-06-24 21:33:35+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

/*
 * "foo" -> "foo  "
 * append padlen-srclen spaces after dest, if that is >= 0.  Truncate
 * only if total length is larger than maxlen.  Return number of
 * characters written. 
 */
unsigned int
fmt_fill(char *dest, unsigned int srclen, unsigned int padlen, unsigned int maxlen)
{
	unsigned int    todo;
	char           *olddest = dest;
	char           *max = dest + maxlen;

	if ((int) padlen < 0 || (int) maxlen < 0)
		return 0;
	if (srclen > maxlen)
		return maxlen;
	if (dest == 0) {
		unsigned int    sum = srclen > padlen ? srclen : padlen;
		return sum > maxlen ? maxlen : sum;
	}
	dest += srclen;
	for (todo = (long) (padlen - srclen); todo > 0; --todo) {
		if (dest > max)
			break;
		*dest = ' ';
		++dest;
	}
	return (dest - olddest);
}

void
getversion_fmt_fill_c()
{
	static char    *x = "$Id: fmt_fill.c,v 1.2 2019-07-18 10:06:24+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
