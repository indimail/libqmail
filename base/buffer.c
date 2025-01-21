/*
 * $Id: buffer.c,v 1.3 2025-01-21 22:18:54+05:30 Cprogrammer Exp mbhangui $
 */
#include <unistd.h>
#include <errno.h>
#include "buffer.h"
#include <str.h>
#include <byte.h>

/*
 * author djb
 */

void
buffer_init(buffer *s, ssize_t(*op) (int, char *, size_t), int fd, char *buf, size_t len)
{
	s->x = buf;
	s->fd = fd;
	s->op = op;
	s->p = 0;
	s->n = len;
}

ssize_t
buffer_0_read(int fd, char *buf, size_t len)
{
	if (buffer_flush(buffer_1) == -1)
		return -1;
	return read(fd, buf, len);
}

char            buffer_0_space[BUFFER_INSIZE];
char            buffer_1_space[BUFFER_OUTSIZE];
char            buffer_2_space[BUFFER_OUTSIZE];
static buffer   it0 = BUFFER_INIT(buffer_0_read, 0, buffer_0_space, sizeof (buffer_0_space));
static buffer   it1 = BUFFER_INIT((ssize_t (*)(int,  char *, size_t)) write, 1, buffer_1_space, sizeof (buffer_1_space));
static buffer   it2 = BUFFER_INIT((ssize_t (*)(int,  char *, size_t)) write, 2, buffer_2_space, sizeof (buffer_2_space));

buffer         *buffer_0 = &it0;
buffer         *buffer_1 = &it1;
buffer         *buffer_2 = &it2;

char            buffer_0_small[BUFFER_SMALL];
char            buffer_1_small[BUFFER_SMALL];
char            buffer_2_small[BUFFER_SMALL];

static buffer   is0 = BUFFER_INIT(buffer_0_read, 0, buffer_0_small, sizeof (buffer_0_small));
static buffer   is1 = BUFFER_INIT((ssize_t (*)(int,  char *, size_t)) write, 1, buffer_1_small, sizeof (buffer_1_small));
static buffer   is2 = BUFFER_INIT((ssize_t (*)(int,  char *, size_t)) write, 2, buffer_2_small, sizeof (buffer_2_small));

buffer         *buffer_0small = &is0;
buffer         *buffer_1small = &is1;
buffer         *buffer_2small = &is2;

ssize_t
buffer_unixread(int fd, char *buf, size_t len)
{
	return read(fd, buf, len);
}

ssize_t
buffer_unixwrite(int fd, const char *buf, size_t len)
{
	return write(fd, buf, len);
}

int
buffer_copy(buffer *bout, buffer *bin)
{
	int             n;
	char           *x;

	for (;;) {
		if ((n = buffer_feed(bin)) < 0)
			return -2;
		if (!n)
			return 0;
		x = buffer_PEEK(bin);
		if (buffer_put(bout, x, n) == -1)
			return -3;
		buffer_SEEK(bin, n);
	}
}

static int
oneread(ssize_t(*op) (int, char *, size_t), int fd, char *buf, size_t len)
{
	int             r;

	for (;;) {
		if ((r = op(fd, buf, len)) == -1) {
			if (errno == EINTR)
				continue;
		}
		return r;
	}
}

static int
getthis(buffer *s, char *buf, size_t len)
{
	if (len > s->p)
		len = s->p;
	s->p -= len;
	byte_copy(buf, len, s->x + s->n);
	s->n += len;
	return len;
}

int
buffer_feed(buffer *s)
{
	int             r;

	if (s->p)
		return s->p;
	if ((r = oneread(s->op, s->fd, s->x, s->n)) <= 0)
		return r;
	s->p = r;
	s->n -= r;
	if (s->n > 0)
		byte_copyr(s->x + s->n, r, s->x);
	return r;
}

int
buffer_bget(buffer *s, char *buf, size_t len)
{
	int             r;

	if (s->p > 0)
		return getthis(s, buf, len);
	if (s->n <= len)
		return oneread(s->op, s->fd, buf, s->n);
	if ((r = buffer_feed(s)) <= 0)
		return r;
	return getthis(s, buf, len);
}

int
buffer_get(buffer *s, char *buf, size_t len)
{
	int             r;

	if (s->p > 0)
		return getthis(s, buf, len);
	if (s->n <= len)
		return oneread(s->op, s->fd, buf, len);
	if ((r = buffer_feed(s)) <= 0)
		return r;
	return getthis(s, buf, len);
}

char           *
buffer_peek(buffer *s)
{
	return s->x + s->n;
}

void
buffer_seek(buffer *s, size_t len)
{
	s->n += len;
	s->p -= len;
}

static int
allwrite(ssize_t(*op) (int, const char *, size_t), int fd, const char *buf, size_t len)
{
	int             w;

	while (len) {
		if ((w = op(fd, buf, len)) == -1) {
			if (errno == EINTR)
				continue;
			return -1; /* note that some data may have been written */
		}
		if (w == 0) /* luser's fault */
			;
		buf += w;
		len -= w;
	}
	return 0;
}

void
buffer_discard(buffer *s)
{
	s->p = 0;
	return;
}

int
buffer_flush(buffer *s)
{
	int             p;

	if (!(p = s->p))
		return 0;
	s->p = 0;
	return allwrite((ssize_t (*)(int,  const char *, size_t)) s->op, s->fd, s->x, p);
}

int
buffer_putalign(buffer *s, const char *buf, size_t len)
{
	unsigned int    n;

	while (len > (n = s->n - s->p)) {
		byte_copy(s->x + s->p, n, buf);
		s->p += n;
		buf += n;
		len -= n;
		if (buffer_flush(s) == -1)
			return -1;
	}
	/*- now len <= s->n - s->p */
	byte_copy(s->x + s->p, len, buf);
	s->p += len;
	return 0;
}

int
buffer_put(buffer *s, const char *buf, size_t len)
{
	unsigned int    n;

	n = s->n;
	if (len > n - s->p) {
		if (buffer_flush(s) == -1)
			return -1;
		/*- now s->p == 0 */
		if (n < BUFFER_OUTSIZE)
			n = BUFFER_OUTSIZE;
		while (len > s->n) {
			if (n > len)
				n = len;
			if (allwrite((ssize_t (*)(int,  const char *, size_t)) s->op, s->fd, buf, n) == -1)
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
buffer_putflush(buffer *s, const char *buf, size_t len)
{
	if (buffer_flush(s) == -1)
		return -1;
	return allwrite((ssize_t (*)(int,  const char *, size_t)) s->op, s->fd, buf, len);
}

int
buffer_putsalign(buffer *s, const char *buf)
{
	return buffer_putalign(s, buf, str_len(buf));
}

int
buffer_puts(buffer *s, const char *buf)
{
	return buffer_put(s, buf, str_len(buf));
}

int
buffer_putsflush(buffer *s, const char *buf)
{
	return buffer_putflush(s, buf, str_len(buf));
}

/*
 * $Log: buffer.c,v $
 * Revision 1.3  2025-01-21 22:18:54+05:30  Cprogrammer
 * fixes for gcc14
 *
 * Revision 1.2  2024-05-12 00:10:20+05:30  mbhangui
 * fix function prototypes
 *
 * Revision 1.1  2024-01-22 10:15:46+05:30  Cprogrammer
 * Initial revision
 *
 */
