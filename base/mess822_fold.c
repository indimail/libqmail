/*
 * $Log: mess822_fold.c,v $
 * Revision 1.4  2024-05-09 23:46:54+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.2  2004-10-22 20:27:28+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-01-04 23:17:26+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "mess822.h"

int
mess822_fold(stralloc *out, stralloc *in, const char *prefix, int linelen)
{
	int             i;
	int             j;
	int             k;
	int             partial;

	if (!stralloc_copys(out, prefix))
		return 0;
	partial = out->len;
	for (j = i = 0; j <= in->len; ++j) {
		if ((j == in->len) || (in->s[j] == '\n')) {
			k = i;
			while ((in->s[k] == ' ') && (in->s[k + 1] == ' '))
				++k;
			if (i && (partial + j - k > linelen)) {
				if (!stralloc_cats(out, "\n") ||
						!stralloc_catb(out, in->s + i, j - i))
					return 0;
				partial = j - i;
			} else {
				if (!stralloc_catb(out, in->s + k, j - k))
					return 0;
				partial += j - k;
			}
			i = j + 1;
		}
	}
	if (!stralloc_append(out, "\n"))
		return 0;
	return 1;
}

void
getversion_mess822_fold_c()
{
	const char     *x = "$Id: mess822_fold.c,v 1.4 2024-05-09 23:46:54+05:30 mbhangui Exp mbhangui $";

	x++;
}
