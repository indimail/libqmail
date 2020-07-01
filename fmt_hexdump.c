/*
 * $Log: fmt_hexdump.c,v $
 * Revision 1.1  2020-07-01 12:12:28+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"
#include "textcode.h"
#include "str.h"
/*- #include "haveinline.h" -*/

size_t
fmt_hexdump(char *dest, const char *src, size_t len)
{
	register const unsigned char *s = (const unsigned char *) src;
	size_t          written = 0, i;

	if (!dest)
		return (len > ((size_t) -1) / 2) ? (size_t) -1 : len * 2;
	for (i = 0; i < len; ++i) {
		dest[written] = fmt_tohex(s[i] >> 4);
		dest[written + 1] = fmt_tohex(s[i] & 15);
		written += 2;
	}
	return written;
}

void
getversion_fmt_hexdump_c()
{
	static char    *x = "$Id: fmt_hexdump.c,v 1.1 2020-07-01 12:12:28+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
