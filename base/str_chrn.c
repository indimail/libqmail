/*
 * $Log: str_chrn.c,v $
 * Revision 1.5  2022-01-30 19:36:14+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.4  2021-07-15 09:54:25+05:30  Cprogrammer
 * use const char * for str
 *
 * Revision 1.3  2021-06-10 10:50:24+05:30  Cprogrammer
 * fixed compiler warning
 *
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
	t = (char *) s;
	while (len > 0) {
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
		return ((char *) (s + (t - s)));
}

void
getversion_str_chrn_c()
{
	const char     *x = "$Id: str_chrn.c,v 1.5 2022-01-30 19:36:14+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
