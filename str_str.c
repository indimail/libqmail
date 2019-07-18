/*
 * $Log: str_str.c,v $
 * Revision 1.3  2019-07-18 10:09:22+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.2  2019-07-18 09:55:56+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:42:45+05:30  Cprogrammer
 * Initial revision
 *
 *
 * strstr -- locate first occurence of a substring 
 *
 * Locates the first occurrence in the string pointed to by S1 of the string
 * pointed to by S2.  Returns a pointer to the substring found, or a NULL
 * pointer if not found.  If S2 points to a string with zero length, the
 * function returns S1. 
 *
 * For license terms, see the file COPYING in this directory.
 */

char           *
str_str(register char *buf, register char *sub)
{
	register char  *bp;

	if (!*sub)
		return buf;
	for (;;) {
		if (!*buf)
			break;
		bp = buf;
		for (;;) {
			if (!*sub)
				return buf;
			if (*bp++ != *sub++)
				break;
		}
		sub -= (unsigned long) bp;
		sub += (unsigned long) buf;
		buf += 1;
	}
	return 0;
}

void
getversion_str_str_c()
{
	static char    *x = "$Id: str_str.c,v 1.3 2019-07-18 10:09:22+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
