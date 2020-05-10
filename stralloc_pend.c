/*
 * $Log: stralloc_pend.c,v $
 * Revision 1.4  2020-05-10 17:51:05+05:30  Cprogrammer
 * GEN_ALLOC refactoring (by Rolf Eike Beer) to fix memory overflow reported by Qualys Security Advisory
 *
 * Revision 1.3  2004-10-22 20:30:53+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:10+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "alloc.h"
#include "stralloc.h"
#include "gen_allocdefs.h"

GEN_ALLOC_append(stralloc, char, s, len, a, 30, stralloc_readyplus, stralloc_append)

void
getversion_stralloc_pend_c()
{
	static char    *x = "$Id: stralloc_pend.c,v 1.4 2020-05-10 17:51:05+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
