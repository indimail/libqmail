/*
 * $Log: strerr_die.c,v $
 * Revision 1.9  2022-08-27 09:07:02+05:30  Cprogrammer
 * BUG: added missing substdio output for argument 16
 *
 * Revision 1.8  2021-08-24 11:16:41+05:30  Cprogrammer
 * added additional members to struct strerr
 * converted to ansic function prototypes
 *
 * Revision 1.7  2020-11-24 13:34:20+05:30  Cprogrammer
 * removed exit.h
 *
 * Revision 1.6  2020-11-22 23:53:35+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.5  2019-06-24 21:28:02+05:30  Cprogrammer
 * added 8 more arguments to strerr_warn(), strerr_die() functions
 *
 * Revision 1.4  2004-10-22 20:30:58+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-10-21 21:53:02+05:30  Cprogrammer
 * added two more string args to strerr_warn() and strerr_die()
 *
 * Revision 1.2  2004-07-17 21:24:18+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <unistd.h>
#include "substdio.h"
#include "subfd.h"
#include "strerr.h"

void
strerr_warn(const char *x1, const char *x2, const char *x3, const char *x4,
		const char *x5, const char *x6, const char *x7, const char *x8,
		const char *x9, const char *x10, const char *x11, const char *x12,
		const char *x13, const char *x14, const char *x15, const char *x16,
		struct strerr *se)
{
	strerr_sysinit();

	if (x1)
		substdio_puts(subfderr, x1);
	if (x2)
		substdio_puts(subfderr, x2);
	if (x3)
		substdio_puts(subfderr, x3);
	if (x4)
		substdio_puts(subfderr, x4);
	if (x5)
		substdio_puts(subfderr, x5);
	if (x6)
		substdio_puts(subfderr, x6);
	if (x7)
		substdio_puts(subfderr, x7);
	if (x8)
		substdio_puts(subfderr, x8);
	if (x9)
		substdio_puts(subfderr, x9);
	if (x10)
		substdio_puts(subfderr, x10);
	if (x11)
		substdio_puts(subfderr, x11);
	if (x12)
		substdio_puts(subfderr, x12);
	if (x13)
		substdio_puts(subfderr, x13);
	if (x14)
		substdio_puts(subfderr, x14);
	if (x15)
		substdio_puts(subfderr, x15);
	if (x16)
		substdio_puts(subfderr, x16);
	while (se) {
		if (se->v)
			substdio_puts(subfderr, se->v);
		if (se->w)
			substdio_puts(subfderr, se->w);
		if (se->x)
			substdio_puts(subfderr, se->x);
		if (se->y)
			substdio_puts(subfderr, se->y);
		if (se->z)
			substdio_puts(subfderr, se->z);
		se = se->who;
	}
	substdio_puts(subfderr, "\n");
	substdio_flush(subfderr);
}

void
strerr_die(int e, const char *x1, const char *x2, const char *x3, 
		const char *x4, const char *x5, const char *x6, const char *x7,
		const char *x8, const char *x9, const char *x10, const char *x11,
		const char *x12, const char *x13, const char *x14, const char *x15,
		const char *x16, struct strerr *se)
{
	strerr_warn(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, se);
	_exit(e);
}

void
getversion_strerr_die_c()
{
	const char     *x = "$Id: strerr_die.c,v 1.9 2022-08-27 09:07:02+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
