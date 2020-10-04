/*
 * $Log: in_crypt.c,v $
 * Revision 1.1  2020-04-01 18:09:38+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#define _XOPEN_SOURCE
#include <unistd.h>
#ifdef HAVE_CRYPT_H
#include <crypt.h>
#else
char           *crypt(const char *, const char *);
#endif

#include "getEnvConfig.h"
#include "in_crypt.h"

/*
 * UNIX password
 */
char           *
in_crypt(const char *pw, const char *salt)
{
	int             passwd_hash;

	getEnvConfigInt(&passwd_hash, "PASSWORD_HASH", PASSWORD_HASH);
	switch (passwd_hash)
	{
	case DES_HASH:
		return (crypt(pw, salt));
		break;
	case MD5_HASH:
#ifdef ENABLE_MD5_CRYPT
		return (md5_crypt(pw, salt));
#endif
		break;
	case SHA256_HASH:
#ifdef ENABLE_SHA256_CRYPT
		return (sha256_crypt(pw, salt));
#endif
		break;
	case SHA512_HASH:
#ifdef ENABLE_SHA512_CRYPT
		return (sha512_crypt(pw, salt));
#endif
		break;
	}
	return (crypt(pw, salt));
}

void
getversion_in_crypt_c()
{
	static char    *x = "$Id: in_crypt.c,v 1.1 2020-04-01 18:09:38+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
