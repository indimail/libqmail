/*
 * $Id: scan_short.c,v 1.1 2024-05-27 08:01:13+05:30 Cprogrammer Exp mbhangui $
 */
#include "scan.h"

unsigned int
scan_short(register const char *s, register short *i)
{
	register unsigned int pos;
	register short result;
	register unsigned char c;
	short           sign;

	/*-
	 * determine sign of the number
	 */
	for (pos = result = 0, sign = 1; s[pos] && (s[pos] == ' ' || s[pos] == '\t'); pos++);
	switch (s[pos])
	{
		case '\0':
			return 0;
		case '-':
			++pos;
			sign = -1;
			break;
		case '+':
			++pos;
			sign = 1;
			break;
		default:
			if ((s[pos] - '0') >= 10) {
				*i = 0;
				return pos;
			}
			break;
	}
	for (; s[pos]; pos++) {
		if ((c = (unsigned char)(s[pos] - '0')) >= 10) {
			*i = result * sign;
			return pos;
		}
		result = result * 10 + c;
	}
	*i = result * sign;
	return pos;
}

void
getversion_scan_short_c()
{
	const char     *x = "$Id: scan_short.c,v 1.1 2024-05-27 08:01:13+05:30 Cprogrammer Exp mbhangui $";

	x++;
}

/*
 * $Log: scan_short.c,v $
 * Revision 1.1  2024-05-27 08:01:13+05:30  Cprogrammer
 * Initial revision
 *
 */
