/*
 * $Log: fd_copy.c,v $
 * Revision 1.6  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.5  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.4  2004-10-22 20:25:02+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-07-17 21:18:43+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <fcntl.h>
#include <unistd.h>
#include "fd.h"

int
fd_copy(int to, int from)
{
	if (to == from)
		return 0;
	if (fcntl(from, F_GETFL, 0) == -1)
		return -1;
	close(to);
	if (fcntl(from, F_DUPFD, to) == -1)
		return -1;
	return 0;
}

void
getversion_fd_copy_c()
{
	const char     *x = "$Id: fd_copy.c,v 1.6 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
