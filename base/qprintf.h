/*
 * $Log: qprintf.h,v $
 * Revision 1.5  2023-02-08 11:22:57+05:30  Cprogrammer
 * include qmailconfig.h if HAVE_CONFIG_H is not defined
 *
 * Revision 1.4  2023-01-21 16:59:29+05:30  Cprogrammer
 * added __attribute__ ((format (printf, x, y))) for compile time warnings
 * added qsprintf function
 *
 * Revision 1.3  2023-01-17 17:02:09+05:30  Cprogrammer
 * added stralloc.h
 *
 * Revision 1.2  2023-01-16 18:47:23+05:30  Cprogrammer
 * added subprintf, qsnprintf functions
 *
 * Revision 1.1  2020-07-01 16:57:13+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef QPRINTF_H
#define QPRINTF_H
#include "substdio.h"
#include "stralloc.h"
#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#include "qmailconfig.h"
#endif
#ifdef HAVE_STDARG_H
#include <stdarg.h>
#endif

int             qprintf(substdio *, const char *, const char *);
int             qprintf_flush(substdio *);
#ifdef HAVE_STDARG_H
int             subprintf(substdio *ss, const char *format, ...)
					__attribute__ ((format (printf, 2, 3)));
int             qsprintf(stralloc *, const char *format, ...)
					__attribute__ ((format (printf, 2, 3)));
int             qsnprintf(stralloc *, size_t size, const char *format, ...)
					__attribute__ ((format (printf, 3, 4)));
#else
int             subprintf();
int             qsprintf();
int             qsnprintf();
#endif
#endif
