/*
 * $Log: makesalt.c,v $
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

char           *
genpass(int len)
{
	int             i, slen;
	char           *pwtmp;
	uint32_t        u;

	if (!(pwtmp = alloc(len + 1)))
		return ((char *) 0);
	slen = str_len(itoa64);
	for (i = 0; i < len; i++) {
#ifndef HAVE_ARC4RANDOM
		if (!(u = arc4random()))
			return ((char *) 0);
#else
		u = arc4random();
#endif
		pwtmp[i] = itoa64[u % slen];
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
	default:
	case MD5_HASH:
		salt[0] = '$';
		salt[1] = '1';
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
	static char    *x = "$Id: makesalt.c,v 1.3 2022-04-17 08:25:32+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
