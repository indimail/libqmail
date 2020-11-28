/*
 * $Log: mess822_line.c,v $
 * Revision 1.6  2020-11-28 19:54:51+05:30  Cprogrammer
 * refactored logic to skip extra wsp
 *
 * Revision 1.5  2020-11-28 11:41:31+05:30  Cprogrammer
 * +HeaderName feature to display all headers which have HeaderName as the initial text
 *
 * Revision 1.4  2011-05-07 15:57:43+05:30  Cprogrammer
 * added headers for str & case function prototypes
 *
 * Revision 1.3  2004-10-22 20:27:29+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-08-07 19:55:57+05:30  Cprogrammer
 * BUG - Incorrect match. Corrected by using the length of string
 *
 * Revision 1.1  2004-01-04 23:17:41+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "mess822.h"
#include "case.h"
#include "str.h"

int
mess822_begin(mess822_header *h, mess822_action *a)
{
	h->action = a;
	for (;;) {
		if (a->value && !stralloc_copys(a->value, ""))
			return 0;
		if (a->copy && !stralloc_copys(a->copy, ""))
			return 0;
		if (a->flag)
			*a->flag = 0;
		if (a->addr && !stralloc_copys(a->addr, ""))
			return 0;
		if (a->when)
			a->when->known = 0;
		if (!a->name)
			break;
		++a;
	}
	return stralloc_copys(&h->inprogress, "");
}

static stralloc addrlist = { 0 };

int
mess822_end(mess822_header *h)
{
	mess822_action *a;
	int             pos, i, j;
	char            ch, prev;

	if (!h->inprogress.len)
		return 1;
	for (pos = 0; pos < h->inprogress.len; ++pos) {
		ch = h->inprogress.s[pos];
		if (ch == ':')
			break;
		if (ch < 33)
			break;
		if (ch > 126)
			break;
	}
	for (a = h->action; a->name; ++a) {
		j = str_len(a->name);
		if (!a->flag || (a->flag && *a->flag != 2)) {
			if ( h->inprogress.s[j] == ':' && !case_diffb(h->inprogress.s, j, a->name)) {
				break;
			}
		} else /*- we have given a + in the field name */
		if (!case_diffb(h->inprogress.s, j, a->name)) { /* compare length of a->name, not pos of ':' */
			if (!stralloc_catb(a->value, h->inprogress.s, pos + 1)) /*- include header name */
				return 0;
			break;
		}
	}
	for (; pos < h->inprogress.len; ++pos) {
		ch = h->inprogress.s[pos];
		if ((ch != ' ') && (ch != '\t'))
			break;	/*- skip past : or WSP */
	}
	if (pos < h->inprogress.len) { /*- skip past : and WSP */
		if (h->inprogress.s[pos] == ':')
			++pos;
		if (!a->flag || (a->flag && *a->flag != 2)) {
			if (h->inprogress.s[pos] == ' ')
				++pos;
		}
	}
	/*
	 * XXX: allocate all necessary memory before doing anything? 
	 */
	if (a->flag)
		if (*a->flag != 2)
			*a->flag = 1;
	if (a->copy && !stralloc_cat(a->copy, &h->inprogress))
		return 0;
	j = 0;
	prev = 0;
	for (i = pos; i < h->inprogress.len; ++i) {
		ch = h->inprogress.s[i];
		if (ch == '\r') /*- for dos formatted files */
			continue;
		/*- collapse multiple successive WSP into 1 */
		if ((prev == '\n' || prev == ' ' || prev == '\t') && (ch == ' ' || ch == '\t'))
			continue;
		if (ch != '\n') {
			if (!ch)
				ch = '\n';
			prev = ch;
			h->inprogress.s[j++] = ch;
		} else
		if (prev != ';')
			prev = ch;
	}
	h->inprogress.len = j;
	if (!stralloc_0(&h->inprogress))
		return 0;
	if (a->value) {
		for (i = 0; (ch = h->inprogress.s[i]); ++i) {
			if (ch == '\n')
				ch = 0;
			if (!stralloc_append(a->value, &ch))
				return 0;
		}
		if (!stralloc_append(a->value, "\n"))
			return 0;
	}
	/*
	 * XXX: tokenize once for both addr and when? 
	 */
	if (a->addr) {
		if (!mess822_addrlist(&addrlist, h->inprogress.s))
			return 0;
		if (!stralloc_cat(a->addr, &addrlist))
			return 0;
	}
	if (a->when && !mess822_when(a->when, h->inprogress.s))
		return 0;
	h->inprogress.len = 0;
	return 1;
}

int
mess822_line(mess822_header *h, stralloc * s)
{
	if (!s->len)
		return 1;
	if (s->s[0] == ' ' || s->s[0] == '\t')
		return stralloc_cat(&h->inprogress, s);
	if (!mess822_end(h))
		return 0;
	return stralloc_copy(&h->inprogress, s);
}

void
getversion_mess822_line_c()
{
	static char    *x = "$Id: mess822_line.c,v 1.6 2020-11-28 19:54:51+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
