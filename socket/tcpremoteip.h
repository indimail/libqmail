/*
 * $Log: tcpremoteip.h,v $
 * Revision 1.1  2023-06-28 10:11:56+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef _TCPREMOTEIP_H
#define _TCPREMOTEIP_H

#ifndef __P
#ifdef __STDC__
#define __P(args) args
#else
#define __P(args) ()
#endif
#endif

const char     *tcpremoteip __P((int));

#endif

