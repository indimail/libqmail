/*
 * $Log: substdio.c,v $
 * Revision 1.7  2025-01-21 22:21:37+05:30  Cprogrammer
 * fixes for gcc14
 *
 * Revision 1.6  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.5  2020-05-12 11:23:47+05:30  Cprogrammer
 * converted to C89 prototype and len argument changed to size_t
 *
 * Revision 1.4  2008-07-14 20:59:22+05:30  Cprogrammer
 * fixed compilation warning on 64 bit os
 *
 * Revision 1.3  2004-10-22 20:31:11+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:39+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "substdio.h"
#include <sys/types.h>

void
substdio_fdbuf(register substdio *s, register ssize_t (*op)(int, char *, size_t),
		register int fd, register char *buf, register size_t len)
{
	s->x = buf;
	s->fd = fd;
	s->op = op;
	s->p = 0;
	s->n = len;
}

void
getversion_substdio_c()
{
	const char     *x = "$Id: substdio.c,v 1.7 2025-01-21 22:21:37+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
