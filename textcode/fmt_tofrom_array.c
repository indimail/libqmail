/*
 * $Log: fmt_tofrom_array.c,v $
 * Revision 1.1  2020-09-30 09:16:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "array.h"
#include "textcode.h"

void
fmt_tofrom_array(size_t (*func)(char *, const char *, size_t), array * dest, array * src)
{
	size_t          needed;
	char           *x;

	if (array_failed(dest) || array_failed(src)) {
		array_fail(dest);
		return;
	}
	needed = func(0, array_start(src), array_bytes(src));
	if (array_bytes(dest) + needed > needed && array_allocate(dest, 1, array_bytes(dest) + needed - 1)) {
		x = ((char *) array_start(dest)) + array_bytes(dest) - needed;
		func(x, array_start(src), array_bytes(src));
	} else
		array_fail(dest);
}

void
getversion_fmt_tofrom_array_c()
{
	static char    *x = "$Id: fmt_tofrom_array.c,v 1.1 2020-09-30 09:16:27+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
