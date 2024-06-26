/*
 * $Log: taia_fmtfrac.c,v $
 * Revision 1.3  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.2  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.1  2016-01-28 23:43:09+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "taia.h"

unsigned int
taia_fmtfrac(char *s, const struct taia *t)
{
	unsigned long   x;

	if (s) {
		x = t->atto;
		s[17] = '0' + (x % 10);
		x /= 10;
		s[16] = '0' + (x % 10);
		x /= 10;
		s[15] = '0' + (x % 10);
		x /= 10;
		s[14] = '0' + (x % 10);
		x /= 10;
		s[13] = '0' + (x % 10);
		x /= 10;
		s[12] = '0' + (x % 10);
		x /= 10;
		s[11] = '0' + (x % 10);
		x /= 10;
		s[10] = '0' + (x % 10);
		x /= 10;
		s[9] = '0' + (x % 10);
		x = t->nano;
		s[8] = '0' + (x % 10);
		x /= 10;
		s[7] = '0' + (x % 10);
		x /= 10;
		s[6] = '0' + (x % 10);
		x /= 10;
		s[5] = '0' + (x % 10);
		x /= 10;
		s[4] = '0' + (x % 10);
		x /= 10;
		s[3] = '0' + (x % 10);
		x /= 10;
		s[2] = '0' + (x % 10);
		x /= 10;
		s[1] = '0' + (x % 10);
		x /= 10;
		s[0] = '0' + (x % 10);
	}
	return 18;
}

void
getversion_taia_fmtfrac_c()
{
	const char     *x = "$Id: taia_fmtfrac.c,v 1.3 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
