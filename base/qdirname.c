/*
 * $Log: qdirname.c,v $
 * Revision 1.3  2024-05-17 16:13:00+05:30  Cprogrammer
 * fix discarded-qualifier-warnings
 *
 * Revision 1.2  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.1  2022-05-10 19:49:09+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include "stralloc.h"
#include "strerr.h"
#include "str.h"

#ifndef	lint
const char      sccsid[] = "$Id: qdirname.c,v 1.3 2024-05-17 16:13:00+05:30 Cprogrammer Exp mbhangui $"
#endif

static void
die_nomem()
{
	strerr_warn1("qdirname: out of memory", 0);
	_exit(111);
}

char           *
qdirname(const char *path)
{
	static stralloc tmpbuf = {0};
	int             i;

	if (!path || !*path)
		return ((char *) 0);
	if (!stralloc_copys(&tmpbuf, path) || !stralloc_0(&tmpbuf))
		die_nomem();
	i = str_rchr(tmpbuf.s, '/');
	if (tmpbuf.s[i]) {
		if (!i)
			return ((char *) "/");
		tmpbuf.s[i] = 0;
		return (tmpbuf.s);
	} else
		return ((char *) 0);
}

void
getversion_qdirname_c()
{
	const char     *x = "$Id: qdirname.c,v 1.3 2024-05-17 16:13:00+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
