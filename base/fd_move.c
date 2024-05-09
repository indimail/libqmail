/*
 * $Log: fd_move.c,v $
 * Revision 1.6  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.5  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.4  2004-10-22 20:25:03+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-07-17 21:18:46+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "fd.h"
#include <unistd.h>

int
fd_move(int to, int from)
{
	if (to == from)
		return 0;
	if (fd_copy(to, from) == -1)
		return -1;
	close(from);
	return 0;
}

void
getversion_fd_move_c()
{
	const char     *x = "$Id: fd_move.c,v 1.6 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
