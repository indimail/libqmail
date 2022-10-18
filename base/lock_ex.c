/*
 * $Log: lock_ex.c,v $
 * Revision 1.5  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.4  2004-10-22 20:26:06+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-07-17 21:19:21+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <sys/types.h>
#include <sys/file.h>
#include <fcntl.h>
#include "hasflock.h"
#include "lock.h"

#ifdef HASFLOCK
int
lock_ex(int fd)
{
	return flock(fd, LOCK_EX);
}
#else
#include <unistd.h>
int
lock_ex(int fd)
{
	return lockf(fd, 1, 0);
}
#endif

void
getversion_lock_ex_c()
{
	static char    *x = "$Id: lock_ex.c,v 1.5 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
