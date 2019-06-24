/*
 * $Log: strerr_die.c,v $
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
#include "substdio.h"
#include "subfd.h"
#include "exit.h"
#include "strerr.h"

void
strerr_warn(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, se)
	char           *x1;
	char           *x2;
	char           *x3;
	char           *x4;
	char           *x5;
	char           *x6;
	char           *x7;
	char           *x8;
	char           *x9;
	char           *x10;
	char           *x11;
	char           *x12;
	char           *x13;
	char           *x14;
	char           *x15;
	char           *x16;
	struct strerr  *se;
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
	while (se) {
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
strerr_die(e, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, se)
	int             e;
	char           *x1;
	char           *x2;
	char           *x3;
	char           *x4;
	char           *x5;
	char           *x6;
	char           *x7;
	char           *x8;
	char           *x9;
	char           *x10;
	char           *x11;
	char           *x12;
	char           *x13;
	char           *x14;
	char           *x15;
	char           *x16;
	struct strerr  *se;
{
	strerr_warn(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, se);
	_exit(e);
}

void
getversion_strerr_die_c()
{
	static char    *x = "$Id: strerr_die.c,v 1.5 2019-06-24 21:28:02+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
