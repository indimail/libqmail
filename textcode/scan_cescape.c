/*
 * $Log: scan_cescape.c,v $
 * Revision 1.1  2020-09-30 09:16:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"
#include "textcode.h"
#include "scan.h"

size_t
scan_cescape(const char *src, char *dest, size_t *destlen)
{
	register const unsigned char *s = (const unsigned char *) src;
	size_t          written = 0, i;
	char            c;

	for (i = 0; s[i]; ++i) {
		if ((c = s[i]) == '\\') {
			switch (s[i + 1])
			{
			case 'a':
				c = '\a';
				break;
			case 'b':
				c = '\b';
				break;
			case 'e':
				c = 0x1b;
				break;
			case 'f':
				c = '\f';
				break;
			case 'n':
				c = '\n';
				break;
			case 'r':
				c = '\r';
				break;
			case 't':
				c = '\t';
				break;
			case 'v':
				c = '\v';
			case '\\':
				break;
			case 'x':
				{
					unsigned char   a, b;
					a = scan_fromhex(s[i + 2]);
					b = scan_fromhex(s[i + 3]);
					if (a < 16 && b < 16) {
						c = (a << 4) + b;
						i += 2;
					}
				}
				break;
			default:
				--i;
			}
			++i;
		}
		dest[written] = c;
		++written;
	}
	*destlen = written;
	return i;
}

void
getversion_scan_escape_c()
{
	static char    *x = "$Id: scan_cescape.c,v 1.1 2020-09-30 09:16:27+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
