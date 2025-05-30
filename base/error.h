/*
 * $Log: error.h,v $
 * Revision 1.14  2025-05-06 22:19:24+05:30  Cprogrammer
 * added error_invalid for EINVAL
 *
 * Revision 1.13  2024-05-09 23:46:54+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.12  2023-04-24 22:18:02+05:30  Cprogrammer
 * fixed order
 *
 * Revision 1.11  2022-12-13 15:49:10+05:30  Cprogrammer
 * added error_child
 *
 * Revision 1.10  2020-11-24 13:33:59+05:30  Cprogrammer
 * added error_notdir
 *
 * Revision 1.9  2019-06-24 21:18:50+05:30  Cprogrammer
 * added error_restart
 *
 * Revision 1.8  2017-04-18 08:36:29+05:30  Cprogrammer
 * added error_srch for errno ESRCH
 *
 * Revision 1.7  2008-08-02 14:20:24+05:30  Cprogrammer
 * added function estack()
 *
 * Revision 1.6  2004-10-11 13:53:20+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.5  2004-10-09 21:20:39+05:30  Cprogrammer
 * added error_nodevice
 *
 * Revision 1.4  2004-06-18 22:58:31+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef ERROR_H
#define ERROR_H

#include <errno.h>

extern int      error_intr;
extern int      error_nomem;
extern int      error_noent;
extern int      error_txtbsy;
extern int      error_io;
extern int      error_exist;
extern int      error_timeout;
extern int      error_inprogress;
extern int      error_wouldblock;
extern int      error_again;
extern int      error_dquot;
extern int      error_pipe;
extern int      error_perm;
extern int      error_acces;
extern int      error_nodevice;
extern int      error_proto;
extern int      error_isdir;
extern int      error_connrefused;
extern int      error_notdir;
extern int      error_hostdown;
extern int      error_netunreach;
extern int      error_hostunreach;
extern int      error_srch;
extern int      error_restart;
extern int      error_child;
extern int      error_ebadf;
extern int      error_invalid;

const char     *error_str(int);
char           *estack(int, const char *);
int             error_temp(int);

#endif
