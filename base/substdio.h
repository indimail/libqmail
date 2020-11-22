/*
 * $Log: substdio.h,v $
 * Revision 1.9  2020-11-22 23:54:03+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.8  2020-11-22 20:31:54+05:30  Cprogrammer
 * removed newline
 *
 * Revision 1.7  2020-05-12 11:27:24+05:30  Cprogrammer
 * changed len argument of substdio_fdbuf to size_t
 * length argument for substdio_put(), substdio_bput(), substdio_putflsh() changed to unsigned to fix integer signedness error (CVE-2005-1515)
 *
 * Revision 1.6  2018-05-24 16:23:49+05:30  Cprogrammer
 * added subsdio_discard() function to discard unflushed data
 *
 * Revision 1.5  2008-09-16 08:25:54+05:30  Cprogrammer
 * added substdio_putalign
 *
 * Revision 1.4  2008-07-14 20:59:31+05:30  Cprogrammer
 * fixed compilation warning on 64 bit os
 *
 * Revision 1.3  2004-10-09 23:34:37+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 23:02:06+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef SUBSTDIO_H
#define SUBSTDIO_H
#include <sys/types.h>

typedef struct substdio
{
	char           *x;
	int             p;
	int             n;
	int             fd;
	ssize_t         (*op) ();
} substdio;

#define SUBSTDIO_FDBUF(op,fd,buf,len) { (buf), 0, (len), (fd), (op) }

void            substdio_fdbuf(substdio *, ssize_t (*op) (), int, char *, size_t);
int             substdio_flush(substdio *);
void            substdio_discard(substdio *);
int             substdio_putalign(substdio *, const char *, unsigned int);
int             substdio_put(substdio *, const char *, unsigned int);
int             substdio_bput(substdio *, const char *, unsigned int);
int             substdio_putflush(substdio *, const char *, unsigned int);
int             substdio_puts(substdio *, const char *);
int             substdio_bputs(substdio *, const char *);
int             substdio_putsflush(substdio *, const char *);
int             substdio_get(substdio *, char *, int);
int             substdio_bget(substdio *, char *, int);
int             substdio_feed(substdio *);
char           *substdio_peek(substdio *);
void            substdio_seek(substdio *, int);
int             substdio_copy(substdio *, substdio *);

#define substdio_fileno(s) ((s)->fd)

#define SUBSTDIO_INSIZE 8192
#define SUBSTDIO_OUTSIZE 8192

#define substdio_PEEK(s)     ((s)->x + (s)->n)
#define substdio_SEEK(s,len) (((s)->p -= (len)) , ((s)->n += (len)))

#define substdio_BPUTC(s,c) \
  (((s)->n != (s)->p) ? ((s)->x[(s)->p++] = (c), 0) : substdio_bput((s),&(c),1))

#endif
