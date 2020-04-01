/*
 * $Log: makesalt.h,v $
 * Revision 1.1  2020-04-01 18:13:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef HAVE_MAKESALT_H
#define HAVE_MAKESALT_H

#define SALTSIZE 32

void            makesalt(char *, int);
char           *genpass(int);

#endif
