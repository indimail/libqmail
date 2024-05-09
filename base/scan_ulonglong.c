/*
 * $Log: scan_ulonglong.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2020-11-22 23:52:22+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2019-07-18 10:09:14+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.2  2019-07-18 09:55:48+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:42:39+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "scan.h"

unsigned int
scan_ulonglong(const char *src, unsigned long long *dest)
{
	register const char *tmp = src;
	register unsigned long long l = 0;
	register unsigned char c;

	while ((c = (unsigned char) (*tmp - '0')) < 10) {
		unsigned long long n;

		/*- division is very slow on most architectures */
		n = l << 3;
		if ((n >> 3) != l)
			break;
		if (n + (l << 1) < n)
			break;
		n += l << 1;
		if (n + c < n)
			break;
		l = n + c;
		++tmp;
	}
	if (tmp - src)
		*dest = l;
	return (tmp - src);
}

void
getversion_scan_ulonglong_c()
{
	const char     *x = "$Id: scan_ulonglong.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
