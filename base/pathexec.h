/*
 * $Log: pathexec.h,v $
 * Revision 1.5  2024-05-09 23:46:54+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2021-07-14 09:39:16+05:30  Cprogrammer
 * added pathexec_clear() to clear new env variables added
 *
 * Revision 1.3  2010-06-08 22:00:08+05:30  Cprogrammer
 * pathexec() now returns the allocated environment variable
 *
 * Revision 1.2  2004-10-11 13:57:08+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.1  2004-06-18 22:59:20+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef PATHEXEC_H
#define PATHEXEC_H

void            pathexec_run(const char *, char **, char **);
int             pathexec_env(const char *, const char *);
void            pathexec_clear();
char          **pathexec(char **);

#endif
