/*
 * $Log: constmap.h,v $
 * Revision 1.5  2020-11-26 13:48:52+05:30  Cprogrammer
 * added constmap_index(), constmap_get() functions
 *
 * Revision 1.4  2020-05-15 11:37:12+05:30  Cprogrammer
 * define function prototypes as extern
 *
 * Revision 1.3  2004-10-11 13:51:38+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 22:58:16+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef CONSTMAP_H
#define CONSTMAP_H

typedef unsigned long constmap_hash;

struct constmap_entry {
	const char     *input;
	int             inputlen;
	constmap_hash   hash;
	int             next;
};

struct constmap {
	unsigned int    num;
	constmap_hash   mask;
	int            *first;
	struct constmap_entry *entries;
};

extern int      constmap_init(struct constmap *cm, const char *s, int len, int splitchar);
extern void     constmap_free(struct constmap *cm);
extern const char *constmap(struct constmap *cm, const char *s, int len);
extern const char *constmap_get(struct constmap *cm, unsigned int idx);
extern int      constmap_index(const struct constmap *cm, const char *s, int len);
#endif
