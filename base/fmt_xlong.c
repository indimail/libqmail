/*
 * $Log: fmt_xlong.c,v $
 * Revision 1.3  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.2  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.1  2015-08-24 19:03:07+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"
/*
 * writes ulong u in hex to char *s, does not NULL-terminate 
 */
unsigned int
fmt_xlong(char *s, unsigned long u)
{
	unsigned int    len;
	unsigned long   q;
	unsigned long   c;

	len = 1;
	q = u;
	while (q > 15) {
		++len;
		q /= 16;
	}
	if (s) {
		s += len;
		do
		{
			c = u & 15;
			*--s = (c > 9 ? 'a' - 10 : '0') + c;
			u /= 16;
		} while (u);
	}
	return len;
}

void
getversion_fmt_xlong_c()
{
	const char     *x = "$Id: fmt_xlong.c,v 1.3 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
