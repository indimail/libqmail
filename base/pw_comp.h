/*
 * $Log: pw_comp.h,v $
 * Revision 1.1  2020-04-01 18:15:57+05:30  Cprogrammer
 * Initial revision
 *
 * Revision 1.1  2019-04-13 23:39:27+05:30  Cprogrammer
 * pw_comp.h
 *
 */
#ifndef PW_COMP_H
#define PW_COMP_H

#define AUTH_LOGIN       1
#define AUTH_PLAIN       2
#define AUTH_CRAM_MD5    3
#define AUTH_CRAM_SHA1   4
#define AUTH_CRAM_SHA256 5
#define AUTH_CRAM_SHA512 6
#define AUTH_CRAM_RIPEMD 7
#define AUTH_DIGEST_MD5  8

int             pw_comp(unsigned char *, unsigned char *, unsigned char *, unsigned char *, int);

#endif
