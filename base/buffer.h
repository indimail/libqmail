/*
 * $Id: buffer.h,v 1.3 2025-01-21 22:18:59+05:30 Cprogrammer Exp mbhangui $
 */

#ifndef BUFFER_H
#define BUFFER_H
#include <sys/types.h> /* need type: ssize_t */

typedef struct buffer {
	char           *x;
	unsigned int    p;
	size_t          n;
	int             fd;
	ssize_t         (*op) (int, char *, size_t);
} buffer;

#define BUFFER_INIT(op,fd,buf,len) { (buf), 0, (len), (fd), (op) }
#define BUFFER_SMALL 256
#define BUFFER_INSIZE 8192
#define BUFFER_OUTSIZE 8192

extern void     buffer_init(buffer *, ssize_t(*op) (int, char *, size_t), int, char *, size_t);
extern int      buffer_flush(buffer *);
extern void     buffer_discard(buffer *);
extern int      buffer_put(buffer *, const char *, size_t);
extern int      buffer_putalign(buffer *, const char *, size_t);
extern int      buffer_putflush(buffer *, const char *, size_t);
extern int      buffer_puts(buffer *, const char *);
extern int      buffer_putsalign(buffer *, const char *);
extern int      buffer_putsflush(buffer *, const char *);

#define buffer_PUTC(s,c) \
  ( ((s)->n != (s)->p) \
    ? ( (s)->x[(s)->p++] = (c), 0 ) \
    : buffer_put((s),&(c),1) \
  )

extern int      buffer_get(buffer *, char *, size_t);
extern int      buffer_bget(buffer *, char *, size_t);
extern int      buffer_feed(buffer *);

extern char    *buffer_peek(buffer *);
extern void     buffer_seek(buffer *, size_t);

#define buffer_PEEK(s) ( (s)->x + (s)->n )
#define buffer_SEEK(s,len) ( ( (s)->p -= (len) ) , ( (s)->n += (len) ) )

#define buffer_GETC(s,c) \
  ( ((s)->p > 0) \
    ? ( *(c) = (s)->x[(s)->n], buffer_SEEK((s),1), 1 ) \
    : buffer_get((s),(c),1) \
  )

extern int      buffer_copy(buffer *, buffer *);
extern ssize_t  buffer_unixread(int, char *, size_t);
extern ssize_t  buffer_unixwrite(int, const char *, size_t);

extern buffer  *buffer_0;
extern buffer  *buffer_1;
extern buffer  *buffer_2;
extern buffer  *buffer_0small;
extern buffer  *buffer_1small;
extern buffer  *buffer_2small;

#endif
