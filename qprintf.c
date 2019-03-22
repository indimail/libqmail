/*
 * $Log: $
 */
#include "substdio.h"
#include "subfd.h"
#include "scan.h"
#include "str.h"
#include "strerr.h"

int
qprintf(char *src, char *format_spec)
{
	register int    len = 0, todo;
	int             i = -1;

	len = str_len(src);
	if (*format_spec != '%')
		return (substdio_put(subfdoutsmall, src, len));
	switch (*(format_spec + 1))
	{
	case '+':
		scan_int(format_spec + 2, &i);
		if ((todo = i - len) > 0) {
			for (; todo > 0; todo--) {
				if (substdio_put(subfdoutsmall, " ", 1) == -1)
					strerr_die1x(111, "qprintf: unable to write output: ");
			}
			if (substdio_put(subfdoutsmall, src, len) == -1)
				strerr_die1x(111, "qprintf: unable to write output: ");
			return (0);
		} else
			return (substdio_put(subfdoutsmall, src, len));
		break;
	case '-':
		scan_int(format_spec + 2, &i);
	default:
		if (i == -1)
			scan_int(format_spec + 1, &i);
		if (len < i) {
			if (substdio_put(subfdoutsmall, src, len) == -1)
				strerr_die1x(111, "qprintf: unable to write output: ");
			for (todo = i - len; todo; todo--) {
				if (substdio_put(subfdoutsmall, " ", 1) == -1)
					strerr_die1x(111, "qprintf: unable to write output: ");
			}
			return (0);
		} else
			return (substdio_put(subfdoutsmall, src, len));
		break;
	}
}
