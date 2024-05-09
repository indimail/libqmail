/*
 * $Log: str_end.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2022-01-30 19:36:20+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.2  2020-11-22 23:53:30+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.1  2016-02-08 18:27:16+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "str.h"

int
str_end(register const char *s, register const char *t)
{
	register char   x, y;
	register const char *z;

	for (y = *(z = t);;) {
		x = *s;
		y = *t;
		if (!x)
			break;
		if (!y)
			y = *(t = z);
		if (x != y) {
			s++;
			t = z;
			continue;
		} else {
			s++;
			t++;
		}
		if (!x)
			break;

		x = *s;
		y = *t;
		if (!x)
			break;
		if (!y)
			y = *(t = z);
		if (x != y) {
			s++;
			t = z;
			continue;
		} else {
			s++;
			t++;
		}
		if (!x)
			break;

		x = *s;
		y = *t;
		if (!x)
			break;
		if (!y)
			y = *(t = z);
		if (x != y) {
			s++;
			t = z;
			continue;
		} else {
			s++;
			t++;
		}
		if (!x)
			break;
	}
	return ((int) (unsigned int) (unsigned char) x) - ((int) (unsigned int) (unsigned char) *t);
}

void
getversion_str_end_c()
{
	const char     *x = "$Id: str_end.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
