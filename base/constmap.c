/*
 * $Log: constmap.c,v $
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

static int      delimiter = ':';

static constmap_hash
hash(char *s, unsigned int len)
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

char           *
constmap(struct constmap *cm, char *s, unsigned int len)
{
	constmap_hash   h;
	int             pos;

	h = hash(s, len);
	pos = cm->first[h & cm->mask];
	while (pos != -1) {
		if (h == cm->hash[pos])
			if (len == cm->inputlen[pos])
				if (!case_diffb(cm->input[pos], len, s))
					return cm->input[pos] + cm->inputlen[pos] + 1;
		pos = cm->next[pos];
	}
	return 0;
}

int
constmap_init(struct constmap *cm, char *s, unsigned int len, int flagkey)
{
	unsigned int    i, j, k, t, pos;
	constmap_hash   h;

	cm->num = 0;
	if (flagkey < ' ' || flagkey > '~')
		delimiter = ':';
	else
	if (flagkey)
		delimiter = flagkey;
	for (j = 0; j < len; ++j)
		if (!s[j])
			++cm->num;
	h = 64;
	while (h && (h < cm->num))
		h += h;
	cm->mask = h - 1;
	cm->first = (int *) alloc(sizeof(int) * h);
	if (cm->first) {
		cm->input = (char **) alloc(sizeof(char *) * cm->num);
		if (cm->input) {
			cm->inputlen = (int *) alloc(sizeof(int) * cm->num);
			if (cm->inputlen) {
				if (__builtin_mul_overflow(sizeof(constmap_hash), cm->num, &t)) {
					errno = error_nomem;
					return 0;
				}
				cm->hash = (constmap_hash *) alloc(t);
				if (cm->hash) {
					cm->next = (int *) alloc(sizeof(int) * cm->num);
					if (cm->next) {
						for (h = 0; h <= cm->mask; ++h)
							cm->first[h] = -1;
						pos = 0;
						i = 0;
						for (j = 0; j < len; ++j)
							if (!s[j]) {
								k = j - i;
								if (flagkey) {
									for (k = i; k < j; ++k)
										if (s[k] == delimiter)
											break;
									if (k >= j) {
										i = j + 1;
										continue;
									}
									k -= i;
								}
								cm->input[pos] = s + i;
								cm->inputlen[pos] = k;
								h = hash(s + i, k);
								cm->hash[pos] = h;
								h &= cm->mask;
								cm->next[pos] = cm->first[h];
								cm->first[h] = pos;
								++pos;
								i = j + 1;
							}
						return 1;
					}
					alloc_free((char *) cm->hash);
				}
				alloc_free((char *) cm->inputlen);
			}
			alloc_free((char *) cm->input);
		}
		alloc_free((char *) cm->first);
	}
	return 0;
}

void
constmap_free(struct constmap *cm)
{
	alloc_free((char *) cm->next);
	alloc_free((char *) cm->hash);
	alloc_free((char *) cm->inputlen);
	alloc_free((char *) cm->input);
	alloc_free((char *) cm->first);
}

void
getversion_constmap_c()
{
	static char    *x = "$Id: constmap.c,v 1.5 2020-11-26 11:58:51+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
