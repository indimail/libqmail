/*
 * $Log: scan.h,v $
 * Revision 1.6  2019-06-24 21:26:25+05:30  Cprogrammer
 * added scan_ulonglong, scan_plusminus prototypes
 *
 * Revision 1.5  2004-10-11 14:01:40+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.4  2004-06-18 23:01:43+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef SCAN_H
#define SCAN_H

unsigned int    scan_uint(char *, unsigned int *);
unsigned int    scan_ushort(char *, unsigned short *);
unsigned int    scan_ulong(char *, unsigned long *);
unsigned int    scan_ulonglong(char *, unsigned long long *);
unsigned int    scan_xlong(char *, unsigned long *);
unsigned int    scan_long(char *, long *);
unsigned int    scan_8long(char *, unsigned long *);
unsigned int    scan_int(char *, int *);
unsigned int    scan_plusminus(char *, int *);

#endif
