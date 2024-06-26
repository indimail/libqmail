/*
 * $Log: fmt_ulong.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:25:23+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:18:58+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "fmt.h"

unsigned int
fmt_ulong(register char *s, register unsigned long u)
{
	register unsigned int len;
	register unsigned long q;

	len = 1;
	q = u;
	while (q > 9) {
		++len;
		q /= 10;
	}
	if (s) {
		s += len;
		do
		{
			*--s = '0' + (u % 10);
			u /= 10;
		} while (u); /*- handles u == 0 */
	}
	return len;
}

void
getversion_fmt_ulong_c()
{
	const char     *x = "$Id: fmt_ulong.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
