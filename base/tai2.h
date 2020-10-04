/*
 * $Log: tai2.h,v $
 * Revision 1.1  2019-07-18 10:15:32+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef __TAI2__H__
#define __TAI2__H__
#include "stralloc.h"

struct tai {
	unsigned long   seconds;
	unsigned long   nanoseconds;
};
typedef struct tai tai;

tai            *tai64n_decode(stralloc *, char **);
int             tai64n_encode(tai *, char *);

tai            *tai_decode(stralloc *, char **);
int             tai_encode(tai *, char *);

#endif
