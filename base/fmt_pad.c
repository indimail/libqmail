/*
 * $Log: fmt_pad.c,v $
 * Revision 1.2  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.1  2019-07-18 10:13:20+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

/*
 * write padlen-srclen spaces, if that is >= 0.  Then copy srclen
 * characters from src.
 * Return number of characters written. 
 */
unsigned int
fmt_pad(char *dest, const char *src, unsigned int srclen, unsigned int padlen, unsigned int maxlen)
{
	unsigned int    todo;
	char           *olddest = dest;
	char           *max = dest + maxlen;

	if ((int) srclen < 0 || (int) padlen < 0 || (int) maxlen < 0)
		return 0;
	todo = (padlen - srclen);
	if (dest == 0) {
		unsigned int   sum = srclen > padlen ? srclen : padlen;
		return sum > maxlen ? maxlen : sum;
	}
	for (; todo > 0; --todo) {
		if (dest > max)
			break;
		*dest = ' ';
		++dest;
	}
	for (todo = (long) (srclen > maxlen ? maxlen : srclen); todo > 0; --todo) {
		if (dest > max)
			break;
		*dest = *src;
		++dest;
		++src;
	}
	return (dest - olddest);
}

void
getversion_fmt_pad_c()
{
	const char     *x = "$Id: fmt_pad.c,v 1.2 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
