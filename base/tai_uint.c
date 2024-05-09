/*
 * $Log: tai_uint.c,v $
 * Revision 1.2  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.1  2020-11-21 21:50:38+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "tai.h"

void tai_uint(struct tai *t,unsigned int u)
{
  t->x = u;
}

void
getversion_tai_uint_c()
{
	const char     *x = "$Id: tai_uint.c,v 1.2 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
