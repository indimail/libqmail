/*
 * $Log: in_crypt.h,v $
 * Revision 1.1  2020-04-01 18:10:14+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef IN_CRYPT_H
#define IN_CRYPT_H

char           *in_crypt(const char *, const char *);
#ifdef ENABLE_MD5_CRYPT
char           *md5_crypt(const char *, const char *);
#endif
#ifdef ENABLE_SHA256_CRYPT
char           *sha256_crypt(const char *, const char *);
#endif
#ifdef ENABLE_SHA512_CRYPT
char           *sha512_crypt(const char *, const char *);
#endif

#endif
