#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_TIME_H
#include <time.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_CRYPT_H
#include <crypt.h>
#endif
#include "str.h"
#include "alloc.h"
#include "getEnvConfig.h"
#ifndef HAVE_ARC4RANDOM
#include "arc4random.h"
#endif

static char     itoa64[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./";
char            pchars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz~!@#$%^&*_-+=`|\(){}[]:;\"'<>,.?/)";

char           *
genpass(int len)
{
	int             i, slen;
	char           *pwtmp;
	uint32_t        u;

	if (!(pwtmp = alloc(len + 1)))
		return ((char *) 0);
	/*- generate an alpha-numeric character as the first char */
#ifndef HAVE_ARC4RANDOM
		if (!(u = arc4random()))
			return ((char *) 0);
#else
		u = arc4random();
#endif
	pwtmp[0] = pchars[u % 62]; /*- alphanumeric chars from pchars */

	slen = str_len(pchars);
	for (i = 1; i < len; i++) {
#ifndef HAVE_ARC4RANDOM
		if (!(u = arc4random()))
			return ((char *) 0);
#else
		u = arc4random();
#endif
		pwtmp[i] = pchars[u % slen];
	}
	pwtmp[i] = '\0';
	return (pwtmp);
}

/*-
 * Salt suitable for traditional DES or MD5, SHA256, SHA512
 */
int
makesalt(char *salt, int n)
{
	int             i, len, new, passwd_hash;
	uint32_t        u;
#ifdef HAVE_CRYPT_GENSALT
	int             ylen = 16;
#endif

	getEnvConfigInt(&passwd_hash, "PASSWORD_HASH", PASSWORD_HASH);
	i = 0;
	new = n;
	switch (passwd_hash)
	{
	case DES_HASH: /*- 2 bytes salt DES_HASH=0 */
		i = 0;
		new = 2;
		if (n < new + 1)
			return -1;
		break;
	case MD5_HASH: /*- 8 bytes salt MD5_HASH=1 */
		salt[i++] = '$';
		salt[i++] = '1';
		salt[i++] = '$';
		new = 8 + i;
		if (n < new + 2)
			return -1;
		break;
	case SHA256_HASH: /*- 16 bytes salt SHA256_HASH=2 */
		salt[i++] = '$';
		salt[i++] = '5';
		salt[i++] = '$';
		new = 16 + i;
		if (n < new + 2)
			return -1;
		break;
	case SHA512_HASH: /*- 16 bytes salt SHA512_HASH=3 */
		salt[i++] = '$';
		salt[i++] = '6';
		salt[i++] = '$';
		new = 16 + i;
		if (n < new + 2)
			return -1;
		break;
	case YESCRYPT_HASH: /*- 24 bytes salt YESCRYPT_HASH=4 */
#ifdef HAVE_CRYPT_GENSALT
		new = ylen;
		if (n < new + 2)
			return -1;
#else
		salt[i++] = '$';
		salt[i++] = 'y';
		salt[i++] = '$';
		salt[i++] = 'j';
		salt[i++] = '9';
		salt[i++] = 'T';
		salt[i++] = '$';
		new = 24 + i;
		if (n < new + 2)
			return -1;
#endif
		break;
	default: /*- 16 bytes salt */
		salt[i++] = '$';
		salt[i++] = '6';
		salt[i++] = '$';
		new = 16 + i;
		if (n < new + 2)
			return -1;
		break;
	}
	for (len = str_len(itoa64); i < new; i++) {
#ifndef HAVE_ARC4RANDOM
		if (!(u = arc4random()))
			return -1;
#else
		u = arc4random();
#endif
		salt[i] = itoa64[u % len]; /* generate random no from 0 to len */
	}
#ifdef HAVE_CRYPT_GENSALT
	if (passwd_hash == YESCRYPT_HASH) {
		char           *ptr;
		if (!(ptr = crypt_gensalt("$y$", 5, salt, ylen)))
			return -1;
		for (i = 0; *ptr; i++)
			salt[i] = *ptr++;
	}
#endif
	if (salt[0] == '$')
		salt[i++] = '$';
	salt[i] = '\0';
	return 0;
}

void
getversion_makesalt_c()
{
	const char     *x = "$Id: makesalt.c,v 1.10 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}

/*
 * $Log: makesalt.c,v $
 * Revision 1.10  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.9  2023-07-16 13:49:56+05:30  Cprogrammer
 * use crypt_gensalt if available to generate salt for yescrypt
 *
 * Revision 1.8  2022-08-28 17:28:31+05:30  Cprogrammer
 * return -1 for insufficient length
 *
 * Revision 1.7  2022-08-28 10:56:39+05:30  Cprogrammer
 * add missing terminating '$' character for salt
 *
 * Revision 1.6  2022-08-26 18:25:51+05:30  Cprogrammer
 * added additional characters to random generated passwords
 *
 * Revision 1.5  2022-08-24 15:34:52+05:30  Cprogrammer
 * changed default hash method to SHA256
 *
 * Revision 1.4  2022-08-03 17:08:46+05:30  Cprogrammer
 * include stdint.h for uint32_t
 *
 * Revision 1.3  2022-04-17 08:25:32+05:30  Cprogrammer
 * added arc4random() functions for systems missing it
 *
 * Revision 1.2  2020-10-04 16:47:47+05:30  Cprogrammer
 * combined duplicate cases in switch
 *
 * Revision 1.1  2020-04-01 18:14:20+05:30  Cprogrammer
 * Initial revision
 *
 */
