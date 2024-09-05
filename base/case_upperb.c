/*
 * $Id: case_upperb.c,v 1.1 2024-09-05 18:07:01+05:30 Cprogrammer Exp mbhangui $
 */
#include "case.h"

void
case_upperb(char *s, unsigned int len)
{
	while (len > 0) {
		--len;
		if (*s >= 'a' && *s <= 'z')
			*s -= 'a' - 'A';
		++s;
	}
}

/*
 * $Log: case_upperb.c,v $
 * Revision 1.1  2024-09-05 18:07:01+05:30  Cprogrammer
 * Initial revision
 *
 */
