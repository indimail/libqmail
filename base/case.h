/*
 * $Log: case.h,v $
 * Revision 1.5  2024-09-05 18:08:01+05:30  Cprogrammer
 * added case_uppers(), case_upperb() functions
 *
 * Revision 1.4  2020-11-22 23:50:19+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2004-10-11 13:49:14+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 22:57:50+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef CASE_H
#define CASE_H

void            case_lowers(char *);
void            case_lowerb(char *, unsigned int);
void            case_uppers(char *);
void            case_upperb(char *, unsigned int);
int             case_diffs(const char *, const char *);
int             case_diffb(const char *, unsigned int, const char *);
int             case_starts(const char *, const char *);
int             case_startb(const char *, unsigned int, const char *);

#define case_equals(s,t) (!case_diffs((s),(t)))

#endif
