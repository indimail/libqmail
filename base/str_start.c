/*
 * $Log: str_start.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2020-11-22 23:53:53+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2004-10-22 20:31:02+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:25+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "str.h"

int
str_start(register const char *s, register const char *t)
{
	register char   x;

	for (;;) {
		x = *t++;
		if (!x)
			return 1;
		if (x != *s++)
			return 0;
		x = *t++;
		if (!x)
			return 1;
		if (x != *s++)
			return 0;
		x = *t++;
		if (!x)
			return 1;
		if (x != *s++)
			return 0;
		x = *t++;
		if (!x)
			return 1;
		if (x != *s++)
			return 0;
	}
}

void
getversion_str_start_c()
{
	const char     *x = "$Id: str_start.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
