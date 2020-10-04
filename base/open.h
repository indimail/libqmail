/*
 * $Log: open.h,v $
 * Revision 1.7  2019-06-24 21:23:48+05:30  Cprogrammer
 * added open_readwrite prototype
 *
 * Revision 1.6  2004-10-11 13:57:02+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.5  2004-06-18 23:01:12+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef OPEN_H
#define OPEN_H

int             open_read(char *);
int             open_excl(char *);
int             open_append(char *);
int             open_trunc(char *);
int             open_write(char *);
int             open_readwrite(char *);
#endif