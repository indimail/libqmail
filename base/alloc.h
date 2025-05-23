/*
 * $Log: alloc.h,v $
 * Revision 1.6  2025-01-21 22:18:20+05:30  Cprogrammer
 * fixes for gcc14
 *
 * Revision 1.5  2024-05-12 00:10:20+05:30  mbhangui
 * fix function prototypes
 *
 * Revision 1.4  2020-12-02 14:50:38+05:30  Cprogrammer
 * changed return type of alloc() to void *
 *
 * Revision 1.3  2004-10-11 13:48:20+05:30  Cprogrammer
 * added prototypes
 *
 * Revision 1.2  2004-06-18 22:52:28+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef ALLOC_H
#define ALLOC_H

/* @null@ *//* @out@ */
void           *alloc(unsigned int);
void            alloc_free(char *);
int             alloc_re(void **, unsigned int, unsigned int);

#endif
