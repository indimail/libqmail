/*
 * $Log: open_read.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2020-11-22 23:51:48+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2004-10-22 20:27:50+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:20:03+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <sys/types.h>
#include <fcntl.h>
#include "open.h"

int
open_read(const char *fn)
{
	return open(fn, O_RDONLY | O_NDELAY);
}

void
getversion_open_read_c()
{
	const char     *x = "$Id: open_read.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
