#include "fmt.h"

/*
 * append padlen-srclen spaces after dest, if that is >= 0.  Truncate
 * only if total length is larger than maxlen.  Return number of
 * characters written. 
 */
unsigned int
fmt_padright(char *dest, char *src, unsigned int srclen, unsigned int padlen)
{
	register int    len = 0, todo;
	register char  *p, *q;

	if (srclen < padlen) {
		for (p = dest, q = src, todo = srclen; todo > 0; todo--, len++)
			*p++ = *q++;
		for (todo = padlen - srclen; todo; todo--, len++)
			*p++ = ' ';
		return (len);
	}
	return (srclen);
}
