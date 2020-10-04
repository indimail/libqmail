/*
 * $Log: makesalt.c,v $
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

int        Arc4random(int, int);

static char     itoa64[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./";

char           *
genpass(int len)
{
	int             i, slen;
	char           *pwtmp;

	if (!(pwtmp = alloc(len + 1)))
		return ((char *) 0);
	slen = str_len(itoa64) - 1;
	for (i = 0; i < len; i++)
		pwtmp[i] = itoa64[Arc4random(0, slen)];
	pwtmp[i] = '\0';
	return (pwtmp);
}

int
Arc4random(int start_num, int end_num)
{
	int             j;
	float           fnum;
	static int      seeded;

	if (!seeded) {
		seeded = 1;
		srand(time(0)^(getpid()<<15));
	}
	fnum = (float) end_num;
	j = start_num + (int) (fnum * rand() / (RAND_MAX + 1.0));
	return (j);
}

/*
 * Salt suitable for traditional DES and MD5 
 */
void
makesalt(char *salt, int n)
{
	int             i, len, passwd_hash;
	static int      seeded; /* 0 ... 63 => ascii - 64 */

	/*
	 * These are not really random numbers, they are just
	 * numbers that change to thwart construction of a
	 * dictionary. This is exposed to the public.
	 */
	if (!seeded) {
		seeded = 1;
		srand(time(0)^(getpid()<<15));
	}
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
	for (len = str_len(itoa64); i < n; i++)
		salt[i] = itoa64[Arc4random(0, len - 1)]; /* generate random no from 0 to len */
	salt[i] = '\0';
}

void
getversion_makesalt_c()
{
	static char    *x = "$Id: makesalt.c,v 1.2 2020-10-04 16:47:47+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
