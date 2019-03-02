/*
 * $Log: open_readwrite.c,v $
 * Revision 1.1  2019-03-01 11:27:23+05:30  Cprogrammer
 * Initial revision
 *
 */
#include <sys/types.h>
#include <fcntl.h>
#include "open.h"

int
open_readwrite(fn)
	char           *fn;
{
	return open(fn, O_RDWR | O_NDELAY);
}

void
getversion_open_readwrite_c()
{
	static char    *x = "$Id: open_readwrite.c,v 1.1 2019-03-01 11:27:23+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
