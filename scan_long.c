#include "scan.h"

unsigned int
scan_long(s, i)
	register char  *s;
	register long  *i;
{
	int             sign;
	unsigned long   u;
	register unsigned int len;

	len = scan_plusminus(s, &sign);
	s += len;
	len += scan_ulong(s, &u);
	if (sign < 0)
		*i = -u;
	else
		*i = u;
	return len;
}

