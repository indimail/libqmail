/*
 * $Log: str_chrn.c,v $
 * Revision 1.2  2020-11-22 23:53:12+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.1  2005-01-22 01:01:09+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "str.h"

/*
 * return pointer to string where
 * match occurs
 * return null if you reach null
 * or len bytes
 */
char           *
str_chrn(register const char *s, int c, int len)
{
	register char   ch;
	register char  *t;

	ch = c;
	t = s;
	while (len > 0)
	{
		if (!*t)
			return ((char *) 0);
		if (*t == ch)
			break;
		--len;
		++t;
	}
	if (!len)
		return ((char *) 0);
	else
		return (s + (t - s));
}

void
getversion_str_chrn_c()
{
	static char    *x = "$Id: str_chrn.c,v 1.2 2020-11-22 23:53:12+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
