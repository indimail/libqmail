/*
 * $Log: mkpasswd.h,v $
 * Revision 1.2  2020-10-04 16:36:36+05:30  Cprogrammer
 * included missing stralloc.h
 *
 * Revision 1.1  2020-04-01 18:14:56+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef MKPASSWD_H
#define MKPASSWD_H
#include <stralloc.h>

int             mkpasswd(char *, stralloc *, int);

#endif
