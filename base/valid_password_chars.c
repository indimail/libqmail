/*
 * $Log: valid_password_chars.c,v $
 * Revision 1.1  2022-08-26 18:33:05+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "makesalt.h"
#include "str.h"

int
valid_password_chars(char *password)
{
	int             i;
	char           *ptr;

	for (ptr = password; *ptr; ptr++) {
		i = str_chr(pchars, *ptr);
		if (!pchars[i])
			return 0;
	}
	return 1;
}

void
getversion_valid_pasword_chars_c()
{
	const char     *x = "$Id: valid_password_chars.c,v 1.1 2022-08-26 18:33:05+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
