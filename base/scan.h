/*
 * $Log: scan.h,v $
 * Revision 1.9  2020-11-22 23:52:02+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.8  2020-07-23 11:27:48+05:30  Cprogrammer
 * added scan_double(), scan_hexdump() prototyps
 *
 * Revision 1.7  2020-07-01 12:14:40+05:30  Cprogrammer
 * added scan_fromhex()
 *
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#include <sys/types.h>
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

unsigned int    scan_uint(const char *, unsigned int *);
unsigned int    scan_ushort(const char *, unsigned short *);
unsigned int    scan_ulong(const char *, unsigned long *);
unsigned int    scan_ulonglong(const char *, unsigned long long *);
unsigned int    scan_xlong(const char *, unsigned long *);
unsigned int    scan_long(const char *, long *);
unsigned int    scan_8long(const char *, unsigned long *);
unsigned int    scan_int(const char *, int *);
unsigned int    scan_plusminus(const char *, int *);
int             scan_fromhex(unsigned char c);
unsigned int    scan_double(const char *, double *);
size_t          scan_hexdump(const char *, char *, size_t *);

#endif
