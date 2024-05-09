/*
 * $Id: scan_int.c,v 1.6 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $
 */
#include "scan.h"

unsigned int
scan_int(register const char *s, register int *i)
{
	register unsigned int pos;
	register int result;
	register unsigned char c;
	int             sign;

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
getversion_scan_int_c()
{
	const char     *x = "$Id: scan_int.c,v 1.6 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}

/*
 * $Log: scan_int.c,v $
 * Revision 1.6  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.5  2023-11-30 15:15:33+05:30  Cprogrammer
 * incorrect conversion when string has non-numeric characters
 *
 * Revision 1.5  2023-09-17 07:53:51+05:30  Cprogrammer
 * BUG, incorrect conversion when string starts with non-numeric character.
 *
 * Revision 1.4  2020-11-22 23:52:05+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2019-07-18 10:08:58+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.2  2019-07-18 09:55:36+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:42:31+05:30  Cprogrammer
 * Initial revision
 *
 */
