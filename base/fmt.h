/*
 * $Log: fmt.h,v $
 * Revision 1.13  2023-02-08 11:22:48+05:30  Cprogrammer
 * include qmailconfig.h if HAVE_CONFIG_H is not defined
 *
 * Revision 1.12  2020-11-24 09:31:23+05:30  Cprogrammer
 * use const keyword for readonly arguments
 *
 * Revision 1.11  2020-10-10 21:18:16+05:30  Cprogrammer
 * removed fmt_tohex()
 *
 * Revision 1.10  2020-08-03 18:11:20+05:30  Cprogrammer
 * added tohex() proto
 *
 * Revision 1.9  2020-07-04 23:43:48+05:30  Cprogrammer
 * include sys/types.h if config.h is not included
 *
 * Revision 1.8  2020-07-01 16:16:41+05:30  Cprogrammer
 * removed inttypes
 *
 * Revision 1.7  2020-07-01 12:15:39+05:30  Cprogrammer
 * added fmt_hexdump(), fmt_tohex()
 *
 * Revision 1.6  2019-06-24 21:22:06+05:30  Cprogrammer
 * added prototypes for fmt_int, fmt_ulonglong, fmt_long, fmt_8long, fmt_pad, fmt_fill
 *
 * Revision 1.5  2015-08-24 19:14:27+05:30  Cprogrammer
 * added fmt_hexbyte() function
 *
 * Revision 1.4  2013-08-29 18:26:57+05:30  Cprogrammer
 * added fmt_double()
 *
 * Revision 1.3  2004-10-10 10:11:25+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 22:58:52+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef FMT_H
#define FMT_H
#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#include "qmailconfig.h"
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#define FMT_LONG   41			/*- enough space to hold -2^127 in decimal, plus \0 */
#define FMT_ULONG  40			/*- enough space to hold 2^128 - 1 in decimal, plus \0 */
#define FMT_8LONG  44			/*- enough space to hold 2^128 - 1 in octal, plus \0 */
#define FMT_XLONG  33			/*- enough space to hold 2^128 - 1 in hexadecimal, plus \0 */
#define FMT_DOUBLE 63			/*- enough to hold double with 20 precision in fraction part */
#define FMT_LEN ((char *) 0)	/*- convenient abbreviation */

unsigned int    fmt_uint(char *, unsigned int);
unsigned int    fmt_int(char *, signed int);
unsigned int    fmt_uint0(char *, unsigned int, unsigned int);
unsigned int    fmt_ushort(char *, unsigned short);
unsigned int    fmt_ulong(char *, unsigned long);
unsigned int    fmt_ulonglong(char *, unsigned long long);
unsigned int    fmt_long(char *, signed long);
unsigned int    fmt_xlong(char *, unsigned long);
unsigned int    fmt_8long(char *, unsigned long);
unsigned int    fmt_hexbyte(char *, unsigned char);
size_t          fmt_hexdump(char *, const char *, size_t);
char            tohex(char);
unsigned int    fmt_double(char *s, double, unsigned int);
unsigned int    fmt_plusminus(char *, int);
unsigned int    fmt_minus(char *, int);

/*-
 * copy str to dest until \0 byte, return number of copied bytes. */
/* fmt_str(NULL,str) == strlen(str) */
/* fmt_str(buf,str) == strcpy(buf,str), return strlen(str) */
/* strcat(strcpy(buf,"foo"),"bar") can be written as
 *   i=fmt_str(buf,"foo");
 *   i+=fmt_str(buf+i,"bar");
 *   buf[i]=0;
 * This is more efficient because strcat needs to scan the string to
 * find the end and append.
 */
unsigned int    fmt_str(char *, const char *);
unsigned int    fmt_strn(char *, const char *, unsigned int);
/*-
 * write padlen-srclen spaces, if that is >= 0.  Then copy srclen
 * characters from src.  Truncate only if total length is larger than
 * maxlen.  Return number of characters written.
 */
unsigned int    fmt_pad(char *, const char *, unsigned int, unsigned int, unsigned int);

/*-
 * append padlen-srclen spaces after dest, if that is >= 0.  Truncate
 * only if total length is larger than maxlen.  Return number of
 * characters written.
 */
unsigned int    fmt_fill(char *, unsigned int, unsigned int, unsigned int);
#endif
