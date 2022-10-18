/*
 * $Log: fmt_uint.c,v $
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:25:21+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:18:57+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "fmt.h"

unsigned int
fmt_uint(register char *s, register unsigned int u)
{
	register unsigned long l;
	l = u;
	return fmt_ulong(s, l);
}

void
getversion_fmt_uint_c()
{
	static char    *x = "$Id: fmt_uint.c,v 1.4 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
