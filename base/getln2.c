/*
 * $Log: getln2.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:25:35+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:19:01+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "substdio.h"
#include "stralloc.h"
#include "byte.h"
#include "getln.h"

int
getln2(register substdio *ss, register stralloc *sa, char **cont, unsigned int *clen, int sep)
{
	register char  *x;
	register unsigned int i;
	int             n;

	if (!stralloc_ready(sa, 0))
		return -1;
	sa->len = 0;
	for (;;) {
		n = substdio_feed(ss);
		if (n < 0)
			return -1;
		if (n == 0) {
			*clen = 0;
			return 0;
		}
		x = substdio_PEEK(ss);
		i = byte_chr(x, n, sep);
		if (i < n) {
			substdio_SEEK(ss, *clen = i + 1);
			*cont = x;
			return 0;
		}
		if (!stralloc_readyplus(sa, n))
			return -1;
		i = sa->len;
		sa->len = i + substdio_get(ss, sa->s + i, n);
	}
}

void
getversion_getln2_c()
{
	const char     *x = "$Id: getln2.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
