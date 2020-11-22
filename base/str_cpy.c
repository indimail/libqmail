/*
 * $Log: str_cpy.c,v $
 * Revision 1.4  2020-11-22 23:53:20+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2004-10-22 20:30:55+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:13+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "str.h"

unsigned int
str_copy(register char *to, register const char *from)
{
	register int    len;

	len = 0;
	for (;;)
	{
		if (!(*to = *from))
			return len;
		++to;
		++from;
		++len;
		if (!(*to = *from))
			return len;
		++to;
		++from;
		++len;
		if (!(*to = *from))
			return len;
		++to;
		++from;
		++len;
		if (!(*to = *from))
			return len;
		++to;
		++from;
		++len;
	}
}

void
getversion_str_cpy_c()
{
	static char    *x = "$Id: str_cpy.c,v 1.4 2020-11-22 23:53:20+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
