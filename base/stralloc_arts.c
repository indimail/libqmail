/*
 * $Log: stralloc_arts.c,v $
 * Revision 1.5  2020-11-22 23:52:45+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.4  2020-05-13 07:23:29+05:30  Cprogrammer
 * fix possible integer overflow
 *
 * Revision 1.3  2004-10-22 20:30:45+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:23:53+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "byte.h"
#include "str.h"
#include "stralloc.h"

int
stralloc_starts(stralloc *sa, const char *s)
{
	unsigned int    len;
	len = str_len(s);
	return (sa->len >= len) && byte_equal(s, len, sa->s);
}

void
getversion_stralloc_arts_c()
{
	const char     *x = "$Id: stralloc_arts.c,v 1.5 2020-11-22 23:52:45+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
