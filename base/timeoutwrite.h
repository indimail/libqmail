/*
 * $Log: timeoutwrite.h,v $
 * Revision 1.5  2025-01-21 22:21:52+05:30  Cprogrammer
 * fixes for gcc14
 *
 * Revision 1.4  2021-03-03 23:56:44+05:30  Cprogrammer
 * fix data types
 *
 * Revision 1.3  2004-10-11 14:15:27+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 23:02:15+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef TIMEOUTWRITE_H
#define TIMEOUTWRITE_H
#include <sys/types.h>

ssize_t         timeoutwrite(long, int, const char *, size_t);

#endif
