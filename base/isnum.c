/*
 * $Log: isnum.c,v $
 * Revision 1.1  2022-05-10 19:49:13+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_CTYPE_H
#include <ctype.h>
#endif

#ifndef	lint
static char     sccsid[] = "$Id: isnum.c,v 1.1 2022-05-10 19:49:13+05:30 Cprogrammer Exp mbhangui $";
#endif

int
isnum(char *str)
{
	register char  *ptr;

	for (ptr = str; *ptr; ptr++)
		if (!isdigit((int) *ptr))
			return (0);
	return (1);
}

void
getversion_isnum_c()
{
	static char    *x = "$Id: isnum.c,v 1.1 2022-05-10 19:49:13+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
