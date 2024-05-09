/*
 * $Log: timeoutread.c,v $
 * Revision 1.7  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.6  2024-01-23 18:36:27+05:30  Cprogrammer
 * added timeoutread() using poll() instead of select()
 *
 * Revision 1.5  2021-03-03 23:56:25+05:30  Cprogrammer
 * fix data types
 *
 * Revision 1.4  2004-10-22 20:31:45+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-10-22 15:40:02+05:30  Cprogrammer
 * replaced readwrite.h with unistd.h
 *
 * Revision 1.2  2004-07-17 21:24:52+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <unistd.h>
#include <sys/types.h>
#include "timeoutread.h"
#include "iopause.h"
#include "error.h"

#ifdef IOPAUSE_POLL /*- taken from Erwin Hofman fehQlibs */
ssize_t
timeoutread(long t, int fd, char *buf, size_t len)
{
	struct taia     now;
	struct taia     deadline;
	iopause_fd      x;

	taia_now(&now);
	taia_uint(&deadline, t);
	taia_add(&deadline, &now, &deadline);

	x.fd = fd;
	x.events = IOPAUSE_READ;
	for (;;) {
		taia_now(&now);
		iopause(&x, 1, &deadline, &now);
		if (x.revents)
			break;
		if (taia_less(&deadline, &now)) {
			errno = ETIMEDOUT;
			return -1;
		}
	}
	return read(fd, buf, len);
}
#else
#include "select.h"

ssize_t
timeoutread(long t, int fd, char *buf, size_t len)
{
	fd_set          rfds;
	struct timeval  tv;

	tv.tv_sec = t;
	tv.tv_usec = 0;

	FD_ZERO(&rfds);
	FD_SET(fd, &rfds);

	if (select(fd + 1, &rfds, (fd_set *) 0, (fd_set *) 0, &tv) == -1)
		return -1;
	if (FD_ISSET(fd, &rfds))
		return read(fd, buf, len);

	errno = error_timeout;
	return -1;
}
#endif

void
getversion_timeoutread_c()
{
	const char     *x = "$Id: timeoutread.c,v 1.7 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
