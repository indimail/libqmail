/*
 * $Log: lock_un.c,v $
 * Revision 1.6  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.5  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.4  2004-10-22 20:26:08+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-07-17 21:19:24+05:30  Cprogrammer
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
lock_un(int fd)
{
	return flock(fd, LOCK_UN);
}
#else
#include <unistd.h>
int
lock_un(int fd)
{
	return lockf(fd, 0, 0);
}
#endif

void
getversion_lock_un_c()
{
	const char     *x = "$Id: lock_un.c,v 1.6 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
