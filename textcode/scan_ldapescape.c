/*
 * $Log: scan_ldapescape.c,v $
 * Revision 1.1  2020-09-30 09:17:54+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"
#include "textcode.h"
#include "scan.h"

size_t
scan_ldapescape(const char *src, char *dest, size_t *destlen)
{
	register const unsigned char *s = (const unsigned char *) src;
	size_t          written = 0, i;

	for (i = 0; s[i]; ++i) {
		if (s[i] == '\\') {
			int             j = scan_fromhex(s[i + 1]);
			if (j < 0)
				break;
			dest[written] = j << 4;
			j = scan_fromhex(s[i + 2]);
			if (j < 0)
				break;
			dest[written] |= j;
			i += 2;
		} else {
			dest[written] = s[i];
		}
		++written;
	}
	*destlen = written;
	return i;
}

void
getversion_scan_ldapescape_c()
{
	const char     *x = "$Id: scan_ldapescape.c,v 1.1 2020-09-30 09:17:54+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
