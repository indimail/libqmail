/*
 * $Log: open_readwrite.c,v $
 * Revision 1.4  2020-11-22 23:51:50+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2019-07-18 10:08:38+05:30  Cprogrammer
 * fixed compiler warning
 *
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

int
open_readwrite(const char *fn)
{
	return open(fn, O_RDWR | O_NDELAY);
}

void
getversion_open_readwrite_c()
{
	static char    *x = "$Id: open_readwrite.c,v 1.4 2020-11-22 23:51:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
