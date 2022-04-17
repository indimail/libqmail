/*
 * $Log: makesalt.h,v $
 * Revision 1.2  2022-04-17 08:20:52+05:30  Cprogrammer
 * change in return type of makesalt()
 *
 * Revision 1.1  2020-04-01 18:13:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef HAVE_MAKESALT_H
#define HAVE_MAKESALT_H

#define SALTSIZE 32

int             makesalt(char *, int);
char           *genpass(int);

#endif
