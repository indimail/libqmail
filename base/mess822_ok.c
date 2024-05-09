/*
 * $Log: mess822_ok.c,v $
 * Revision 1.4  2024-05-09 23:46:54+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.2  2004-10-22 20:27:30+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-01-04 23:17:51+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "mess822.h"
#include "byte.h"

int
mess822_ok(stralloc *sa)
{
	int             i;
	int             len;
	int             colon;

	len = sa->len;
	if (len && (sa->s[len - 1] == '\n'))
		--len;
	if (!len)
		return 0;
	/*
	 * if input message is 822-compliant, will return 1 after this
	 */
	if (sa->s[0] == ' ')
		return 1;
	if (sa->s[0] == '\t')
		return 1;
	colon = byte_chr(sa->s, sa->len, ':');
	if (colon >= sa->len)
		return 0;
	while (colon && ((sa->s[colon - 1] == ' ') || (sa->s[colon - 1] == '\t')))
		--colon;
	if (!colon)
		return 0;
	for (i = 0; i < colon; ++i)
		if (sa->s[i] < 33)
			return 0;
	for (i = 0; i < colon; ++i)
		if (sa->s[i] > 126)
			return 0;
	return 1;
}

void
getversion_mess822_ok_c()
{
	const char     *x = "$Id: mess822_ok.c,v 1.4 2024-05-09 23:46:54+05:30 mbhangui Exp mbhangui $";

	x++;
}
