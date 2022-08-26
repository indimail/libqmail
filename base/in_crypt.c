/*
 * $Log: in_crypt.c,v $
 * Revision 1.2  2022-08-26 18:12:58+05:30  Cprogrammer
 * disregard PASSWORD_HASH if salt contains crypt(3) prefix
 *
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

#include "str.h"
#include "getEnvConfig.h"
#include "in_crypt.h"

/*
 * UNIX password
 */
char           *
in_crypt(const char *pw, const char *salt)
{
	int             passwd_hash;

	if (salt[0] == '$' && (salt[2] == '$' || salt[3] == '$' ||
				!str_diffn(salt, "$sha1", 5) || !str_diffn(salt, "$2b$", 4)
				|| !str_diffn(salt, "$md5", 4) )) { /* see crypt(5) */
		switch (salt[1] - '0')
		{
		case MD5_HASH:
			passwd_hash = MD5_HASH;
			break;
		case SHA256_HASH:
			passwd_hash = SHA256_HASH;
			break;
		case SHA512_HASH:
			passwd_hash = SHA512_HASH;
			break;
		default:
			return (crypt(pw, salt));
		}
	} else
		getEnvConfigInt(&passwd_hash, "PASSWORD_HASH", PASSWORD_HASH);
	switch (passwd_hash)
	{
	case MD5_HASH:
#ifdef ENABLE_MD5_CRYPT
		return (md5_crypt(pw, salt));
#endif
	case SHA256_HASH:
#ifdef ENABLE_SHA256_CRYPT
		return (sha256_crypt(pw, salt));
#endif
	case SHA512_HASH:
#ifdef ENABLE_SHA512_CRYPT
		return (sha512_crypt(pw, salt));
#endif
	}
	return (crypt(pw, salt));
}

void
getversion_in_crypt_c()
{
	static char    *x = "$Id: in_crypt.c,v 1.2 2022-08-26 18:12:58+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
