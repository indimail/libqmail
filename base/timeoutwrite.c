/*
 * $Log: timeoutwrite.c,v $
 * Revision 1.7  2024-01-23 18:36:52+05:30  Cprogrammer
 * added timeoutwrite using poll() instead of select()
 *
 * Revision 1.6  2023-01-11 00:35:01+05:30  Cprogrammer
 * replaced write() with allwrite()
 *
 * Revision 1.5  2021-03-03 23:56:39+05:30  Cprogrammer
 * fix data types
 *
 * Revision 1.4  2004-10-22 20:31:46+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-10-22 15:40:04+05:30  Cprogrammer
 * replaced readwrite.h with unistd.h
 *
 * Revision 1.2  2004-07-17 21:24:54+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <unistd.h>
#include <sys/types.h>
#include "timeoutwrite.h"
#include "allwrite.h"
#include "iopause.h"
#include "error.h"

#ifdef IOPAUSE_POLL /*- taken from Erwin Hofman fehQlibs */
ssize_t
timeoutwrite(long t, int fd, char *buf, size_t len)
{
	struct taia     now;
	struct taia     deadline;
	iopause_fd      x;

	taia_now(&now);
	taia_uint(&deadline, t);
	taia_add(&deadline, &now, &deadline);

	x.fd = fd;
	x.events = IOPAUSE_WRITE;
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
	return allwrite(fd, buf, len);
}
#else
#include "select.h"

ssize_t
timeoutwrite(long t, int fd, char *buf, size_t len)
{
	fd_set          wfds;
	struct timeval  tv;

	tv.tv_sec = t;
	tv.tv_usec = 0;

	FD_ZERO(&wfds);
	FD_SET(fd, &wfds);

	if (select(fd + 1, (fd_set *) 0, &wfds, (fd_set *) 0, &tv) == -1)
		return -1;
	if (FD_ISSET(fd, &wfds))
		return allwrite(fd, buf, len);

	errno = error_timeout;
	return -1;
}
#endif

void
getversion_timeoutwrite_c()
{
	const char     *x = "$Id: timeoutwrite.c,v 1.7 2024-01-23 18:36:52+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
