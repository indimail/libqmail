/*
 * $Log: scan_html.c,v $
 * Revision 1.1  2020-09-30 09:16:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#include "entities.h"
#include "fmt.h"
#include "textcode.h"
#include "scan.h"
#include "case.h"
#include "str.h"
#include "byte.h"

static const char *
lookup(size_t ofs, const char *t)
{
	if (ofs > entities.tab[0])
		return 0;
	while (ofs < entities.tab[0]) {
		unsigned char   ch = entities.tab[ofs] & 0xff;
		if (ch == (unsigned char) *t || (!ch && *t == ';')) {
			if (!ch || *t == ';')
				return entities.data + (entities.tab[ofs] >> 8);
			else
				return lookup(entities.tab[ofs] >> 8, t + 1);
		} else
			++ofs;
		if (!ch)
			break;
	}
	return NULL;
}

static size_t
scan_html_inner(const char *src, char *dest, size_t *destlen, int flag)
{
	register const unsigned char *s = (const unsigned char *) src;
	size_t          written = 0, i;

	for (i = 0; s[i]; ++i) {
		if (s[i] == '&') {
			const char     *utf8;
			if (s[i + 1] == '#') {
				unsigned long   l;
				size_t          j;
				if ((s[i + 2] & ~32) == 'X') {
					j = scan_xlong((char *) src + i + 3, &l);
					if (!j)
						j += 3;
				} else {
					j = scan_ulong((char *) src + i + 2, &l);
					if (!j)
						j += 3;
				}
				if (s[i + j] == ';') {
					i += j;
					written += fmt_utf8(dest + written, l);
				} else {
					dest[written++] = '&';
				}
				continue;
			}
			utf8 = lookup(1, src + i + 1);
			if (utf8) {
				size_t          l = str_len((char *) utf8);
				byte_copy(dest + written, l, (char *) utf8);
				written += l;
				i += 2 + str_chr((char *) src + i + 2, ';');
				continue;
			} else
				dest[written] = '&';
		} else
		if (flag && s[i] == '<') {
			if (case_starts((char *) s + i + 1, "br>")) {
				dest[written] = '\n';
				i += 3;
			} else
			if (case_starts((char *) s + i + 1, "p>")) {
				dest[written] = '\n';
				++written;
				dest[written] = '\n';
				i += 3;
			} else
				dest[written] = s[i];
		} else
			dest[written] = s[i];
		++written;
	}
	*destlen = written;
	return i;
}

size_t
scan_html_tagarg(const char *src, char *dest, size_t *destlen)
{
	return scan_html_inner(src, dest, destlen, 1);
}

size_t
scan_html(const char *src, char *dest, size_t *destlen)
{
	return scan_html_inner(src, dest, destlen, 0);
}

void
getversion_scan_html_c()
{
	const char     *x = "$Id: scan_html.c,v 1.1 2020-09-30 09:16:27+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
