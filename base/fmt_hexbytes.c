/*
 * $Log: fmt_hexbytes.c,v $
 * Revision 1.3  2020-08-03 18:12:21+05:30  Cprogrammer
 * added tohex() function
 *
 * Revision 1.2  2020-07-01 12:13:50+05:30  Cprogrammer
 * removed extra newline
 *
 * Revision 1.1  2015-08-24 19:03:00+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

unsigned int
fmt_hexbyte(char *s, unsigned char byte)
{
	static char     data[] = "0123456789abcdef";

	if (s)
	{
		*s++ = data[(byte >> 4) & 0xf];
		*s = data[byte & 0xf];
	}
	return 2;
}

char
tohex(char num)
{
	return (num < 10 ?  num + '0' : (num < 16 ?  num - 10 + 'a': -1));
}

void
getversion_fmt_hexbytes_c()
{
	const char     *x = "$Id: fmt_hexbytes.c,v 1.3 2020-08-03 18:12:21+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
