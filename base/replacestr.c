/*
 * $Log: replacestr.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2022-01-30 19:37:31+05:30  Cprogrammer
 * removed #ifdef HAVE_QMAIL
 *
 * Revision 1.3  2020-07-23 11:19:26+05:30  Cprogrammer
 * added comments as code is complicated
 *
 * Revision 1.2  2020-07-09 13:42:50+05:30  Cprogrammer
 * BUGFIX: initialize stralloc variable buf
 *
 * Revision 1.1  2019-04-14 18:30:01+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <stralloc.h>
#include <strerr.h>
#include <str.h>

#ifndef	lint
const char      sccsid[] = "$Id: replacestr.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";
#endif

/*-
 * returns 0 if search string ch not found
 * and leaves buf untouched
 */
int
replacestr(const char *str, const char *ch, const char *rch, stralloc *buf)
{
	int             chlen, rchlen, prev;
	register int    i, cnt;
	register const char  *ptr, *s;

	chlen = str_len(ch);
	rchlen = str_len(rch);
	buf->len = 0;
	for (ptr = str, prev = cnt = 0; *ptr;) {
		/*- no more characters found from this point onward */
		if (!(s = str_str(ptr, ch))) {
			if (cnt) {
				/*- copy remaining data */
				if (!stralloc_cats(buf, ptr))
					return (-1);
				if (!stralloc_0(buf))
					return (-1);
				buf->len--;
			}
			return (cnt);
		}
		i = s - str;
		/*- copy data upto the found character */
		if (!stralloc_catb(buf, ptr, i - prev))
			return (-1);
		/*- replace the found character with replacement */
		if (!stralloc_catb(buf, rch, rchlen))
			return (-1);
		ptr = str + i + chlen; /*- move past the found character */
		prev = i + chlen;
		cnt++;
	}
	if (!stralloc_0(buf))
		return (-1);
	buf->len--;
	return (cnt);
}
