/*
 * $Log: open_exclr.c,v $
 * Revision 1.2  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
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
	const char     *x = "$Id: open_exclr.c,v 1.2 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
