/*
 * $Log: subfdin.c,v $
 * Revision 1.7  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.6  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.5  2008-07-14 20:59:05+05:30  Cprogrammer
 * fixed compilation warning on 64 bit os
 *
 * Revision 1.4  2004-10-22 20:31:04+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-10-22 15:39:37+05:30  Cprogrammer
 * replaced readwrite.h with unistd.h
 *
 * Revision 1.2  2004-07-17 21:24:28+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <unistd.h>
#include "substdio.h"
#include "subfd.h"

ssize_t
subfd_read(int fd, char *buf, size_t len)
{
	if (substdio_flush(subfdout) == -1)
		return -1;
	return read(fd, buf, len);
}

char            subfd_inbuf[SUBSTDIO_INSIZE];
static substdio it = SUBSTDIO_FDBUF(subfd_read, 0, subfd_inbuf, SUBSTDIO_INSIZE);
substdio       *subfdin = &it;

void
getversion_subfdin_c()
{
	const char     *x = "$Id: subfdin.c,v 1.7 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
