/*
 * $Log: qprintf.h,v $
 * Revision 1.1  2020-07-01 16:57:13+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef QPRINTF_H
#define QPRINTF_H
#include "substdio.h"

int             qprintf(substdio *, char *, char *);
int             qprintf_flush(substdio *);
#endif
