/*
 * $Log: fifo.h,v $
 * Revision 1.5  2024-05-09 23:46:54+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-11 13:53:35+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 22:58:50+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef FIFO_H
#define FIFO_H
#include <sys/types.h>

int             fifo_make(const char *, mode_t);

#endif
