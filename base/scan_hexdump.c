/*
 * $Log: scan_hexdump.c,v $
 * Revision 1.1  2020-07-01 12:12:36+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"
#include "textcode.h"
#include "scan.h"

size_t
scan_hexdump(const char *src, char *dest, size_t *destlen)
{
	register const unsigned char *s = (const unsigned char *) src;
	size_t          written = 0, i;
	for (i = 0; s[i]; ++i) {
		int             j = scan_fromhex(s[i]);
		if (j < 0)
			break;
		dest[written] = j << 4;
		j = scan_fromhex(s[i + 1]);
		if (j < 0)
			break;
		dest[written] |= j;
		++i;
		++written;
	}
	*destlen = written;
	return i;
}

void
getversion_scan_hexdump_c()
{
	const char     *x = "$Id: scan_hexdump.c,v 1.1 2020-07-01 12:12:36+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
