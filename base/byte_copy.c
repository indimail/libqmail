/*
 * $Log: byte_copy.c,v $
 * Revision 1.4  2020-11-22 23:48:56+05:30  Cprogrammer
 * changed argument to const char *
 *
 * Revision 1.3  2004-10-22 20:22:26+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:16:36+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "byte.h"

void
byte_copy(register char *to, register unsigned int n, register const char *from)
{
	for (;;) {
		if (!n)
			return;
		*to++ = *from++;
		--n;
		if (!n)
			return;
		*to++ = *from++;
		--n;
		if (!n)
			return;
		*to++ = *from++;
		--n;
		if (!n)
			return;
		*to++ = *from++;
		--n;
	}
}

void
getversion_byte_copy_c()
{
	const char     *x = "$Id: byte_copy.c,v 1.4 2020-11-22 23:48:56+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
