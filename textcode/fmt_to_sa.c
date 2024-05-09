/*
 * $Log: fmt_to_sa.c,v $
 * Revision 1.1  2020-09-30 09:16:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "stralloc.h"
#include "textcode.h"

int
fmt_to_sa(size_t (*func)(char *, const char *, size_t), stralloc * sa, const char *src, size_t len)
{
	size_t          needed = func(0, src, len);

	if (!stralloc_readyplus(sa, needed))
		return 0;
	func(sa->s + sa->len, src, len);
	sa->len += needed;
	return needed;
}

void
getversion_fmt_to_sa_c()
{
	const char     *x = "$Id: fmt_to_sa.c,v 1.1 2020-09-30 09:16:27+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
