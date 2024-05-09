/*
 * $Log: alloc.c,v $
 * Revision 1.9  2022-10-18 19:47:27+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.8  2020-12-02 14:50:28+05:30  Cprogrammer
 * changed return type to void *
 *
 * Revision 1.7  2020-05-11 19:14:07+05:30  Cprogrammer
 * use malloc instead of custom allocator for memory allocation >= 4096
 *
 * Revision 1.6  2010-03-22 09:20:31+05:30  Cprogrammer
 * add unsigned integer overflow check to alloc.c
 * Matthew Dempsky - http://marc.info/?l=qmail&m=125213850310173&w=2
 *
 * Revision 1.5  2008-08-03 18:23:51+05:30  Cprogrammer
 * use stdlib.h
 *
 * Revision 1.4  2004-12-20 22:55:46+05:30  Cprogrammer
 * change return type of malloc to void * (ansic)
 *
 * Revision 1.3  2004-10-22 20:17:04+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:14:26+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "alloc.h"
#include "error.h"
#include <stdlib.h>

#define ALIGNMENT 16			/*- XXX: assuming that this alignment is enough */
#define SPACE 4096				/*- must be multiple of ALIGNMENT */

typedef union
{
	char            irrelevant[ALIGNMENT];
	double          d;
} aligned;

static aligned  realspace[SPACE / ALIGNMENT];
#define space ((char *) realspace)
static unsigned int avail = SPACE;	/*- multiple of ALIGNMENT; 0<=avail<=SPACE */

/*@null@*//*@out@*/void *alloc(unsigned int n)
{
	char           *x;

	if (n >= SPACE) { /*- https://github.com/notqmail/notqmail/issues/112 */
		if (!(x = malloc(n)))
			errno = error_nomem;
		return x;
	}
	/*- Round it up to the next multiple of alignment. */
	if ((n = ALIGNMENT + n - (n & (ALIGNMENT - 1))) <= avail) {
		avail -= n;
		return space + avail;
	}
	if (!(x = malloc(n)))
		errno = error_nomem;
	return x;
}

void
alloc_free(char *x)
{
	if (x >= space && (x < space + SPACE))
		return; /*- XXX: assuming that pointers are flat */
	free(x);
}

void
getversion_alloc_c()
{
	const char     *x = "$Id: alloc.c,v 1.9 2022-10-18 19:47:27+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
