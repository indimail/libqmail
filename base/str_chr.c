/*
 * $Log: str_chr.c,v $
 * Revision 1.8  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.7  2022-01-30 19:36:04+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.6  2021-07-15 09:54:02+05:30  Cprogrammer
 * use const char * for str
 *
 * Revision 1.5  2021-06-10 10:50:18+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.4  2020-11-22 23:53:09+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2004-10-22 20:30:53+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:11+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "str.h"

unsigned int
str_chr(register const char *s, int c)
{
	register char   ch;
	register char  *t;

	ch = c;
	t = (char *) s;
	for (;;) {
		if (!*t)
			break;
		if (*t == ch)
			break;
		++t;
		if (!*t)
			break;
		if (*t == ch)
			break;
		++t;
		if (!*t)
			break;
		if (*t == ch)
			break;
		++t;
		if (!*t)
			break;
		if (*t == ch)
			break;
		++t;
	}
	return t - s;
}

void
getversion_str_chr_c()
{
	const char     *x = "$Id: str_chr.c,v 1.8 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
