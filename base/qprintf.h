/*
 * $Log: qprintf.h,v $
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
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_STDARG_H
#include <stdarg.h>
#endif

int             qprintf(substdio *, char *, char *);
int             qprintf_flush(substdio *);
#ifdef HAVE_STDARG_H
int             subprintf(substdio *ss, const char *format, ...);
int             qsnprintf(stralloc *, size_t size, const char *format, ...);
#else
int             subprintf();
int             qsnprintf();
#endif
#endif
