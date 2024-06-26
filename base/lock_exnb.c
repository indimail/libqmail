/*
 * $Log: lock_exnb.c,v $
 * Revision 1.6  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.5  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.4  2004-10-22 20:26:07+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-07-17 21:19:23+05:30  Cprogrammer
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
lock_exnb(int fd)
{
	return flock(fd, LOCK_EX | LOCK_NB);
}
#else
#include <unistd.h>
int
lock_exnb(int fd)
{
	return lockf(fd, 2, 0);
}
#endif

void
getversion_lock_exnb_c()
{
	const char     *x = "$Id: lock_exnb.c,v 1.6 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
