/*
 * $Log: fmt_str.c,v $
 * Revision 1.6  2020-11-24 09:32:01+05:30  Cprogrammer
 * use const keyword for readonly arguments
 *
 * Revision 1.5  2004-10-22 20:32:37+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.4  2004-07-17 21:18:52+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "fmt.h"

unsigned int
fmt_str(register char *s, register const char *t)
{
	register unsigned int len;
	char            ch;

	len = 0;
	if (s)
	{
		while ((ch = t[len]))
			s[len++] = ch;
	} else
	{
		while (t[len])
			len++;
	}
	return len;
}

void
getversion_fmt_str_c()
{
	const char     *x = "$Id: fmt_str.c,v 1.6 2020-11-24 09:32:01+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
