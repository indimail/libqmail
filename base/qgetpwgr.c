/*
 * $Log: qgetpwgr.c,v $
 * Revision 1.1  2021-07-03 17:52:50+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_STDDEF_H
#include <stddef.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_PWD_H
#include <pwd.h>
#endif
#ifdef HAVE_GRP_H
#include <grp.h>
#endif
#include <stralloc.h>
#include <substdio.h>
#include <byte.h>
#include <getln.h>
#include <open.h>
#include <scan.h>
#include <str.h>
#include <alloc.h>
#include "qgetpwgr.h"

static int      set_pwent, end_pwent, set_grent, end_grent;
static PASSWD   _pwent;
static GROUP    _grent;
static char    *_pwbuf, *_grbuf;
static int      _pwbuf_len, _grbuf_len;
static char     _pw_inbuf[4096], _gr_inbuf[4096];
static char   **gr_mem_ptr;
static int      gr_mem_len;
static substdio pwss, grss;


void
qsetgrent()
{
	set_grent = 1;
}

void
qendgrent()
{
	end_grent = 1;
}

void
qsetpwent()
{
	set_pwent = 1;
}

void
qendpwent()
{
	end_pwent = 1;
}

void
qgrinit(int flag)
{
	int             i;

	if (!_grbuf_len) {
		if ((i = sysconf(_SC_GETPW_R_SIZE_MAX)) == -1) {
			errno = ERANGE;
			return;
		}
		if (!(_grbuf = (char *) alloc(sizeof(char) * i))) {
			errno = ERANGE;
			return;
		}
		_grbuf_len = i;
	}
	if (!flag)
		return;
	if (!alloc_re(&_grbuf, _grbuf_len, _grbuf_len + 512)) {
		errno = ERANGE;
		return;
	}
	errno = 0;
	_grbuf_len += 512;
}

void
qpwinit(int flag)
{
	int             i;

	if (!_pwbuf_len) {
		if ((i = sysconf(_SC_GETPW_R_SIZE_MAX)) == -1) {
			errno = ERANGE;
			return;
		}
		if (!(_pwbuf = (char *) alloc(sizeof(char) * i))) {
			errno = ERANGE;
			return;
		}
		_pwbuf_len = i;
	}
	if (!flag)
		return;
	if (!alloc_re(&_pwbuf, _pwbuf_len, _pwbuf_len + 512)) {
		errno = ERANGE;
		return;
	}
	errno = ERANGE;
	_pwbuf_len += 512;
}

int
qgetgrent_r(struct group *grp, char *buf, size_t buflen, struct group **result)
{
	int             match, field_count, sv, i, g, pos;
	char           *ptr, *cptr, *x, *y;
	static stralloc line = { 0 };
	static int      _is_open, grfd;

	*result = (struct group *) NULL;
	if (end_grent) {
		close(grfd);
		end_grent = _is_open = 0;
	}
	if (!_is_open) {
		if ((grfd = open_read("/etc/group")) == -1)
			return errno;
		_is_open = 1;
		substdio_fdbuf(&grss, read, grfd, _gr_inbuf, sizeof (_gr_inbuf));
	}
	if (set_grent) {
		if (grss.p) {
			grss.p = 0;
		}
		lseek(grfd, 0, SEEK_SET);
		set_grent = 0;
	}
	for (;;) {
		pos = grss.p;
		if (getln(&grss, &line, &match, '\n') == -1) {
			sv = errno;
			close(grfd);
			_is_open = 0;
			return (errno = sv);
		}
		if (!line.len) {
			set_grent = 1;
			return 0;
		}
		if (!match)	  /*- partial line */
			continue;
		line.s[line.len - 1] = ':';
		if (!stralloc_0(&line)) {
			sv = errno;
			close(grfd);
			_is_open = 0;
			return (errno = sv);
		}
		line.len--;
		if (buflen < line.len) {
			errno = ERANGE;
			grss.p = pos;
			return errno;
		}
		byte_copy(buf, buflen, line.s);
		break;
	}
	/*- qmail:x:1015:apache,mbhangui,qscand */
	for (field_count = 0, cptr = ptr = buf; *ptr; ptr++) {
		if (*ptr == ':') {
			field_count++;
			*ptr = 0;
		} else
			continue;
		switch (field_count) {
		case 1:/*- group */
			grp->gr_name = cptr;
			break;
		case 2:/*- passwd */
			grp->gr_passwd = cptr;
			break;
		case 3:/*- gid */
			scan_uint(cptr, &(grp->gr_gid));
			break;
		case 4:/*- members */
			if (*cptr) {
				for (x = cptr, g = 0; *x; x++) {
					if (*x == ',')
						g++;
				}
				if (!alloc_re(&gr_mem_ptr, gr_mem_len, g + 1))
					return errno;
				if (gr_mem_len < g + 1)
					gr_mem_len = g + 1;
				for (x = y = cptr, i = 0; *x; x++) {
					if (*x == ',') {
						*x = 0;
						gr_mem_ptr[i++] = y;
						y = x + 1;
					}
				}
				gr_mem_ptr[i++] = y;
				gr_mem_ptr[i] = NULL;
			} else {
				if (!alloc_re(&gr_mem_ptr, gr_mem_len, 1))
					return errno;
				gr_mem_ptr[0] = NULL;
			}
			grp->gr_mem = gr_mem_ptr;
			break;
		}
		if (field_count == 4) {
			*result = grp;
			errno = 0;
			return 0;
		}
		cptr = ptr + 1;
	}
	set_grent = 1;
	errno = ENOENT;
	return 0;
}

int
qgetgrnam_r(const char *name, struct group *grp,
	char *buf, size_t buflen, struct group **result)
{
	int             i;

	for (;;) {
		if ((i = qgetgrent_r(grp, buf, buflen, result)))
			return i;
		if (!*result)
			return 0;
		if (!str_diff(name, (*result)->gr_name))
			return 0;
	}
	errno = ENOENT;
	return i;
}

int
qgetgrgid_r(gid_t gid, struct group *grp, char *buf,
	size_t buflen, struct group **result)
{
	int             i;

	for (;;) {
		if ((i = qgetgrent_r(grp, buf, buflen, result)))
			return i;
		if (!*result)
			return 0;
		if (gid == (*result)->gr_gid)
			return 0;
	}
	errno = ENOENT;
	return i;
}

struct group   *
qgetgrnam(const char *name)
{
	struct group   *result;
	int             i;

	qgrinit(0);
	for (;;) {
		if ((i = qgetgrent_r(&_grent, _grbuf, _grbuf_len, &result))) {
			if (errno == ERANGE) {
				qgrinit(1);
				continue;
			}
			return ((struct group *) NULL);
		}
		if (!result)
			return ((struct group *) NULL);
		if (!str_diff(name, result->gr_name))
			return (result);
	}
	errno = ENOENT;
	return ((struct group *) NULL);
}

struct group   *
qgetgrgid(gid_t gid)
{
	struct group   *result;
	int             i;

	qgrinit(0);
	for (;;) {
		if ((i = qgetgrent_r(&_grent, _grbuf, _grbuf_len, &result))) {
			if (errno == ERANGE) {
				qgrinit(1);
				continue;
			}
			return ((struct group *) NULL);
		}
		if (!result)
			return ((struct group *) NULL);
		if (gid == result->gr_gid)
			return (result);
	}
	errno = ENOENT;
	return ((struct group *) NULL);
}

struct group   *
qgetgrent()
{
	struct group   *result;
	int             i;

	qgrinit(0);
	for (;;) {
		if ((i = qgetgrent_r(&_grent, _grbuf, _grbuf_len, &result))) {
			if (errno == ERANGE) {
				qgrinit(1);
				continue;
			}
			return ((struct group *) NULL);
		}
		if (!result)
			return ((struct group *) NULL);
		return (result);
	}
	/*- not reached */
}

int
qgetpwent_r(struct passwd *pwd, char *buf, size_t buflen, struct passwd **result)
{
	int             match, field_count, sv, pos;
	char           *ptr, *cptr;
	static stralloc line = { 0 };
	static int      _is_open, pwfd;

	*result = (struct passwd *) NULL;
	if (end_pwent) {
		close(pwfd);
		end_pwent = _is_open = 0;
	}
	if (!_is_open) {
		if ((pwfd = open_read("/etc/passwd")) == -1)
			return errno;
		_is_open = 1;
		substdio_fdbuf(&pwss, read, pwfd, _pw_inbuf, sizeof (_pw_inbuf));
	}
	if (set_pwent) {
		if (pwss.p) {
			pwss.p = 0;
		}
		lseek(pwfd, 0, SEEK_SET);
		set_pwent = 0;
	}
	for (;;) {
		pos = pwss.p;
		if (getln(&pwss, &line, &match, '\n') == -1) {
			sv = errno;
			close(pwfd);
			_is_open = 0;
			return (errno = sv);
		}
		if (!line.len) {
			set_pwent = 1;
			errno = ENOENT;
			return 0;
		}
		if (!match)	  /*- partial line */
			continue;
		line.s[line.len - 1] = ':';
		if (!stralloc_0(&line)) {
			sv = errno;
			close(pwfd);
			_is_open = 0;
			return (errno = sv);
		}
		line.len--;
		if (buflen < line.len) {
			pwss.p = pos;
			errno = ERANGE;
			return errno;
		}
		byte_copy(buf, buflen, line.s);
		break;
	}
	/*- root:x:0:0:root:/root:/bin/bash: */
	for (field_count = 0, cptr = ptr = buf; *ptr; ptr++) {
		if (*ptr == ':') {
			field_count++;
			*ptr = 0;
		} else
			continue;
		switch (field_count) {
		case 1:/*- user */
			pwd->pw_name = cptr;
			break;
		case 2:/*- passwd */
			pwd->pw_passwd = cptr;
			break;
		case 3:/*- uid */
			scan_uint(cptr, &(pwd->pw_uid));
			break;
		case 4:/*- gid */
			scan_uint(cptr, &(pwd->pw_gid));
			break;
		case 5:/*- getcos */
			pwd->pw_gecos = cptr;
			break;
		case 6:/*- home */
			pwd->pw_dir = cptr;
			break;
		case 7:/*- shell */
			pwd->pw_shell = cptr;
			break;
		}
		if (field_count == 7) {
			*result = pwd;
			errno = 0;
			return 0;
		}
		cptr = ptr + 1;
	}
	set_pwent = 1;
	errno = ENOENT;
	return 0;
}

int
qgetpwnam_r(const char *name, struct passwd *pwd, char *buf, size_t buflen, struct passwd **result)
{
	int             i;

	for (;;) {
		if ((i = qgetpwent_r(pwd, buf, buflen, result)))
			return i;
		if (!*result)
			return 0;
		if (!str_diff(name, (*result)->pw_name))
			return 0;
	}
	errno = ENOENT;
	return i;
}

int
qgetpwuid_r(uid_t uid, struct passwd *pwd, char *buf, size_t buflen, struct passwd **result)
{
	int             i;

	for (;;) {
		if ((i = qgetpwent_r(pwd, buf, buflen, result)))
			return i;
		if (!*result)
			return 0;
		if (uid == (*result)->pw_uid)
			return 0;
	}
	errno = ENOENT;
	return i;
}

struct passwd  *
qgetpwnam(const char *name)
{
	struct passwd  *result;
	int             i;

	qpwinit(0);
	for (;;) {
		if ((i = qgetpwent_r(&_pwent, _pwbuf, _pwbuf_len, &result))) {
			if (errno == ERANGE) {
				qpwinit(1);
				continue;
			}
			return ((struct passwd *) NULL);
		}
		if (!result)
			return ((struct passwd *) NULL);
		if (!str_diff(name, result->pw_name))
			return (result);
	}
	errno = ENOENT;
	return ((struct passwd *) NULL);
}

struct passwd  *
qgetpwuid(uid_t uid)
{
	struct passwd  *result;
	int             i;

	qpwinit(0);
	for (;;) {
		if ((i = qgetpwent_r(&_pwent, _pwbuf, _pwbuf_len, &result))) {
			if (errno == ERANGE) {
				qpwinit(1);
				continue;
			}
			return ((struct passwd *) NULL);
		}
		if (!result)
			return ((struct passwd *) NULL);
		if (uid == result->pw_uid)
			return (result);
	}
	/*- not reached */
	errno = ENOENT;
	return ((struct passwd *) NULL);
}

struct passwd  *
qgetpwent()
{
	struct passwd  *result;
	int             i;

	qpwinit(0);
	for (;;) {
		if ((i = qgetpwent_r(&_pwent, _pwbuf, _pwbuf_len, &result))) {
			if (errno == ERANGE) {
				qpwinit(1);
				continue;
			}
			return ((struct passwd *) NULL);
		}
		if (!result)
			return ((struct passwd *) NULL);
		return (result);
	}
	/*- not reached */
}

void
getversion_qgetpwgr_c()
{
	static char    *x = "$Id: qgetpwgr.c,v 1.1 2021-07-03 17:52:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
