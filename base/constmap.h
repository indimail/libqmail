/*
 * $Log: constmap.h,v $
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

struct constmap
{
	int             num;
	constmap_hash   mask;
	constmap_hash  *hash;
	int            *first;
	int            *next;
	char          **input;
	int            *inputlen;
};

extern int      constmap_init(struct constmap *, char *, unsigned int, int);
extern void     constmap_free(struct constmap *);
extern char    *constmap(struct constmap *, char *, unsigned int);

#endif
