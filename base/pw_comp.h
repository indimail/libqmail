/*
 * $Log: pw_comp.h,v $
 * Revision 1.3  2022-08-27 09:04:18+05:30  Cprogrammer
 * removed AUTH methods definition as they are defined in authmethods.h
 *
 * Revision 1.2  2021-06-16 17:37:06+05:30  Cprogrammer
 * added hmac_sha224, hmac_sha384 functions
 *
 * Revision 1.1  2020-04-01 18:15:57+05:30  Cprogrammer
 * Initial revision
 *
 * Revision 1.1  2019-04-13 23:39:27+05:30  Cprogrammer
 * pw_comp.h
 *
 */
#ifndef PW_COMP_H
#define PW_COMP_H

int             pw_comp(unsigned char *, unsigned char *, unsigned char *, unsigned char *, int);

#endif
