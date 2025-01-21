/*
 * $Log: env.c,v $
 * Revision 1.12  2025-01-21 22:19:14+05:30  Cprogrammer
 * fixes for gcc14
 *
 * Revision 1.11  2024-05-12 00:10:20+05:30  mbhangui
 * fix function prototypes
 *
 * Revision 1.10  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.9  2022-01-30 19:35:38+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.8  2021-06-10 10:50:09+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.7  2020-11-22 23:51:11+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.6  2020-05-15 11:30:41+05:30  Cprogrammer
 * convert function prototypes to c89 standards
 * fix possible integer overflow
 *
 * Revision 1.5  2009-05-03 22:42:42+05:30  Cprogrammer
 * simplified restore_env()
 *
 * Revision 1.4  2004-10-22 20:24:47+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-09-25 23:59:37+05:30  Cprogrammer
 * BUG fix. set env_isnit to zero in restore_env()
 *
 * Revision 1.2  2004-07-17 21:18:30+05:30  Cprogrammer
 * added RCS log
 *
 *
 * env.c, envread.c, env.h: environ library
 * Daniel J. Bernstein, djb@silverton.berkeley.edu.
 * Depends on str.h, alloc.h, env.h, builtinoflmacros.h.
 * Requires environ.
 * 19960113: rewrite. warning: interface is different.
 * No known patent problems.
 */

#include "str.h"
#include "alloc.h"
#include "env.h"
#include "error.h"
#include "builtinoflmacros.h"

int             env_isinit = 0;	/*- if env_isinit: */
static int      ea;				/*- environ is a pointer to ea+1 char*'s.  */
static int      en;				/*- the first en of those are ALLOCATED. environ[en] is 0.  */
static char   **origenv;        /*- points to pristine original environment */

static void
env_goodbye(int i)
{
	alloc_free(environ[i]);
	environ[i] = environ[--en];
	environ[en] = 0;
}

static char    *null = 0;

void
env_clear()
{
	if (env_isinit) {
		while (en)
			env_goodbye(0);
		alloc_free((char *) environ);
		ea = en = env_isinit = 0;
	} else
		environ = &null;
}

static void
env_unsetlen(const char *s, int len)
{
	int             i;

	for (i = en - 1; i >= 0; --i) {
		if (!str_diffn(s, environ[i], len) && environ[i][len] == '=')
			env_goodbye(i);
	}
}

int
env_unset(const char *s)
{
	if (!env_isinit && !env_init())
		return 0;
	env_unsetlen(s, str_len(s));
	return 1;
}

static int
env_add(const char *s)
{
	const char     *t;
	unsigned int    i;

	if ((t = env_findeq(s)))
		env_unsetlen(s, t - s);
	if (en == ea) {
		/*- 
		 * we add one extra to ea to avoid overflow check again
		 * while calling alloc()
		 */
		if (__builtin_add_overflow(ea, 30+1, &i)) {
			errno = error_nomem;
			return 0;
		}
		ea = i - 1; /*- substract the one extra added above */
		/*-
		 * no overflow check for en +1 as it would have succeeded in an
		 * earlier call to alloc()
		 */
		if (!alloc_re((void **) &environ, (en + 1) * sizeof(char *), i * sizeof(char *))) {
			ea = en;
			return 0;
		}
	}
	environ[en++] = (char *) s;
	environ[en] = 0;
	return 1;
}

int
env_put(const char *s)
{
	char           *u;
	unsigned int    i;

	if (!env_isinit && !env_init())
		return 0;
	if (__builtin_add_overflow(str_len(s), 1, &i)) {
		errno = error_nomem;
		return 0;
	}
	if (!(u = alloc(i)))
		return 0;
	str_copy(u, s);
	if (!env_add(u)) {
		alloc_free(u);
		return 0;
	}
	return 1;
}

int
env_put2(const char *s, const char *t)
{
	char           *u;
	unsigned int    slen, i;

	if (!env_isinit && !env_init())
		return 0;
	slen = str_len(s);
	if (__builtin_add_overflow(slen, str_len(t), &i)) {
		errno = error_nomem;
		return 0;
	}
	if (__builtin_add_overflow(i, 2, &i)) {
		errno = error_nomem;
		return 0;
	}
	if (!(u = alloc(i)))
		return 0;
	str_copy(u, s);
	u[slen] = '=';
	/*- 
	 * overflow cannot happen in slen+1 as above builtin
	 * overflow checks succeeded
	 */
	str_copy(u + slen + 1, t);
	if (!env_add(u)) {
		alloc_free(u);
		return 0;
	}
	return 1;
}

int
env_init()
{
	char          **newenviron;
	unsigned int    i;

	for (en = 0; environ[en]; ++en);
	/*- 
	 * we add one extra to ea to avoid overflow check again
	 * while calling alloc()
	 */
	if (__builtin_add_overflow(en, 10+1, &i)) {
		errno = error_nomem;
		return 0;
	}
	ea = i - 1; /*- substract the one extra added above */
	if (!(newenviron = (char **) alloc(i * sizeof(char *))))
		return 0;
	for (en = 0; environ[en]; ++en) {
		if (__builtin_add_overflow(str_len(environ[en]), 1, &i)) {
			errno = error_nomem;
			return 0;
		}
		if (!(newenviron[en] = alloc(i))) {
			for (i = 0; i < en; ++i)
				alloc_free(newenviron[i]);
			alloc_free((char *) newenviron);
			return 0;
		}
		str_copy(newenviron[en], environ[en]);
	}
	newenviron[en] = 0;
	if (!origenv)
		origenv = environ; /*- the pristine environment */
	environ = newenviron;
	env_isinit = 1;
	return 1;
}

void
restore_env()
{
	if (origenv) {
		env_clear();
		environ = origenv;
		origenv = 0;
	}
	return;
}

void
getversion_env_c()
{
	const char     *x = "$Id: env.c,v 1.12 2025-01-21 22:19:14+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
