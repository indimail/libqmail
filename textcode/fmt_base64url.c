/*
 * $Log: fmt_base64url.c,v $
 * Revision 1.1  2020-09-30 09:16:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"
#include "textcode.h"

size_t
fmt_base64url(char *dest, const char *src, size_t len)
{
	register const unsigned char *s = (const unsigned char *) src;
	unsigned short  bits = 0, temp = 0;
	size_t          written = 0, i;

	if (!dest)
		return (len > ((size_t) -1) / 2) ? (size_t) -1 : ((len + 2) / 3) * 4;
	for (i = 0; i < len; ++i) {
		temp <<= 8;
		temp += s[i];
		bits += 8;
		while (bits > 6) {
			dest[written] = base64url[((temp >> (bits - 6)) & 63)];
			++written;
			bits -= 6;
		}
	}
	if (bits) {
		temp <<= (6 - bits);
		dest[written] = base64url[temp & 63];
		++written;
	}
	/*- no padding for base64url */
	return written;
}

void
getversion_fmt_base64url_c()
{
	const char     *x = "$Id: fmt_base64url.c,v 1.1 2020-09-30 09:16:27+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
