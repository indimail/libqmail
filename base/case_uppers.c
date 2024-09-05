/*
 * $Id: case_uppers.c,v 1.1 2024-09-05 18:07:08+05:30 Cprogrammer Exp mbhangui $
 */
#include "case.h"

void
case_uppers(char *s)
{
	while (*s) {
		if (*s >= 'a' && *s <= 'z')
			*s -= 'a' - 'A';
		++s;
	}
}

/*
 * $Log: case_uppers.c,v $
 * Revision 1.1  2024-09-05 18:07:08+05:30  Cprogrammer
 * Initial revision
 *
 */
