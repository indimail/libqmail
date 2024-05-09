/*
 * $Log: tcpopen.h,v $
 * Revision 1.1  2023-02-08 11:26:09+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef _TCPOPEN_H
#define _TCPOPEN_H

#ifndef __P
#ifdef __STDC__
#define __P(args) args
#else
#define __P(args) ()
#endif
#endif

int             tcpopen     __P((const char *, const char *, int));

#endif

