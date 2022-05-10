/*
 * $Log: qdirname.c,v $
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
static char     sccsid[] = "$Id: qdirname.c,v 1.1 2022-05-10 19:49:09+05:30 Cprogrammer Exp mbhangui $"
#endif

static void
die_nomem()
{
	strerr_warn1("qdirname: out of memory", 0);
	_exit(111);
}

char           *
qdirname(char *path)
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
			return ("/");
		tmpbuf.s[i] = 0;
		return (tmpbuf.s);
	} else
		return ((char *) 0);
}

void
getversion_qdirname_c()
{
	static char    *x = "$Id: qdirname.c,v 1.1 2022-05-10 19:49:09+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
