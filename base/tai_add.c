/*
 * $Log: tai_add.c,v $
 * Revision 1.2  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.1  2020-11-21 21:50:37+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "tai.h"

void tai_add(struct tai *t,const struct tai *u,const struct tai *v)
{
  t->x = u->x + v->x;
}

void
getversion_tai_add_c()
{
	const char     *x = "$Id: tai_add.c,v 1.2 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
