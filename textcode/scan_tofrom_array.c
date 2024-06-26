/*
 * $Log: scan_tofrom_array.c,v $
 * Revision 1.1  2020-09-30 09:17:54+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "str.h"
#include "array.h"
#include "textcode.h"

size_t
scan_tofrom_array(size_t (*func)(const char *, char *, size_t *), array * src, array * dest)
{
	size_t          scanned, needed;
	char           *x;

	array_cat0(src);
	if (array_failed(src) || array_failed(dest))
		return 0;
	needed = array_bytes(src);
	x = ((char *) array_start(dest)) + array_bytes(dest);
	if (!array_allocate(dest, 1, array_bytes(dest) + needed - 1))
		return 0;
	needed = func(array_start(src), x, &scanned);
	array_truncate(src, 1, array_bytes(src) - 1);
	return needed;
}

void
getversion_scan_tofrom_array_c()
{
	const char     *x = "$Id: scan_tofrom_array.c,v 1.1 2020-09-30 09:17:54+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
