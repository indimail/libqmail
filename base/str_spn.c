/*
 * $Id: str_spn.c,v 1.1 2023-12-22 18:36:10+05:30 Cprogrammer Exp mbhangui $
 */
#include <str.h>

/*
 * Span the string s2 (skip characters that are in s2).
 */
size_t
str_spn(const char *s1, register const char *s2)
{
	register const char *p = s1, *spanp;
	register char c, sc;

	/*
	 * Skip any characters in s2, excluding the terminating \0.
	 */
cont:
	c = *p++;
	for (spanp = s2; (sc = *spanp++) != 0;)
		if (sc == c)
			goto cont;
	return (p - 1 - s1);
}

void
getversion_str_spn_c()
{
	static char    *x = "$Id: str_spn.c,v 1.1 2023-12-22 18:36:10+05:30 Cprogrammer Exp mbhangui $";

	x++;
}

/*
 * $Log: str_spn.c,v $
 * Revision 1.1  2023-12-22 18:36:10+05:30  Cprogrammer
 * Initial revision
 *
 */
