/*
 * $Log: prot.h,v $
 * Revision 1.4  2021-07-03 13:51:30+05:30  Cprogrammer
 * updated data types
 *
 * Revision 1.3  2004-10-11 13:57:43+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 23:01:19+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef PROT_H
#define PROT_H
#include <sys/types.h>

int             prot_gid(gid_t);
int             prot_uid(uid_t);

#endif
