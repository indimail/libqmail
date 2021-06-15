/*
 * $Log: open_exclr.c,v $
 * Revision 1.1  2021-06-15 21:21:17+05:30  Cprogrammer
 * Initial revision
 *
 */
#include <sys/types.h>
#include <fcntl.h>
#include "open.h"

int
open_exclr(const char *fn)
{
	return open(fn, O_RDWR | O_EXCL | O_CREAT, 0644);
}

void
getversion_open_exclr_c()
{
	static char    *x = "$Id: open_exclr.c,v 1.1 2021-06-15 21:21:17+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
