/*
 * $Log: cdbmake_add.c,v $
 * Revision 1.10  2024-05-12 00:10:20+05:30  mbhangui
 * fix function prototypes
 *
 * Revision 1.9  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.8  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.7  2020-12-02 14:50:59+05:30  Cprogrammer
 * changed return type of alloc() to void *
 *
 * Revision 1.6  2020-05-11 12:32:05+05:30  Cprogrammer
 * fixed shadowing of global variables by local variables
 *
 * Revision 1.5  2005-08-23 17:14:39+05:30  Cprogrammer
 * gcc 4 compliance
 *
 * Revision 1.4  2004-10-22 20:23:21+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-07-17 21:17:19+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "cdbmake.h"

void
cdbmake_init(struct cdbmake *cdbm)
{
	cdbm->head = 0;
	cdbm->split = 0;
	cdbm->hash = 0;
	cdbm->numentries = 0;
}

int
cdbmake_add(struct cdbmake *cdbm, uint32 h, uint32 p, void *(*alloc)(unsigned int))
{
	struct cdbmake_hplist *head;

	head = cdbm->head;
	if (!head || (head->num >= CDBMAKE_HPLIST)) {
		if (!(head = (struct cdbmake_hplist *) alloc(sizeof(struct cdbmake_hplist))))
			return 0;
		head->num = 0;
		head->next = cdbm->head;
		cdbm->head = head;
	}
	head->hp[head->num].h = h;
	head->hp[head->num].p = p;
	++head->num;
	++cdbm->numentries;
	return 1;
}

int
cdbmake_split(struct cdbmake *cdbm, void *(*alloc)(unsigned int))
{
	int             i;
	uint32          u, memsize;
	struct cdbmake_hplist *x;

	for (i = 0; i < 256; ++i)
		cdbm->count[i] = 0;
	for (x = cdbm->head; x; x = x->next) {
		i = x->num;
		while (i--)
			++cdbm->count[255 & x->hp[i].h];
	}
	memsize = 1;
	for (i = 0; i < 256; ++i) {
		u = cdbm->count[i] * 2;
		if (u > memsize)
			memsize = u;
	}
	memsize += cdbm->numentries;	/*- no overflow possible up to now */
	u = (uint32) 0 - (uint32) 1;
	u /= sizeof(struct cdbmake_hp);
	if (memsize > u)
		return 0;
	if (!(cdbm->split = (struct cdbmake_hp *) alloc(memsize * sizeof(struct cdbmake_hp))))
		return 0;
	cdbm->hash = cdbm->split + cdbm->numentries;
	u = 0;
	for (i = 0; i < 256; ++i) {
		u += cdbm->count[i];	/*- bounded by numentries, so no overflow */
		cdbm->start[i] = u;
	}
	for (x = cdbm->head; x; x = x->next) {
		i = x->num;
		while (i--)
			cdbm->split[--cdbm->start[255 & x->hp[i].h]] = x->hp[i];
	}

	return 1;
}

uint32
cdbmake_throw(struct cdbmake *cdbm, uint32 pos, int b)
{
	uint32          len, j, count;
	struct cdbmake_hp *hp;
	uint32          where;

	count = cdbm->count[b];
	len = count + count; /*- no overflow possible */
	cdbmake_pack((unsigned char *) cdbm->final + 8 * b, pos);
	cdbmake_pack((unsigned char *) cdbm->final + 8 * b + 4, len);
	if (len) {
		for (j = 0; j < len; ++j)
			cdbm->hash[j].h = cdbm->hash[j].p = 0;
		hp = cdbm->split + cdbm->start[b];
		for (j = 0; j < count; ++j) {
			where = (hp->h >> 8) % len;
			while (cdbm->hash[where].p)
				if (++where == len)
					where = 0;
			cdbm->hash[where] = *hp++;
		}
	}
	return len;
}

void
getversion_cdbmake_add_c()
{
	const char     *x = "$Id: cdbmake_add.c,v 1.10 2024-05-12 00:10:20+05:30 mbhangui Exp mbhangui $";

	x++;
}
