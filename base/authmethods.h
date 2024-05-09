/*
 * $Log: authmethods.h,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2022-08-23 07:50:03+05:30  Cprogrammer
 * added get_authmethod() function
 *
 * Revision 1.2  2022-08-14 17:19:34+05:30  Cprogrammer
 * added AUTH_SCRAM_SHA1_PLUS, AUTH_SCRAM_SHA256_PLUS, AUTH_SCRAM_SHA512_PLUS auth methods
 *
 * Revision 1.1  2022-08-04 10:04:41+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef _AUTHMETHODS_H
#define _AUTHMETHODS_H

#define AUTH_LOGIN             1
#define AUTH_PLAIN             2
#define AUTH_CRAM_MD5          3
#define AUTH_CRAM_SHA1         4
#define AUTH_CRAM_SHA224       5
#define AUTH_CRAM_SHA256       6
#define AUTH_CRAM_SHA384       7
#define AUTH_CRAM_SHA512       8
#define AUTH_CRAM_RIPEMD       9
#define AUTH_DIGEST_MD5        10
#define AUTH_SCRAM_SHA1        11
#define AUTH_SCRAM_SHA256      12
#define AUTH_SCRAM_SHA512      13
#define AUTH_SCRAM_SHA1_PLUS   14
#define AUTH_SCRAM_SHA256_PLUS 15
#define AUTH_SCRAM_SHA512_PLUS 16

const char     *get_authmethod(int);

#endif
