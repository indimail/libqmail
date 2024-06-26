/*
 * $Log: fmt_uint0.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:25:20+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:18:55+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "fmt.h"

unsigned int
fmt_uint0(char *s, unsigned int u, unsigned int n)
{
	unsigned int    len;

	len = fmt_uint(FMT_LEN, u);
	while (len < n) {
		if (s)
			*s++ = '0';
		++len;
	}
	if (s)
		fmt_uint(s, u);
	return len;
}

void
getversion_fmt_uint0_c()
{
	const char     *x = "$Id: fmt_uint0.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
