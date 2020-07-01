/*
 * $Log: base64.h,v $
 * Revision 1.4  2020-07-01 12:13:06+05:30  Cprogrammer
 * added definition for b64alpha
 *
 * Revision 1.3  2004-06-18 22:55:43+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef BASE64_H
#define BASE64_H
#include "stralloc.h"

#ifndef _B64SUB_C
extern const char b64alpha[];
#endif

extern int b64decode(const unsigned char *, int, stralloc *);
extern int b64encode(stralloc *, stralloc *);

#endif
