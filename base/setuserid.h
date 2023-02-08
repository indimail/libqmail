/*
 * $Log: setuserid.h,v $
 * Revision 1.4  2023-02-08 11:23:08+05:30  Cprogrammer
 * include qmailconfig.h if HAVE_CONFIG_H is not defined
 *
 * Revision 1.3  2020-07-04 23:45:00+05:30  Cprogrammer
 * include sys/types.h, grp.h if config.h is not included
 *
 * Revision 1.2  2020-06-18 20:12:50+05:30  Cprogrammer
 * added #include <grp.h>
 *
 * Revision 1.1  2019-04-13 23:39:27+05:30  Cprogrammer
 * setuserid.h
 *
 */
#ifndef SETUSERID_H
#define SETUSERID_H
#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#include "qmailconfig.h"
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_GRP_H
#include <grp.h>
#endif

gid_t           *grpscan(char *, int *);
int              setuserid(char *);
int              setuser_privileges(uid_t, gid_t, char *);

#endif
