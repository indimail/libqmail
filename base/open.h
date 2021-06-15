/*
 * $Log: open.h,v $
 * Revision 1.9  2021-06-15 21:21:29+05:30  Cprogrammer
 * added open_exclr() function
 *
 * Revision 1.8  2020-11-22 23:51:45+05:30  Cprogrammer
 * use const keyword
 *
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

int             open_read(const char *);
int             open_excl(const char *);
int             open_exclr(const char *);
int             open_append(const char *);
int             open_trunc(const char *);
int             open_write(const char *);
int             open_readwrite(const char *);
#endif
