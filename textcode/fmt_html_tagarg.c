/*
 * $Log: fmt_html_tagarg.c,v $
 * Revision 1.1  2020-09-30 09:16:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"
#include "textcode.h"
#include "str.h"

size_t
fmt_html_tagarg(char *dest, const char *src, size_t len)
{
	register const unsigned char *s = (const unsigned char *) src;
	size_t          written = 0, i;
	const char     *seq;

	for (i = 0; i < len; ++i) {
		switch (s[i])
		{
		case '&':
			seq = "&amp;";
			goto doit;
		case '<':
			seq = "&lt;";
			goto doit;
		case '>':
			seq = "&gt;";
			goto doit;
		case '"':
			seq = "&dquot;";
		  doit:
			written += fmt_str(dest ? dest + written : 0, (char *) seq);
			break;
		default:
			if (dest)
				dest[written] = s[i];
			++written;
			break;
		}
		/*- in case someone gives us malicious input */
		if (written > ((size_t) -1) / 2)
			return (size_t) -1;
	}
	return written;
}

void
getversion_fmt_html_tagarg_c()
{
	const char     *x = "$Id: fmt_html_tagarg.c,v 1.1 2020-09-30 09:16:27+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
