/*
 * $Log: error.c,v $
 * Revision 1.13  2025-05-06 22:19:14+05:30  Cprogrammer
 * added error_invalid for EINVAL
 *
 * Revision 1.12  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.11  2023-04-24 22:17:56+05:30  Cprogrammer
 * fixed error codes
 *
 * Revision 1.10  2022-12-13 15:48:57+05:30  Cprogrammer
 * added error_child for ECHILD
 *
 * Revision 1.9  2020-11-24 13:33:44+05:30  Cprogrammer
 * added error_notdir
 *
 * Revision 1.8  2019-06-24 21:13:50+05:30  Cprogrammer
 * added ERESTART
 *
 * Revision 1.7  2017-04-18 08:35:54+05:30  Cprogrammer
 * added error_srch for errno ESRCH
 *
 * Revision 1.6  2004-10-22 20:24:52+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.5  2004-10-09 20:40:16+05:30  Cprogrammer
 * added case for enxio
 *
 * Revision 1.4  2004-07-17 21:18:34+05:30  Cprogrammer
 * added RCS log
 *
 */
#include "error.h"

/* warning: as coverage improves here, should update error_{str,temp} */

int error_intr =
#ifdef EINTR
EINTR;
#else
-1;
#endif

int error_nomem =
#ifdef ENOMEM
ENOMEM;
#else
-2;
#endif

int error_noent = 
#ifdef ENOENT
ENOENT;
#else
-3;
#endif

int error_txtbsy =
#ifdef ETXTBSY
ETXTBSY;
#else
-4;
#endif

int error_io =
#ifdef EIO
EIO;
#else
-5;
#endif

int error_exist =
#ifdef EEXIST
EEXIST;
#else
-6;
#endif

int error_timeout =
#ifdef ETIMEDOUT
ETIMEDOUT;
#else
-7;
#endif

int error_inprogress =
#ifdef EINPROGRESS
EINPROGRESS;
#else
-8;
#endif

int error_wouldblock =
#ifdef EWOULDBLOCK
EWOULDBLOCK;
#else
-9;
#endif

int error_again =
#ifdef EAGAIN
EAGAIN;
#else
-10;
#endif

int error_pipe =
#ifdef EPIPE
EPIPE;
#else
-11;
#endif

int error_perm =
#ifdef EPERM
EPERM;
#else
-12;
#endif

int error_acces =
#ifdef EACCES
EACCES;
#else
-13;
#endif

int error_nodevice =
#ifdef ENXIO
ENXIO;
#else
-14;
#endif

int error_proto =
#ifdef EPROTO
EPROTO;
#else
-15;
#endif

int error_isdir =
#ifdef EISDIR
EISDIR;
#else
-16;
#endif

int error_connrefused =
#ifdef ECONNREFUSED
ECONNREFUSED;
#else
-17;
#endif

int error_hostdown =
#ifdef EHOSTDOWN
EHOSTDOWN;
#else
-18;
#endif

int error_netunreach =
#ifdef ENETUNREACH
ENETUNREACH;
#else
-19;
#endif

int error_hostunreach =
#ifdef EHOSTUNREACH
EHOSTUNREACH;
#else
-20;
#endif

int error_dquot =
#ifdef EDQUOT
EDQUOT;
#else
-21;
#endif

int error_notdir =
#ifdef ENOTDIR
ENOTDIR;
#else
-22;
#endif

int error_srch =
#ifdef ESRCH
ESRCH;
#else
-23;
#endif

int error_restart =
#ifdef ERESTART
ERESTART;
#else
-24;
#endif

int error_child =
#ifdef ECHILD
ECHILD;
#else
-25;
#endif

int error_ebadf =
#ifdef EBADF
EBADF;
#else
-26;
#endif

int error_invalid =
#ifdef EINVAL
EINVAL;
#else
-27;
#endif

void
getversion_error_c()
{
	const char     *x = "$Id: error.c,v 1.13 2025-05-06 22:19:14+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
