/*
 * $Log: substdio_copy.c,v $
 * Revision 1.4  2020-12-04 12:27:46+05:30  Cprogrammer
 * use ansi c function declaration
 *
 * Revision 1.3  2004-10-22 20:31:10+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:38+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <sys/types.h>
#include "substdio.h"

int
substdio_copy(register substdio *ssout, register substdio *ssin)
{
	register char  *x;

	for (;;) {
		ssize_t         n;
		if ((n = substdio_feed(ssin)) == -1)
			return -2;
		else
		if (!n)
			return 0;
		x = substdio_PEEK(ssin);
		if (substdio_put(ssout, x, n) == -1)
			return -3;
		substdio_SEEK(ssin, n);
	}
}

void
getversion_substdio_copy_c()
{
	const char     *x = "$Id: substdio_copy.c,v 1.4 2020-12-04 12:27:46+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
