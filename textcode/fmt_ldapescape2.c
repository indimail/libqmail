/*
 * $Log: fmt_ldapescape2.c,v $
 * Revision 1.1  2020-09-30 09:16:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"
#include "textcode.h"
#include <string.h>

size_t
fmt_ldapescape2(char *dest, const char *src, size_t len, const char *escapeme)
{
	register const unsigned char *s = (const unsigned char *) src;
	size_t          written = 0, i;

	for (i = 0; i < len; ++i) {
		if (s[i] == '\\' || s[i] < ' ' || strchr(escapeme, s[i])) {
			if (dest) {
				dest[written] = '\\';
				dest[written + 1] = tohex(s[i] >> 4);
				dest[written + 2] = tohex(s[i] & 15);
			}
			written += 3;
		} else {
			if (dest)
				dest[written] = s[i];
			++written;
		}
		/*- in case someone gives us malicious input */
		if (written > ((size_t) -1) / 2)
			return (size_t) -1;
	}
	return written;
}

void
getversion_fmt_ldap_escape2_c()
{
	static char    *x = "$Id: fmt_ldapescape2.c,v 1.1 2020-09-30 09:16:27+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
