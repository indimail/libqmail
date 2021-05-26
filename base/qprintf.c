/*
 * $Log: qprintf.c,v $
 * Revision 1.4  2021-05-26 11:58:45+05:30  Cprogrammer
 * pad with zeros for numbers
 *
 * Revision 1.3  2019-07-18 10:08:45+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.2  2019-07-18 09:55:29+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:42:18+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "substdio.h"
#include "scan.h"
#include "str.h"
#include "strerr.h"

int
qprintf_flush(substdio *ss)
{
	if (substdio_flush(ss))
		strerr_die1x(111, "qprintf: unable to write output: ");
	return (0);
}

int
qprintf(substdio *ss, char *src, char *format_spec)
{
	register int    len = 0, todo;
	char           *delim = " ";
	int             i = -1, j;

	len = str_len(src);
	if (*format_spec != '%') {
		if (substdio_put(ss, src, len) == -1)
			strerr_die1x(111, "qprintf: unable to write output: ");
		return (0);
	}
	switch (*(format_spec + 1))
	{
	case '+':
		for (j = 1; format_spec[j]; j++) {
			if (format_spec[j] == 's') {
				delim = " ";
				break;
			} else
			if (format_spec[j] == 'd') {
				delim = "0";
				break;
			}
		}
		scan_int(format_spec + 2, &i);
		if ((todo = i - len) > 0) {
			for (; todo > 0; todo--) {
				if (substdio_put(ss, delim, 1) == -1)
					strerr_die1x(111, "qprintf: unable to write output: ");
			}
			if (substdio_put(ss, src, len) == -1)
				strerr_die1x(111, "qprintf: unable to write output: ");
			return (0);
		} else
			return (substdio_put(ss, src, len));
		break;
	case '-':
		scan_int(format_spec + 2, &i);
	default:
		if (i == -1)
			scan_int(format_spec + 1, &i);
		for (j = 1; format_spec[j]; j++) {
			if (format_spec[j] == 's') {
				delim = " ";
				break;
			} else
			if (format_spec[j] == 'd') {
				delim = "0";
				break;
			}
		}
		if (len < i) {
			if (substdio_put(ss, src, len) == -1)
				strerr_die1x(111, "qprintf: unable to write output: ");
			for (todo = i - len; todo; todo--) {
				if (substdio_put(ss, delim, 1) == -1)
					strerr_die1x(111, "qprintf: unable to write output: ");
			}
			return (0);
		} else {
			if (substdio_put(ss, src, len) == -1)
				strerr_die1x(111, "qprintf: unable to write output: ");
			return (0);
		}
		break;
	}
}
void
getversion_qprintf_c()
{
	static char    *x = "$Id: qprintf.c,v 1.4 2021-05-26 11:58:45+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
