/*
 * $Log: udpopen.h,v $
 * Revision 1.1  2023-02-08 11:26:12+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef _UDPOPEN_H
#define _UDPOPEN_H

#ifndef __P
#ifdef __STDC__
#define __P(args) args
#else
#define __P(args) ()
#endif
#endif

int             udpopen     __P((char *, char *));

#endif

