/*
 * $Log: scan_ulonglong.c,v $
 * Revision 1.1  2019-06-24 21:42:39+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "scan.h"

#ifndef lint
static char     rcsid[] = "$Id: scan_ulonglong.c,v 1.1 2019-06-24 21:42:39+05:30 Cprogrammer Exp mbhangui $";
#endif

unsigned int
scan_ulonglong(char *src, unsigned long long *dest)
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
