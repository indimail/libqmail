/*
 * $Log: makeargs.h,v $
 * Revision 1.2  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.1  2021-06-09 21:27:06+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef MAKEARGS_H
#define MAKEARGS_H

#ifndef	lint
static const char sccsidmakeargsh[] = "$Id: makeargs.h,v 1.2 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";
#endif

char          **makeargs(const char *);
void            free_makeargs(char **);

#endif
