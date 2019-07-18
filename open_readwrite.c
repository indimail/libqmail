/*
 * $Log: open_readwrite.c,v $
 * Revision 1.2  2019-07-18 09:55:23+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:41:58+05:30  Cprogrammer
 * Initial revision
 *
 */
#include <sys/types.h>
#include <fcntl.h>
#include "open.h"

#ifndef lint
static char     rcsid[] = "$Id: open_readwrite.c,v 1.2 2019-07-18 09:55:23+05:30 Cprogrammer Exp mbhangui $";
#endif

int
open_readwrite(fn)
	char           *fn;
{
	return open(fn, O_RDWR | O_NDELAY);
}

void
getversion_open_readwrite_c()
{
	static char    *x = "$Id: open_readwrite.c,v 1.2 2019-07-18 09:55:23+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
