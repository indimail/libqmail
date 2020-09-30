/*
 * $Log: fmt_to_array.c,v $
 * Revision 1.1  2020-09-30 09:16:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#include "textcode.h"

void
fmt_to_array(size_t (*func)(char *, const char *, size_t), array * a, const char *src, size_t len)
{
	size_t          needed = func(0, src, len);

	if (array_bytes(a) + needed >= needed && array_allocate(a, 1, array_bytes(a) + needed - 1)) {
		char           *x = ((char *) array_start(a)) + array_bytes(a) - needed;
		func(x, src, len);
	} else
		array_fail(a);
}

void
getversion_fmt_to_array_c()
{
	static char    *x = "$Id: fmt_to_array.c,v 1.1 2020-09-30 09:16:27+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
