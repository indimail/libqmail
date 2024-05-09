/*
 * $Log: constmap.c,v $
 * Revision 1.6  2020-11-26 13:48:36+05:30  Cprogrammer
 * added constmap_index(), constmap_get() functions
 *
 * Revision 1.5  2020-11-26 11:58:51+05:30  Cprogrammer
 * allow delimiter to be changed
 *
 * Revision 1.4  2020-05-15 11:36:20+05:30  Cprogrammer
 * convert function prototypes to c89 standards
 * fix possible integer overflow
 *
 * Revision 1.3  2004-10-22 20:24:08+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:18:07+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "constmap.h"
#include "alloc.h"
#include "case.h"
#include "error.h"
#include "builtinoflmacros.h"

static constmap_hash
hash(const char *s, int len)
{
	unsigned char   ch;
	constmap_hash   h;

	h = 5381;
	while (len > 0) {
		ch = *s++ - 'A';
		if (ch <= 'Z' - 'A')
			ch += 'a' - 'A';
		h = ((h << 5) + h) ^ ch;
		--len;
	}
	return h;
}

const char     *
constmap(struct constmap *cm, const char *s, int len)
{
	constmap_hash   h;
	struct constmap_entry *e;
	int             pos;

	h = hash(s, len);
	pos = cm->first[h & cm->mask];
	while (pos != -1) {
		e = &cm->entries[pos];
		if (h == e->hash && len == e->inputlen && !case_diffb(e->input, len, s))
			return e->input + e->inputlen + 1;
		pos = e->next;
	}
	return 0;
}

static int      delimiter = ':';
/*-
 * if splitchar is set, we process only the stuff before that character
 * on each line. Otherwise, it's the entire line. Still, the entire line
 * is stored!
 */
int
constmap_init(struct constmap *cm, const char *s, int len, int splitchar)
{
	unsigned int    i, j, k, t, pos;
	constmap_hash   h;
	struct constmap_entry *e;

	if (splitchar < ' ' || splitchar > '~')
		delimiter = ':';
	else
	if (splitchar)
		delimiter = splitchar;
	cm->num = 0;
	for (j = 0; j < len; ++j)
		if (!s[j])
			++cm->num;

	h = 64;
	while (h && (h < cm->num))
		h += h;
	cm->mask = h - 1;

	cm->first = (int *) alloc(sizeof (int) * h);
	if (cm->first) {
		if (__builtin_mul_overflow(sizeof(struct constmap_entry), cm->num, &t)) {
			errno = error_nomem;
			return 0;
		}
		cm->entries = (struct constmap_entry *) alloc(t);
		if (cm->entries) {
			for (h = 0; h <= cm->mask; ++h)
				cm->first[h] = -1;
			pos = 0;
			i = 0;
			for (j = 0; j < len; ++j) {
				if (!s[j]) {
					k = j - i;
					if (splitchar) {
						for (k = i; k < j; ++k) {
							if (s[k] == delimiter)
								break;
						}
						if (k >= j) {
							i = j + 1;
							continue;
						}
						k -= i;
					}
					h = hash(s + i, k);
					e = &cm->entries[pos];
					e->input = s + i;
					e->inputlen = k;
					e->hash = h;
					h &= cm->mask;
					e->next = cm->first[h];
					cm->first[h] = pos;
					++pos;
					i = j + 1;
				}
			}
			return 1;
		}
		alloc_free((char *) cm->first);
	}
	return 0;
}

/*
 * Returns index of string in constmap. 1 = first string, 2 = second ... 
 * 0 not found. Use for commands 
 */
int
constmap_index(const struct constmap *cm, const char *s, int len)
{
	constmap_hash   h;
	struct constmap_entry *e;
	int             pos;

	h = hash(s, len);
	pos = cm->first[h & cm->mask];
	while (pos != -1) {
		e = &cm->entries[pos];
		if (h == e->hash && len == e->inputlen && !case_diffb(e->input, len, s))
			return pos + 1;
		pos = e->next;
	}
	return 0;
}

/*
 * returns pointer to sz of string with index "idx". 1 = first, 2 = second...
 */
const char     *
constmap_get(struct constmap *cm, unsigned int idx)
{
	if (idx <= 0 || idx > cm->num)
		return 0;
	else
		return cm->entries[idx - 1].input;
}

void
constmap_free(struct constmap *cm)
{
	alloc_free((char *) cm->entries);
	alloc_free((char *) cm->first);
}

void
getversion_constmap_c()
{
	const char     *x = "$Id: constmap.c,v 1.6 2020-11-26 13:48:36+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
