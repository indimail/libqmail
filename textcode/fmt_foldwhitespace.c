/*
 * $Log: fmt_foldwhitespace.c,v $
 * Revision 1.1  2020-09-30 09:16:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"
#include "textcode.h"
#include "str.h"

size_t
fmt_foldwhitespace(char *dest, const char *src, size_t len)
{
	register const unsigned char *s = (const unsigned char *) src;
	size_t          i;
	char            c;

	for (i = 0; i < len; ++i) {
		switch (c = s[i])
		{
		case ' ':
		case '\t':
		case '\n':
			c = '_';
			break;
		}
		if (dest)
			dest[i] = c;
	}
	return len;
}

void
getversion_fmt_foldwhitespace_c()
{
	static char    *x = "$Id: fmt_foldwhitespace.c,v 1.1 2020-09-30 09:16:27+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
