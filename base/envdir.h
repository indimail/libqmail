/*
 * $Log: envdir.h,v $
 * Revision 1.5  2021-07-14 13:16:38+05:30  Cprogrammer
 * added arguments ignore_unreadable, unreadable_count
 *
 * Revision 1.4  2021-05-13 14:59:22+05:30  Cprogrammer
 * added envdir_str() function
 *
 * Revision 1.3  2021-05-13 09:38:13+05:30  Cprogrammer
 * added argument to return filename in error
 *
 * Revision 1.2  2014-01-22 20:36:57+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef ENVDIR_H
#define ENVDIR_H

int             envdir(char *, char **, int, int *);
char           *envdir_str(int);

#endif
