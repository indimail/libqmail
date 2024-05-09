/*
 * $Log: seek_trunc.c,v $
 * Revision 1.5  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.4  2004-10-22 20:30:11+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-07-17 21:22:51+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <sys/types.h>
#include <unistd.h>
#include "seek.h"

int
seek_trunc(int fd, seek_pos pos)
{
	return ftruncate(fd, (off_t) pos);
}

void
getversion_seek_trunc_c()
{
	const char     *x = "$Id: seek_trunc.c,v 1.5 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
