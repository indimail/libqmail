/*
 * $Log: subfd.h,v $
 * Revision 1.5  2025-01-21 22:20:26+05:30  Cprogrammer
 * fixes for gcc14
 *
 * Revision 1.4  2008-07-14 20:58:52+05:30  Cprogrammer
 * fixed compilation warning on 64 bit os
 *
 * Revision 1.3  2004-10-11 14:09:23+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 23:02:02+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef SUBFD_H
#define SUBFD_H

#include "substdio.h"

extern substdio *subfdin;
extern substdio *subfdinsmall;
extern substdio *subfdout;
extern substdio *subfdoutsmall;
extern substdio *subfderr;

ssize_t         subfd_read(int, char *, size_t);
ssize_t         subfd_readsmall(int, char *, size_t);

#endif
