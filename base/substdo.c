/*
 * $Log: substdo.c,v $
 * Revision 1.7  2020-05-12 11:34:33+05:30  Cprogrammer
 * length argument for allwrite(), substdio_put(), substdio_bput(), substdio_putflsh() changed to unsigned to fix integer signedness error (CVE-2005-1515)
 *
 * Revision 1.6  2018-05-24 16:23:19+05:30  Cprogrammer
 * added subsdio_discard() function to discard unflushed data
 *
 * Revision 1.5  2014-01-29 14:04:26+05:30  Cprogrammer
 * fixed compilation warnings
 *
 * Revision 1.4  2008-09-16 08:27:09+05:30  Cprogrammer
 * added substdio_putalign
 *
 * Revision 1.3  2004-10-22 20:31:12+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:41+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "substdio.h"
#include "str.h"
#include "byte.h"
#include "error.h"

static int
allwrite(register ssize_t (*op)(), register int fd, register char *buf, register unsigned int len)
{
	register int    w;

	while (len) {
		if ((w = op(fd, buf, len)) == -1) {
			if (errno == error_intr)
				continue;
			return -1;	/*- note that some data may have been written */
		}
		if (w == 0);	/*- luser's fault */
		buf += w;
		len -= w;
	}
	return 0;
}

void
substdio_discard(register substdio *s)
{
	s->p = 0;
	return;
}

int
substdio_flush(register substdio *s)
{
	register int    p;

	if (!(p = s->p))
		return 0;
	s->p = 0;
	return allwrite(s->op, s->fd, s->x, p);
}

int
substdio_bput(register substdio *s, register char *buf, register unsigned int len)
{
	register unsigned int n;

	while (len > (n = s->n - s->p)) {
		byte_copy(s->x + s->p, n, buf);
		s->p += n;
		buf += n;
		len -= n;
		if (substdio_flush(s) == -1)
			return -1;
	}
	/*
	 * now len <= s->n - s->p 
	 */
	byte_copy(s->x + s->p, len, buf);
	s->p += len;
	return 0;
}

int
substdio_putalign(substdio *s, char *buf, unsigned int len)
{
	unsigned int    n;
 
	while (len > (n = s->n - s->p)) {
		byte_copy(s->x + s->p,n,buf);
		s->p += n;
		buf += n;
		len -= n;
		if (substdio_flush(s) == -1)
			return -1;
	}
	/* now len <= s->n - s->p */
	byte_copy(s->x + s->p,len,buf);
	s->p += len;
	return 0;
}

int
substdio_put(register substdio *s, register char *buf, register unsigned int len)
{
	register unsigned int n = s->n; /* how many bytes to write in next chunk */

	/* check if the input would fit in the buffer without flushing */
	if (len > n - (unsigned int) s->p) {
		if (substdio_flush(s) == -1)
			return -1;
		/*- now s->p == 0 */
		if (n < SUBSTDIO_OUTSIZE)
			n = SUBSTDIO_OUTSIZE;
		/*-
		 * as long as the remainder would not fit into s->x
		 * write it directly from buf to s->fd.
		 */
		while (len > (unsigned int) s->n) {
			if (n > len)
				n = len;
			if (allwrite(s->op, s->fd, buf, n) == -1)
				return -1;
			buf += n;
			len -= n;
		}
	}
	/*- now len <= s->n - s->p */
	byte_copy(s->x + s->p, len, buf);
	s->p += len;
	return 0;
}

int
substdio_putflush(register substdio *s, register char *buf, register unsigned int len)
{
	if (substdio_flush(s) == -1)
		return -1;
	return allwrite(s->op, s->fd, buf, len);
}

int
substdio_bputs(register substdio *s, register char *buf)
{
	return substdio_bput(s, buf, str_len(buf));
}

int
substdio_puts(register substdio *s, register char *buf)
{
	return substdio_put(s, buf, str_len(buf));
}

int
substdio_putsflush(register substdio *s, register char *buf)
{
	return substdio_putflush(s, buf, str_len(buf));
}

void
getversion_substdo_c()
{
	static char    *x = "$Id: substdo.c,v 1.7 2020-05-12 11:34:33+05:30 Cprogrammer Exp mbhangui $";

	x++;
}