/*
 * $Log: readclose.h,v $
 * Revision 1.1  2020-11-24 09:35:29+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef READCLOSE_H
#define READCLOSE_H

#include "stralloc.h"

extern int      readclose_append(int, stralloc *, unsigned int);
extern int      readclose(int, stralloc *, unsigned int);

#endif
