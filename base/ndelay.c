/*
 * $Log: ndelay.c,v $
 * Revision 1.5  2023-01-02 20:33:25+05:30  Cprogrammer
 * added ndelay() function to get status of DELAY flag for descriptor
 *
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:27:39+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:19:52+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <sys/types.h>
#include <fcntl.h>
#include "ndelay.h"

#ifndef O_NONBLOCK
#define O_NONBLOCK O_NDELAY
#endif

int
ndelay_on(int fd)
{
	return fcntl(fd, F_SETFL, fcntl(fd, F_GETFL, 0) | O_NONBLOCK);
}

int
ndelay(int fd)
{
	int             i;

	if ((i = fcntl(fd, F_GETFL, 0)) == -1)
		return -1;
	return i & O_NONBLOCK ? 1 : 0;
}

void
getversion_ndelay_c()
{
	static char    *x = "$Id: ndelay.c,v 1.5 2023-01-02 20:33:25+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
