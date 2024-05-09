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
#include "strmsg.h"

void
strmsg_out(c_char *x1, c_char *x2, c_char *x3, c_char *x4, c_char *x5, c_char *x6,
		c_char *x7, c_char *x8, c_char *x9, c_char *x10, c_char *x11, c_char *x12,
		c_char *x13, c_char *x14, c_char *x15, c_char *x16)
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
	const char     *x = "$Id: strmsg_out.c,v 1.5 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
