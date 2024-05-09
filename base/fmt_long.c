/*
 * $Log: fmt_long.c,v $
 * Revision 1.3  2019-07-18 10:08:13+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.2  2019-07-18 09:55:08+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:40:57+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

unsigned int fmt_long(char *dest, long int i)
{
	if (i < 0) {
		if (dest)
			*dest++='-';
		return (fmt_ulong(dest, (unsigned long) -i) + 1);
	} else
	return (fmt_ulong(dest, (unsigned long) i));
}

void
getversion_fmt_long_c()
{
	const char     *x = "$Id: fmt_long.c,v 1.3 2019-07-18 10:08:13+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
