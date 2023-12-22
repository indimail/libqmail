/*
 * $Id: str.h,v 1.12 2023-12-22 18:37:34+05:30 Cprogrammer Exp mbhangui $
 */
#ifndef STR_H
#define STR_H

unsigned int    str_copy(char *, const char *);
unsigned int    str_copyb(char *, const char *, unsigned int);
int             str_diff(const char *, const char *);
int             str_diffn(const char *, const char *, unsigned int);
unsigned int    str_len(const char *);
unsigned int    str_chr(const char *, int);
char           *str_chrn(const char *, int, int);
unsigned int    str_rchr(const char *, int);
int             str_start(const char *, const char *);
int             str_end(const char *, const char *);
char           *str_str(const char *, const char *);
#include <sys/types.h>
size_t          str_cspn(const char *, register const char *);
size_t          str_spn(const char *, register const char *);
char           *str_tok(char *, const char *);

#define str_equal(s,t) (!str_diff((s),(t)))

#endif
/*
 * $Log: str.h,v $
 * Revision 1.12  2023-12-22 18:37:34+05:30  Cprogrammer
 * added str_spn() function
 *
 * Revision 1.11  2021-07-15 09:49:20+05:30  Cprogrammer
 * fixed prototypes for str_chr, str_chrn, str_rchr - use const char *
 *
 * Revision 1.10  2021-06-10 10:50:30+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.9  2020-11-22 23:53:43+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.8  2019-06-24 21:29:40+05:30  Cprogrammer
 * added str_str(), str_tok() functions
 *
 * Revision 1.7  2016-02-08 18:26:41+05:30  Cprogrammer
 * added str_end() function
 *
 * Revision 1.6  2011-07-12 20:42:33+05:30  Cprogrammer
 * added str_cspn() function
 *
 * Revision 1.5  2004-10-24 21:39:53+05:30  Cprogrammer
 * added prototype for str_chrn()
 *
 * Revision 1.4  2004-10-09 23:34:19+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.3  2004-08-14 02:19:12+05:30  Cprogrammer
 * added str_copyb()
 *
 * Revision 1.2  2004-06-18 23:02:40+05:30  Cprogrammer
 * added RCS log
 *
 */
