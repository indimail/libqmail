/* $Id: pathexec_env.c,v 1.8 2024-11-13 09:02:54+05:30 Cprogrammer Exp mbhangui $ */
#include "stralloc.h"
#include "alloc.h"
#include "str.h"
#include "byte.h"
#include "env.h"
#include "pathexec.h"

static stralloc plus, tmp;

int
pathexec_env(const char *s, const char *t)
{
	if (!s)
		return 1;
	if (!stralloc_copys(&tmp, s))
		return 0;
	if (t) {
		if (!stralloc_cats(&tmp, "="))
			return 0;
		if (!stralloc_cats(&tmp, t))
			return 0;
	}
	if (!stralloc_0(&tmp))
		return 0;
	/*- append value to plus with null as separator */
	return stralloc_cat(&plus, &tmp);
}

void
pathexec_clear()
{
	plus.len = 0;
}

/*- execute command with a new environ */
char **
pathexec(char **argv)
{
	char          **e;
	unsigned int    elen, i, j, split, t;

	if (!stralloc_cats(&plus, ""))
		return ((char **) 0);
	elen = 0;
	for (i = 0; environ[i]; ++i) /*- existing environ size */
		++elen;
	for (i = 0; i < plus.len; ++i) /*- additional environment variables to be added */
		if (!plus.s[i])
			++elen;
	if (!(e = (char **) alloc((elen + 1) * sizeof(char *))))
		return ((char **) 0);
	elen = 0;
	/*- copy all existing environment variables */
	for (i = 0; environ[i]; ++i)
		e[elen++] = environ[i];
	j = 0;
	for (i = 0; i < plus.len; ++i) {
		if (!plus.s[i]) {
			split = str_chr(plus.s + j, '=');
			for (t = 0; t < elen; ++t) {
				/*- compare if an env variable in plus matches env variable in
				 * environment & move the last element to current position
				 * and decrease environment list size by 1
				 */
				if (byte_equal(plus.s + j, split, e[t]) && e[t][split] == '=') {
					--elen;
					e[t] = e[elen];
					break;
				}
			}
			/*- if env variable has a value, append the env variable in plus */
			if (plus.s[j + split])
				e[elen++] = plus.s + j;
			j = i + 1;
		}
	}
	e[elen] = 0;
	if (argv)
		pathexec_run(*argv, argv, e);
	return (e);
}

int
pathexec_env_plus(const char *var, int len)
{
	unsigned int    i, j;

	if (!stralloc_cats(&plus, ""))
		return -6;
	j = 0;
	for (i = 0; i < plus.len; ++i) {
		if (!plus.s[i]) {
			if (byte_equal(plus.s + j, len, var)) {
				if (!env_put2(var, plus.s + j + 5))
					return -6;
			}
			j = i + 1;
		}
	}
	plus.len--;
	return 0;
}

void
getversion_pathexec_env_c()
{
	const char     *x = "$Id: pathexec_env.c,v 1.8 2024-11-13 09:02:54+05:30 Cprogrammer Exp mbhangui $";

	x++;
}

/*
 * $Log: pathexec_env.c,v $
 * Revision 1.8  2024-11-13 09:02:54+05:30  Cprogrammer
 * added pathexec_env_plus() to add env variables from plus variable
 *
 * Revision 1.7  2024-05-09 23:46:54+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.6  2021-07-14 09:38:47+05:30  Cprogrammer
 * added pathexec_clear() to clear new env variables added
 *
 * Revision 1.5  2020-04-04 09:46:18+05:30  Cprogrammer
 * added code documentation
 *
 * Revision 1.4  2011-05-07 15:58:21+05:30  Cprogrammer
 * removed unused variable
 *
 * Revision 1.3  2010-06-08 21:59:53+05:30  Cprogrammer
 * return allocated environment variable
 *
 * Revision 1.2  2004-10-22 20:27:54+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-07-17 20:57:35+05:30  Cprogrammer
 * Initial revision
 *
 */
