/*
 * $Id: setuserid.c,v 1.7 2023-02-21 00:11:41+05:30 Cprogrammer Exp mbhangui $
 */
#include <errno.h>
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_CTYPE_H
#include <ctype.h>
#endif
#ifdef HAVE_PWD_H
#include <pwd.h>
#endif
#ifdef HAVE_GRP_H
#include <grp.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include "alloc.h"
#include "scan.h"
#include "str.h"
#include "env.h"
#include "qgetpwgr.h"
#include "isnum.h"
#include "setuserid.h"

/*-
 * scan the group file for all supplementary groups.
 * Return NULL if unsucessfull
 * The returned value should be freed after use
 */
gid_t   *
grpscan(char *user, int *ngroups)
{
	struct passwd  *pwd;
	struct group   *grp;
	long            maxgroups, idx;
	gid_t          *gidset;
	int             use_qpwgr = -1;
	char          **ptr;

	if (!user || !*user)
		return ((gid_t *) 0);
	if (use_qpwgr == -1)
		use_qpwgr = env_get("USE_QPWGR") ? 1 : 0;
	if ((maxgroups = sysconf(_SC_NGROUPS_MAX)) == -1)
		return ((gid_t *) 0);
	else
	if (!(gidset = (gid_t *) alloc(maxgroups * sizeof(gid_t))))
		return ((gid_t *) 0);
	else {
		(use_qpwgr ? qsetpwent : setpwent) ();
		if (!(pwd = (use_qpwgr ? qgetpwnam : getpwnam) (user)))
			return ((gid_t *) 0);
	}
	idx = 0;
	gidset[idx++] = pwd->pw_gid;	/* the base gid */
	(use_qpwgr ? qsetgrent : setgrent) ();
	for (;;) {
		if (!(grp = (use_qpwgr ? qgetgrent : getgrent) ()))
			break;
		for (ptr = grp->gr_mem; *ptr; ptr++) {
			if (!str_diff(user, *ptr) && grp->gr_gid != gidset[0])
				gidset[idx++] = grp->gr_gid;	/* supplementary group ids */
		}
	}
	*ngroups = idx;
	return (gidset);
}

int
set_additional_groups(char *groups, int set_primary_gid)
{
	struct group   *gr;
	char           *ptr, *cptr;
	int             ngroups, i = 0, e;
	gid_t          *gidset, g;

	for (ptr = groups, ngroups = 0; *ptr; ptr++) {
		if (*ptr == ',')
			ngroups++;
	}
	ngroups++;
	if (!(gidset = (gid_t *) alloc(ngroups * sizeof(gid_t))))
		return -1;
	for (ptr = cptr = groups; *ptr; ptr++) {
		if (*ptr == ',') {
			*ptr = 0;
			if (!isnum(cptr)) {
				if (!(gr = getgrnam(cptr))) {
					e = errno;
					alloc_free((char *) gidset);
					errno = e;
					return -1;
				}
				g = gr->gr_gid;
			} else
				scan_uint(cptr, &g);
			gidset[i++] = g;
			*ptr = ',';
			cptr = ptr + 1;
		}
	}
	if (!isnum(cptr)) {
		if (!(gr = getgrnam(cptr))) {
			e = errno;
			alloc_free((char *) gidset);
			errno = e;
			return -1;
		}
		g = gr->gr_gid;
	} else
		scan_uint(cptr, &g);
	gidset[i++] = g;
	if (set_primary_gid && setgid(gidset[0]) == -1) {
		e = errno;
		alloc_free((char *) gidset);
		errno = e;
		return -1;
	}
	if (setgroups(ngroups, gidset)) {
		e = errno;
		alloc_free((char *) gidset);
		errno = e;
		return -1;
	}
	alloc_free((char *) gidset);
	return 0;
}

int
setuserid(char *user, int set_supp_id, char *groups)
{
	struct passwd  *pw;
	struct group   *gr;
	char           *ptr, *cptr;
	gid_t          *gidset = NULL;
	int             ngroups, old, use_qpwgr = -1, i, t;
	uid_t           uid;
	gid_t           gid, g;

	if (use_qpwgr == -1)
		use_qpwgr = env_get("USE_QPWGR") ? 1 : 0;
	(use_qpwgr ? qsetpwent : setpwent) ();
	if (!(pw = (use_qpwgr ? qgetpwnam : getpwnam) (user)))
		return -1;
	uid = pw->pw_uid;
	gid = pw->pw_gid;
	ngroups = 0;
	if (set_supp_id && !(gidset = grpscan(user, &ngroups)))
		return -1;
	if (groups) {
		if (ngroups) {
			if ((t = sysconf(_SC_NGROUPS_MAX)) == -1) {
				if (gidset)
					alloc_free((char *) gidset);
				return -1;
			}
		} else
			t = 0;
		old = ngroups;
		for (ptr = groups; *ptr; ptr++) {
			if (*ptr == ',')
				ngroups++;
		}
		ngroups++;
		if (!alloc_re((char *) &gidset, t * sizeof(gid_t), ngroups * sizeof(gid_t)))
			return -1;
		for (i = old, ptr = cptr = groups; *ptr; ptr++) {
			if (*ptr == ',') {
				*ptr = 0;
				if (!isnum(cptr)) {
					if (!(gr = getgrnam(cptr))) {
						t = errno;
						alloc_free((char *) gidset);
						errno = t;
						return -1;
					}
					g = gr->gr_gid;
				} else
					scan_uint(cptr, &g);
				gidset[i++] = g;
				*ptr = ',';
				cptr = ptr + 1;
			}
		}
		if (!isnum(cptr)) {
			if (!(gr = getgrnam(cptr))) {
				t = errno;
				alloc_free((char *) gidset);
				errno = t;
				return -1;
			}
			g = gr->gr_gid;
		} else
			scan_uint(cptr, &g);
		gidset[i++] = g;
	}
	if (ngroups && setgroups(ngroups, gidset)) {
		t = errno;
		alloc_free((char *) gidset);
		errno = t;
		return -1;
	}
	if (ngroups)
		alloc_free((char *) gidset);
	if (setgid(gid))
		return -1;
	else
	if (setuid(uid))
		return -1;
	return (0);
}

int
setuser_privileges(uid_t uid, gid_t gid, char *user)
{
	gid_t          *gidset;
	int             ngroups;

	if (!(gidset = grpscan(user, &ngroups)))
		return -1;
	if (setgroups(ngroups, gidset)) {
		alloc_free((char *) gidset);
		return -1;
	} else
	if (setgid(gid)) {
		alloc_free((char *) gidset);
		return -1;
	} else
	if (setuid(uid)) {
		alloc_free((char *) gidset);
		return -1;
	}
	alloc_free((char *) gidset);
	return (0);
}

void
getversion_setuserid_c()
{
	static char    *x = "$Id: setuserid.c,v 1.7 2023-02-21 00:11:41+05:30 Cprogrammer Exp mbhangui $";

	x++;
}

/*
 * $Log: setuserid.c,v $
 * Revision 1.7  2023-02-21 00:11:41+05:30  Cprogrammer
 * refactored setuserid
 *
 * Revision 1.7  2023-02-20 20:37:53+05:30  Cprogrammer
 * refactored setuserid.c
 *
 * Revision 1.6  2023-02-13 22:35:32+05:30  Cprogrammer
 * rewind passwd file using qsetpwent, setpwent
 *
 * Revision 1.5  2021-07-05 23:27:42+05:30  Cprogrammer
 * use qgepwnam, qgetgrent if USE_QPWGR is set
 *
 * Revision 1.4  2021-07-03 17:57:34+05:30  Cprogrammer
 * corrected using setgrent instead of endpwent
 *
 * Revision 1.3  2020-06-16 16:08:56+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2020-06-16 16:05:56+05:30  Cprogrammer
 * adapted for libqmail
 *
 * Revision 1.1  2019-04-14 21:02:09+05:30  Cprogrammer
 * Initial revision
 *
 */
