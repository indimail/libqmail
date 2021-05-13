/*
 * $Log: envdir.h,v $
 * Revision 1.3  2021-05-13 09:38:13+05:30  Cprogrammer
 * added argument to return filename in error
 *
 * Revision 1.2  2014-01-22 20:36:57+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef ENVDIR_H
#define ENVDIR_H

int             envdir(char *, char **);
char           *envdir_str(int);

#endif
