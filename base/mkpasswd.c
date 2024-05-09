/*
 * $Log: mkpasswd.c,v $
 * Revision 1.5  2023-07-15 08:39:39+05:30  Cprogrammer
 * allow storage space for salt to be dynamically allocated
 *
 * Revision 1.4  2022-08-28 10:57:10+05:30  Cprogrammer
 * allow variable salt size using environment variable SALTSIZE
 *
 * Revision 1.3  2022-08-05 17:27:25+05:30  Cprogrammer
 * encrypt when encrypt_flag is non-zero
 *
 * Revision 1.2  2022-04-17 08:21:17+05:30  Cprogrammer
 * removed setting 'seeded' variable
 *
 * Revision 1.1  2020-04-01 18:15:20+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_TIME_H
#include <time.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "str.h"
#include "strerr.h"
#include "stralloc.h"
#include "in_crypt.h"
#include "makesalt.h"
#include "getEnvConfig.h"

static void
die_nomem()
{
	strerr_warn1("mkpasswd: out of memory", 0);
	_exit(111);
}

/* encrypt a password */
int
mkpasswd(char *newpasswd, stralloc *crypted, int encrypt_flag)
{
	char           *tmpstr;
	static stralloc salt = {0};
	int             saltsize;

	getEnvConfigInt(&saltsize, "SALTSIZE", SALTSIZE);
	crypted->len = 0;
	if (encrypt_flag) {
		if (!stralloc_ready(&salt, saltsize + 1))
			die_nomem();
		makesalt(salt.s, saltsize);
		if (!(tmpstr = in_crypt(newpasswd, salt.s)))
			return (-1);
	} else
		tmpstr = newpasswd;
	if (!stralloc_copys(crypted, tmpstr) || !stralloc_0(crypted))
		die_nomem();
	crypted->len--;
	return (0);
}

void
getversion_mkpasswd_c()
{
	const char     *x = "$Id: mkpasswd.c,v 1.5 2023-07-15 08:39:39+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
