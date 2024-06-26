/*
 * $Log: substdi.c,v $
 * Revision 1.7  2024-05-12 00:10:20+05:30  mbhangui
 * fix function prototypes
 *
 * Revision 1.6  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.5  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.4  2014-01-29 14:04:20+05:30  Cprogrammer
 * fixed compilation warnings
 *
 * Revision 1.3  2004-10-22 20:31:08+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:37+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "substdio.h"
#include "byte.h"
#include "error.h"

static int
oneread(register ssize_t (*op) (int, char *, size_t), register int fd,
		register char *buf, register int len)
{
	register int    r;

	for (;;) {
		r = op(fd, buf, len);
		if (r == -1)
			if (errno == error_intr)
				continue;
		return r;
	}
}

static int
getthis(register substdio *s, register char *buf, register int len)
{
	register int    r;
	register int    q;

	r = s->p;
	q = r - len;
	if (q > 0) {
		r = len;
		s->p = q;
	} else
		s->p = 0;
	byte_copy(buf, r, s->x + s->n);
	s->n += r;
	return r;
}

int
substdio_feed(register substdio *s)
{
	register int    r;
	register int    q;

	if (s->p)
		return s->p;
	q = s->n;
	r = oneread(s->op, s->fd, s->x, q);
	if (r <= 0)
		return r;
	s->p = r;
	q -= r;
	s->n = q;
	if (q > 0)	/*- damn, gotta shift */
		byte_copyr(s->x + q, r, s->x);
	return r;
}

int
substdio_bget(register substdio *s, register char *buf, register int len)
{
	register int    r;

	if (s->p > 0)
		return getthis(s, buf, len);
	r = s->n;
	if (r <= len)
		return oneread(s->op, s->fd, buf, r);
	r = substdio_feed(s);
	if (r <= 0)
		return r;
	return getthis(s, buf, len);
}

int
substdio_get(register substdio *s, register char *buf, register int len)
{
	register int    r;

	if (s->p > 0)
		return getthis(s, buf, len);
	if (s->n <= len)
		return oneread(s->op, s->fd, buf, len);
	r = substdio_feed(s);
	if (r <= 0)
		return r;
	return getthis(s, buf, len);
}

char           *
substdio_peek(register substdio *s)
{
	return s->x + s->n;
}

void
substdio_seek(register substdio *s, register int len)
{
	s->n += len;
	s->p -= len;
}

void
getversion_substdi_c()
{
	const char     *x = "$Id: substdi.c,v 1.7 2024-05-12 00:10:20+05:30 mbhangui Exp mbhangui $";

	x++;
}
