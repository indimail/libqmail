/*
 * $Log: fmt_strn.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2020-11-24 09:32:06+05:30  Cprogrammer
 * use const keyword for readonly arguments
 *
 * Revision 1.3  2004-10-22 20:25:17+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:18:53+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "fmt.h"

unsigned int
fmt_strn(register char *s, register const char *t, register unsigned int n)
{
	register unsigned int len;
	char            ch;
	len = 0;
	if (s)
	{
		while (n-- && (ch = t[len]))
			s[len++] = ch;
	} else
		while (n-- && t[len])
			len++;
	return len;
}

void
getversion_fmt_strn_c()
{
	const char     *x = "$Id: fmt_strn.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
