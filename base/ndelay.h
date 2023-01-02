/*
 * $Log: ndelay.h,v $
 * Revision 1.4  2023-01-02 20:33:59+05:30  Cprogrammer
 * added ndelay() function to get status of DELAY flag for descriptor
 *
 * Revision 1.3  2004-10-11 13:56:10+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 23:01:02+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef NDELAY_H
#define NDELAY_H

int             ndelay(int);
int             ndelay_on(int);
int             ndelay_off(int);

#endif
