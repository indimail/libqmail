/*
 * $Log: stralloc_pend.c,v $
 * Revision 1.6  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.5  2020-11-23 18:05:03+05:30  Cprogrammer
 * use const keyword for argument
 *
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

GEN_ALLOC_append(stralloc, const char, s, len, a, 30, stralloc_readyplus, stralloc_append)

void
getversion_stralloc_pend_c()
{
	const char     *x = "$Id: stralloc_pend.c,v 1.6 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
