/*
 * $Log: fmt_ushort.c,v $
 * Revision 1.3  2020-10-01 13:30:31+05:30  Cprogrammer
 * changed function to c89 prototype to fix warning on Darwin (warning: promoted type 'int' of K&R function parameter is not compatible with the parameter type)
 *
 * Revision 1.2  2004-10-22 20:25:24+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-01-02 23:51:30+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

unsigned int
fmt_ushort(register char *s, register unsigned short u)
{
	register unsigned long l;
	l = u;
	return fmt_ulong(s, l);
}

void
getversion_fmt_ushort_c()
{
	const char     *x = "$Id: fmt_ushort.c,v 1.3 2020-10-01 13:30:31+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
