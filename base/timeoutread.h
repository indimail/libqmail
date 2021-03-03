/*
 * $Log: timeoutread.h,v $
 * Revision 1.4  2021-03-03 23:56:32+05:30  Cprogrammer
 * fix data types
 *
 * Revision 1.3  2004-10-11 14:15:25+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 23:02:13+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef TIMEOUTREAD_H
#define TIMEOUTREAD_H
#include <sys/types.h>

ssize_t         timeoutread(long, int, char *, size_t);

#endif
