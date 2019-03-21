#include "fmt.h"

/*
 * write padlen-srclen spaces, if that is >= 0. Then copy
 * characters from src.
 * else copy src
 */
unsigned int
fmt_padleft(char *dest, char *src, unsigned int srclen, unsigned int padlen)
{
	register int    len = 0, todo;
	register char  *p, *q;

	if ((todo = padlen - srclen) > 0) {
		for (p = dest; todo; todo--, len++)
			*p++ = ' ';
		for (q = (char *) src, todo = srclen; todo; todo--, len++)
			*p++ = *q++;
		return (len);
	}
	for (p = dest, q = (char *) src, todo = srclen; todo; todo--, len++)
		*p++ = *q++;
	return (len);
}
