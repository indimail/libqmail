/*
 * $Log: fmt_int.c,v $
 * Revision 1.3  2019-07-18 10:08:02+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.2  2019-07-18 09:54:51+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:34:09+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

unsigned int fmt_int(char *dest, int i)
{
	if (i < 0) {
		if (dest)
			*dest++='-';
		return (fmt_uint(dest, (unsigned int) -i) + 1);
	} else
	return (fmt_uint(dest, (unsigned int) i));
}

void
getversion_fmt_int_c()
{
	static char    *x = "$Id: fmt_int.c,v 1.3 2019-07-18 10:08:02+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
