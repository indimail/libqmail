/*
 * $Log: makesalt.c,v $
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

/*
 * Salt suitable for traditional DES and MD5 
 */
int
makesalt(char *salt, int n)
{
	int             i, len, passwd_hash;
	uint32_t        u;

	getEnvConfigInt(&passwd_hash, "PASSWORD_HASH", PASSWORD_HASH);
	i = 0;
	switch (passwd_hash)
	{
	case DES_HASH:
		i = 0;
		break;
	case SHA256_HASH:
		salt[0] = '$';
		salt[1] = '5';
		salt[2] = '$';
		i = 3;
		break;
	case SHA512_HASH:
		salt[0] = '$';
		salt[1] = '6';
		salt[2] = '$';
		i = 3;
		break;
	case MD5_HASH:
		salt[0] = '$';
		salt[1] = '1';
		salt[2] = '$';
		i = 3;
		break;
	default:
		salt[0] = '$';
		salt[1] = '5';
		salt[2] = '$';
		i = 3;
		break;
	}
	for (len = str_len(itoa64); i < n; i++) {
#ifndef HAVE_ARC4RANDOM
		if (!(u = arc4random()))
			return -1;
#else
		u = arc4random();
#endif
		salt[i] = itoa64[u % len]; /* generate random no from 0 to len */
	}
	salt[i] = '\0';
	return 0;
}

void
getversion_makesalt_c()
{
	static char    *x = "$Id: makesalt.c,v 1.6 2022-08-26 18:25:51+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
