/*
 * $Log: alloc_re.c,v $
 * Revision 1.7  2020-12-02 14:50:48+05:30  Cprogrammer
 * changed return type of alloc() to void *
 *
 * Revision 1.6  2020-10-18 09:28:24+05:30  Cprogrammer
 * fix overwriting unallocated memory location when new_size < old_size
 *
 * Revision 1.5  2004-10-22 20:18:06+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.4  2004-10-11 13:48:32+05:30  Cprogrammer
 * prevent inclusion of alloc.h with prototypes
 *
 * Revision 1.3  2004-07-17 21:14:39+05:30  Cprogrammer
 * added RCS log
 *
 */
#define _ALLOC_
#include "alloc.h"
#undef _ALLOC_
#include "byte.h"

int
alloc_re(x, old_size, new_size)
	void          **x;
	unsigned int    old_size;
	unsigned int    new_size;
{
	void           *y;

	if (old_size == new_size)
		return 1;
	if (!(y = alloc(new_size)))
		return 0;
	byte_copy(y, new_size < old_size ? new_size : old_size, *x);
	if (*x)
		alloc_free(*x);
	*x = y;
	return 1;
}

void
getversion_alloc_re_c()
{
	static char    *x = "$Id: alloc_re.c,v 1.7 2020-12-02 14:50:48+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
