/*
 * $Log: mess822.h,v $
 * Revision 1.5  2024-05-09 23:46:54+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2020-11-22 23:51:26+05:30  Cprogrammer
 * removed extra newline
 *
 * Revision 1.3  2004-10-11 13:55:55+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 23:00:58+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef MESS822_H
#define MESS822_H
#include "stralloc.h"
#include "caltime.h"

#define MESS822_HEADER { {0} }

typedef struct
{
	struct caltime  ct;
	int             known; /*- 0 for ct uninitialized; 1 if ok; 2 if ok and right zone */
} mess822_time;

typedef struct
{
	const char     *name; /*- 0 means all names */
	int            *flag;
	stralloc       *copy;
	stralloc       *value;
	stralloc       *addr;
	mess822_time   *when;
} mess822_action;

typedef struct
{
	stralloc        inprogress;
	mess822_action *action;
} mess822_header;

int             mess822_quoteplus(stralloc *, const char *, const char *);
int             mess822_quote(stralloc *, const char *, const char *);
int             mess822_quotelist(stralloc *, stralloc *);
int             mess822_fold(stralloc *, stralloc *, const char *, int);
int             mess822_date(stralloc *, mess822_time *);
int             mess822_token(stralloc *, const char *);
int             mess822_addrlist(stralloc *, const char *);
int             mess822_when(mess822_time *, const char *);
int             mess822_begin(mess822_header *, mess822_action *);
int             mess822_line(mess822_header *, stralloc *);
int             mess822_end(mess822_header *);
int             mess822_ok(stralloc *);

#endif
