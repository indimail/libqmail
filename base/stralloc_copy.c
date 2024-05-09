/*
 * $Log: stralloc_copy.c,v $
 * Revision 1.4  2020-11-22 23:52:57+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2004-10-22 20:30:48+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:02+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "byte.h"
#include "stralloc.h"

int
stralloc_copy(stralloc *sato, const stralloc *safrom)
{
	return stralloc_copyb(sato, safrom->s, safrom->len);
}

void
getversion_stralloc_copy_c()
{
	const char     *x = "$Id: stralloc_copy.c,v 1.4 2020-11-22 23:52:57+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
