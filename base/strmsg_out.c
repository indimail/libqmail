/*
 * $Log: strmsg_out.c,v $
 * Revision 1.5  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.4  2020-11-24 13:35:30+05:30  Cprogrammer
 * removed exit.h
 *
 * Revision 1.3  2019-07-18 10:13:45+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.2  2019-07-18 09:55:53+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:42:42+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "substdio.h"
#include "subfd.h"

void
strmsg_out(char *x1, char *x2, char *x3, char *x4, char *x5, char *x6,
		char *x7, char *x8, char *x9, char *x10, char *x11, char *x12,
		char *x13, char *x14, char *x15, char *x16)
{
	if (x1)
		substdio_puts(subfdout, x1);
	if (x2)
		substdio_puts(subfdout, x2);
	if (x3)
		substdio_puts(subfdout, x3);
	if (x4)
		substdio_puts(subfdout, x4);
	if (x5)
		substdio_puts(subfdout, x5);
	if (x6)
		substdio_puts(subfdout, x6);
	if (x7)
		substdio_puts(subfdout, x7);
	if (x8)
		substdio_puts(subfdout, x8);
	if (x9)
		substdio_puts(subfdout, x9);
	if (x10)
		substdio_puts(subfdout, x10);
	if (x11)
		substdio_puts(subfdout, x11);
	if (x12)
		substdio_puts(subfdout, x12);
	if (x13)
		substdio_puts(subfdout, x13);
	if (x14)
		substdio_puts(subfdout, x14);
	if (x15)
		substdio_puts(subfdout, x15);
	substdio_flush(subfdout);
}

void
getversion_strmsg_out_c()
{
	static char    *x = "$Id: strmsg_out.c,v 1.5 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
