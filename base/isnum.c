/*
 * $Log: isnum.c,v $
 * Revision 1.2  2023-02-20 20:36:21+05:30  Cprogrammer
 * refactored isnum()
 *
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
static char     sccsid[] = "$Id: isnum.c,v 1.2 2023-02-20 20:36:21+05:30 Cprogrammer Exp mbhangui $";
#endif

int
isnum(register char *str)
{
	while (*str && isdigit(*str))
		str++;
	return *str ? 0 : 1;
}

void
getversion_isnum_c()
{
	static char    *x = "$Id: isnum.c,v 1.2 2023-02-20 20:36:21+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
