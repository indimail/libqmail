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
	long            todo;
	char           *olddest = dest;
	char           *max = dest + maxlen;

	if ((int) padlen < 0 || (int) maxlen < 0)
		return 0;
	if (srclen > maxlen)
		return maxlen;
	if (dest == 0) {
		unsigned long   sum = srclen > padlen ? srclen : padlen;
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
