/*
 * $Log: scan_to_sa.c,v $
 * Revision 1.1  2020-09-30 09:17:54+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "str.h"
#include "stralloc.h"
#include "textcode.h"

size_t
scan_to_sa(size_t (*func)(const char *, char *, size_t *), const char *src, stralloc * sa)
{
	size_t          written, r;

	if (!stralloc_readyplus(sa, str_len((char *) src)))
		return 0;
	if ((r = func(src, sa->s + sa->len, &written)))
		sa->len += written;
	return r;
}

void
getversion_scan_to_sa_c()
{
	const char     *x = "$Id: scan_to_sa.c,v 1.1 2020-09-30 09:17:54+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
