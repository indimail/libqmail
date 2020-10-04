/*
 * $Log: fmt_tohex.c,v $
 * Revision 1.1  2020-07-01 12:12:42+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

char
fmt_tohex(char c)
{
    return (char) (c >= 10 ? c - 10 + 'a' : c + '0');
}

void
getversion_fmt_tohex_c()
{
	static char    *x = "$Id: fmt_tohex.c,v 1.1 2020-07-01 12:12:42+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
