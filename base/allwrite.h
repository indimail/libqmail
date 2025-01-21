/*
 * $Log: allwrite.h,v $
 * Revision 1.2  2025-01-21 22:18:48+05:30  Cprogrammer
 * fixes for gcc14
 *
 * Revision 1.1  2023-01-02 19:47:23+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef _ALLWRITE_H
#define _ALLWRITE_H
#include <sys/types.h>

ssize_t         allwrite(int, const char *, size_t);
#endif
