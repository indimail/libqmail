/* 
 * $Log: str_tok.c,v $
 * Revision 1.2  2019-07-18 09:55:59+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:42:47+05:30  Cprogrammer
 * Initial revision
 *
 *
 * str_tok.c --
 *
 *	Source code for the "str_tok" library routine.
 *
 * Copyright 1988 Regents of the University of California
 * Permission to use, copy, modify, and distribute this
 * software and its documentation for any purpose and without
 * fee is hereby granted, provided that the above copyright
 * notice appear in all copies.  The University of California
 * makes no representations about the suitability of this
 * software for any purpose.  It is provided "as is" without
 * express or implied warranty.
 */

#include "str.h"

#ifndef lint
static char     rcsid[] = "$Id: str_tok.c,v 1.2 2019-07-18 09:55:59+05:30 Cprogrammer Exp mbhangui $";
#endif

static char *
local_strchr (register const char *s, int c)
{
  do {
    if (*s == c)
      {
        return (char*)s;
      }
  } while (*s++);
  return (0);
}

/*
 *----------------------------------------------------------------------
 *
 * str_tok --
 *
 *  	Split a string up into tokens
 *
 * Results:
 *      If the first argument is non-NULL then a pointer to the
 *      first token in the string is returned.  Otherwise the
 *      next token of the previous string is returned.  If there
 *      are no more tokens, NULL is returned.
 *
 * Side effects:
 *	Overwrites the delimiting character at the end of each token
 *      with '\0'.
 *
 *----------------------------------------------------------------------
 */

char *
str_tok(s, delim)
    char *s;            /* string to search for tokens */
    const char *delim;  /* delimiting characters */
{
    static char *lasts;
    register int ch;

    if (s == 0)
	s = lasts;
    do {
	if ((ch = *s++) == '\0')
	    return 0;
    } while (local_strchr(delim, ch));
    --s;
    lasts = s + str_cspn(s, delim);
    if (*lasts != 0)
	*lasts++ = 0;
    return s;
}

void
getversion_str_tok_c()
{
	static char    *x = "$Id: str_tok.c,v 1.2 2019-07-18 09:55:59+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
