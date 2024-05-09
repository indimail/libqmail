/*
 * $Log: isnum.c,v $
 * Revision 1.3  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
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
const char      sccsid[] = "$Id: isnum.c,v 1.3 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";
#endif

int
isnum(register const char *str)
{
	while (*str && isdigit(*str))
		str++;
	return *str ? 0 : 1;
}

void
getversion_isnum_c()
{
	const char     *x = "$Id: isnum.c,v 1.3 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
