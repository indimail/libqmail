/*
 * $Log: scan_to_array.c,v $
 * Revision 1.1  2020-09-30 09:17:54+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "str.h"
#include "array.h"
#include "textcode.h"

size_t
scan_to_array(size_t (*func)(const char *, char *, size_t *), const char *src, array * dest)
{
	size_t          scanned;
	size_t          needed = str_len((char *) src);
	char           *x = ((char *) array_start(dest)) + array_bytes(dest);

	if (!array_allocate(dest, 1, array_bytes(dest) + needed - 1))
		return 0;
	return func(src, x, &scanned);
}

void
getversion_scan_to_array_c()
{
	static char    *x = "$Id: scan_to_array.c,v 1.1 2020-09-30 09:17:54+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
