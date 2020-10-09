/*
 * $Log: fmt_jsonescape.c,v $
 * Revision 1.1  2020-09-30 09:16:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"
#include "textcode.h"
#include "str.h"

/*
 * src is UTF-8 encoded 
 */
size_t
fmt_jsonescape(char *dest, const char *src, size_t len)
{
	register const unsigned char *s = (const unsigned char *) src;
	size_t          written = 0, i;

	for (i = 0; i < len; ++i) {
		switch (s[i])
		{
		case '\\':
		case '"':
			if (dest) {
				dest[written] = '\\';
				dest[written + 1] = s[i];
			}
			written += 2;
			break;
		default:
			if (s[i] < ' ') {
				if (dest) {
					dest[written] = '\\';
					dest[written + 1] = 'u';
					dest[written + 2] = '0';
					dest[written + 3] = '0';
					dest[written + 4] = tohex(s[i] >> 4);
					dest[written + 5] = tohex(s[i] & 0xf);
				}
				written += 6;
			} else {
				if (dest)
					dest[written] = s[i];
				++written;
			}
			break;
		}
	/*
	 * in case someone gives us malicious input 
	 */
		if (written > ((size_t) -1) / 2)
			return (size_t) -1;
	}
	return written;
}

void
getversion_fmt_json_escape_c()
{
	static char    *x = "$Id: fmt_jsonescape.c,v 1.1 2020-09-30 09:16:27+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
