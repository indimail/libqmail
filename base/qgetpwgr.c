/*
 * $Log: qgetpwgr.c,v $
 * Revision 1.10  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.9  2023-02-20 20:38:12+05:30  Cprogrammer
 * allow alternate passwd, group, service for uid 0 using env variables
 *
 * Revision 1.8  2022-03-18 13:37:33+05:30  Cprogrammer
 * fixed SIGSEGV caused by byte_copy of extra bytes
 *
 * Revision 1.7  2022-03-09 12:27:21+05:30  Cprogrammer
 * use 4096 as default buffer size on FreeBSD (sysconf _SC_GETPW_R_SIZE_MAX returns -1)
 *
 * Revision 1.6  2021-08-17 20:30:08+05:30  Cprogrammer
 * added arpa/inet.h
 *
 * Revision 1.5  2021-07-10 22:19:17+05:30  Cprogrammer
 * added getservent functions to read /etc/services
 *
 * Revision 1.4  2021-07-09 23:58:00+05:30  Cprogrammer
 * fixed incorrect size passed to alloc_re()
 *
 * Revision 1.3  2021-07-05 18:14:59+05:30  Cprogrammer
 * adjusted errno when returning errors
 *
 * Revision 1.2  2021-07-03 22:05:16+05:30  Cprogrammer
 * fixed SIGSEGV
 *
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
#ifdef HAVE_CTYPE_H
#include <ctype.h>
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
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#include <stralloc.h>
#include <substdio.h>
#include <byte.h>
#include <getln.h>
#include <open.h>
#include <scan.h>
#include <str.h>
#include <alloc.h>
#include <error.h>
#include <env.h>
#include "qgetpwgr.h"

static int      set_pwent, end_pwent, set_grent, end_grent, set_svent, end_svent;
static PASSWD   _pwent;
static GROUP    _grent;
static SERVICE  _svent;

static char    *_pwbuf, *_grbuf, *_svbuf;
static int      _pwbuf_len, _grbuf_len, _svbuf_len;
static char     _pw_inbuf[4096], _gr_inbuf[4096], _sv_inbuf[4096];
static char   **gr_mem_ptr, **sv_alias_ptr;
static int      gr_mem_len, sv_alias_len;
static char    *empty_aliases[] = {0};
static substdio pwss, grss, svss;

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

static void
qpwinit(int flag)
{
	int             i;

	if (!_pwbuf_len) {
#ifdef LINUX
		if ((i = sysconf(_SC_GETPW_R_SIZE_MAX)) == -1) {
			errno = ERANGE;
			return;
		}
#else
		i = 4096;
#endif
		if (!(_pwbuf = (char *) alloc(sizeof(char) * i))) {
			errno = ENOMEM;
			return;
		}
		_pwbuf_len = i * sizeof(char);
	}
	if (!flag)
		return;
	if (!alloc_re(&_pwbuf, sizeof(char) * _pwbuf_len, sizeof(char) * (_pwbuf_len + 512))) {
		errno = ENOMEM;
		return;
	}
	errno = ERANGE;
	_pwbuf_len += 512;
}

int
qgetpwent_r(struct passwd *pwd, char *buf, size_t buflen, struct passwd **result)
{
	int             match, field_count, pos;
	char           *ptr, *cptr;
	static stralloc line = { 0 };
	static int      _is_open, pwfd;

	*result = (struct passwd *) NULL;
	if (end_pwent) {
		close(pwfd);
		end_pwent = _is_open = 0;
	}
	if (!_is_open) {
		ptr = env_get("PASSWD_FILE");
		if (!ptr || !*ptr || getuid())
			ptr = (char *) "/etc/passwd";
		if ((pwfd = open_read(ptr)) == -1)
			return errno;
		_is_open = 1;
		substdio_fdbuf(&pwss, read, pwfd, _pw_inbuf, sizeof (_pw_inbuf));
	}
	if (set_pwent) {
		if (pwss.p)
			pwss.p = 0;
		lseek(pwfd, 0, SEEK_SET);
		set_pwent = 0;
	}
	for (;;) {
		pos = pwss.p;
		if (getln(&pwss, &line, &match, '\n') == -1) {
			close(pwfd);
			_is_open = 0;
			return (errno = ETXTBSY);
		}
		if (!line.len) {
			set_pwent = 1;
			errno = 0;
			return 0;
		}
		if (!match)	  /*- partial line */
			continue;
		if (!stralloc_0(&line)) {
			close(pwfd);
			_is_open = 0;
			return (errno = ENOMEM);
		}
		line.len--;
		for (cptr = line.s;*cptr && isspace(*cptr); cptr++);
		if (!*cptr || *cptr == '#') /*- comment or blank line */
			continue;
		line.s[line.len - 1] = ':'; /*- replace newline with : */
		if (buflen < line.len) {
			pwss.p = pos;
			errno = ERANGE;
			return errno;
		}
		byte_copy(buf, line.len + 1, line.s);
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
	int             i, count;

	for (count = 0;; count++) {
		if ((i = qgetpwent_r(pwd, buf, buflen, result)))
			return i;
		if (!*result) {
			if (count)
				errno = ENOENT;
			return 0;
		}
		if (!str_diff(name, (*result)->pw_name))
			return 0;
	}
	errno = ENOENT;
	return i;
}

int
qgetpwuid_r(uid_t uid, struct passwd *pwd, char *buf, size_t buflen, struct passwd **result)
{
	int             i, count;

	for (count = 0;; count++) {
		if ((i = qgetpwent_r(pwd, buf, buflen, result)))
			return i;
		if (!*result) {
			if (count)
				errno = ENOENT;
			return 0;
		}
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
	int             i, count;

	qpwinit(0);
	for (count = 0;; count++) {
		if ((i = qgetpwent_r(&_pwent, _pwbuf, _pwbuf_len, &result))) {
			if (errno == ERANGE) {
				qpwinit(1);
				continue;
			}
			return ((struct passwd *) NULL);
		}
		if (!result) {
			if (count)
				errno = ENOENT;
			return ((struct passwd *) NULL);
		}
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
	int             i, count;

	qpwinit(0);
	for (count = 0;; count++) {
		if ((i = qgetpwent_r(&_pwent, _pwbuf, _pwbuf_len, &result))) {
			if (errno == ERANGE) {
				qpwinit(1);
				continue;
			}
			return ((struct passwd *) NULL);
		}
		if (!result) {
			if (count)
				errno = ENOENT;
			return ((struct passwd *) NULL);
		}
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
	int             i, count;

	qpwinit(0);
	for (count = 0;; count++) {
		if ((i = qgetpwent_r(&_pwent, _pwbuf, _pwbuf_len, &result))) {
			if (errno == ERANGE) {
				qpwinit(1);
				continue;
			}
			return ((struct passwd *) NULL);
		}
		if (!result) {
			if (!count)
				errno = ENOENT;
			return ((struct passwd *) NULL);
		}
		return (result);
	}
	/*- not reached */
}

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

static void
qgrinit(int flag)
{
	int             i;

	if (!_grbuf_len) {
#ifdef LINUX
		if ((i = sysconf(_SC_GETPW_R_SIZE_MAX)) == -1) {
			errno = ERANGE;
			return;
		}
#else
		i = 4096;
#endif
		if (!(_grbuf = (char *) alloc(sizeof(char) * i))) {
			errno = ENOMEM;
			return;
		}
		_grbuf_len = i * sizeof(char);
	}
	if (!flag)
		return;
	if (!alloc_re(&_grbuf, sizeof(char) * _grbuf_len, sizeof(char) * (_grbuf_len + 512))) {
		errno = ENOMEM;
		return;
	}
	errno = 0;
	_grbuf_len += 512;
}

int
qgetgrent_r(struct group *grp, char *buf, size_t buflen, struct group **result)
{
	int             match, field_count, i, g, pos;
	char           *ptr, *cptr, *x, *y;
	static stralloc line = { 0 };
	static int      _is_open, grfd;

	*result = (struct group *) NULL;
	if (end_grent) {
		close(grfd);
		end_grent = _is_open = 0;
	}
	if (!_is_open) {
		ptr = env_get("GROUP_FILE");
		if (!ptr || !*ptr || getuid())
			ptr = (char *) "/etc/group";
		if ((grfd = open_read(ptr)) == -1)
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
			close(grfd);
			_is_open = 0;
			return (errno = ETXTBSY);
		}
		if (!line.len) {
			set_grent = 1;
			errno = 0;
			return 0;
		}
		if (!match)	  /*- partial line */
			continue;
		if (!stralloc_0(&line)) {
			close(grfd);
			_is_open = 0;
			return (errno = ENOMEM);
		}
		line.len--;
		for (cptr = line.s;*cptr && isspace(*cptr); cptr++);
		if (!*cptr || *cptr == '#') /*- comment or blank line */
			continue;
		line.s[line.len - 1] = ':';
		if (buflen < line.len) {
			grss.p = pos;
			errno = ERANGE;
			return errno;
		}
		byte_copy(buf, line.len + 1, line.s);
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
			while (*cptr && isspace(*cptr))
				cptr++;
			if (*cptr) {
				for (x = cptr, g = 0; *x; x++) {
					if (*x == ',')
						g++;
				}
				if (!alloc_re(&gr_mem_ptr, sizeof(char *) * gr_mem_len, sizeof(char *) * (g + 1)))
					return errno;
				gr_mem_len = g + 1;
				for (x = y = cptr, i = 0; *x; x++) {
					if (*x == ',') {
						*x++ = 0;
						gr_mem_ptr[i++] = y;
						while (*x && isspace(*x))
							x++;
						y = x;
					} else
					if (isspace(*x))
						*x = 0;
				}
				if (*y)
					gr_mem_ptr[i++] = y;
				gr_mem_ptr[i] = NULL;
			} else {
				if (!alloc_re(&gr_mem_ptr, sizeof(char *) * gr_mem_len, sizeof(char *)))
					return errno;
				gr_mem_len = 1;
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
	int             i, count;

	for (count = 0;; count++) {
		if ((i = qgetgrent_r(grp, buf, buflen, result)))
			return i;
		if (!*result) {
			if (count)
				errno = ENOENT;
			return errno;
		}
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
	int             i, count;

	for (count = 0;; count++) {
		if ((i = qgetgrent_r(grp, buf, buflen, result)))
			return i;
		if (!*result) {
			if (count)
				errno = ENOENT;
			return errno;
		}
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
	int             i, count;

	qgrinit(0);
	for (count = 0;; count++) {
		if ((i = qgetgrent_r(&_grent, _grbuf, _grbuf_len, &result))) {
			if (errno == ERANGE) {
				qgrinit(1);
				continue;
			}
			return ((struct group *) NULL);
		}
		if (!result) {
			if (count)
				errno = ENOENT;
			return ((struct group *) NULL);
		}
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
	int             i, count;

	qgrinit(0);
	for (count = 0;; count++) {
		if ((i = qgetgrent_r(&_grent, _grbuf, _grbuf_len, &result))) {
			if (errno == ERANGE) {
				qgrinit(1);
				continue;
			}
			return ((struct group *) NULL);
		}
		if (!result) {
			if (count)
				errno = ENOENT;
			return ((struct group *) NULL);
		}
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
	int             i, count;

	qgrinit(0);
	for (count = 0;; count++) {
		if ((i = qgetgrent_r(&_grent, _grbuf, _grbuf_len, &result))) {
			if (errno == ERANGE) {
				qgrinit(1);
				continue;
			}
			return ((struct group *) NULL);
		}
		if (!result) {
			if (!count)
				errno = ENOENT;
			return ((struct group *) NULL);
		}
		return (result);
	}
	/*- not reached */
}

void
qsetservent()
{
	set_svent = 1;
}

void
qendservent()
{
	end_svent = 1;
}

static void
qsvinit(int flag)
{
	int             i;

	if (!_svbuf_len) {
		i = 1024;
		if (!(_svbuf = (char *) alloc(sizeof(char) * i))) {
			errno = ENOMEM;
			return;
		}
		_svbuf_len = i * sizeof(char);
	}
	if (!flag)
		return;
	if (!alloc_re(&_svbuf, sizeof(char) * _svbuf_len, sizeof(char) * (_svbuf_len + 512))) {
		errno = ENOMEM;
		return;
	}
	errno = ERANGE;
	_svbuf_len += 512;
}

int
qgetservent_r(struct servent *svc, char *buf, size_t buflen, struct servent **result)
{
	int             match, field_count, pos, i, s, end = 0;
	char           *ptr, *cptr, *x, *y;
	static stralloc line = { 0 };
	static int      _is_open, svfd;

	*result = (struct servent *) NULL;
	if (end_svent) {
		close(svfd);
		end_svent = _is_open = 0;
	}
	if (!_is_open) {
		ptr = env_get("SERVICE_FILE");
		if (!ptr || !*ptr || getuid())
			ptr = (char *) "/etc/services";
		if ((svfd = open_read(ptr)) == -1)
			return errno;
		_is_open = 1;
		substdio_fdbuf(&svss, read, svfd, _sv_inbuf, sizeof (_sv_inbuf));
	}
	if (set_svent) {
		if (svss.p)
			svss.p = 0;
		lseek(svfd, 0, SEEK_SET);
		set_svent = 0;
	}
	for (;;) {
		pos = svss.p;
		if (getln(&svss, &line, &match, '\n') == -1) {
			close(svfd);
			_is_open = 0;
			return (errno = ETXTBSY);
		}
		if (!line.len) {
			set_svent = 1;
			errno = 0;
			return 0;
		}
		if (!match)	  /*- partial line */
			continue;
		if (line.len == 1)
			continue;
		line.s[line.len] = 0; /*- null terminate for str_chr */
		pos = str_chr(line.s, '#');
		if (!pos)
			continue;
		if (line.s[pos]) {
			line.s[pos] = 0;
			pos--;
			while (pos >= 0 && isspace(line.s[pos]))
				pos--;
			if (pos == -1)
				continue;
		} else {
			pos = line.len - 2; /*- before the \n */
			while (pos && isspace(line.s[pos]))
				pos--;
		}
		line.len = pos + 1;
		if (!stralloc_append(&line, "\n") || !stralloc_0(&line)) {
			close(svfd);
			_is_open = 0;
			return (errno = ENOMEM);
		}
		if (buflen < line.len) {
			svss.p = pos;
			errno = ERANGE;
			return errno;
		}
		byte_copy(buf, line.len, line.s);
		break;
	}
	buf[line.len] = 0;
	/*
	 * echo            7/udp\n
	 * discard         9/tcp           sink null\n
	 */
	for (field_count = 0, cptr = ptr = buf; *ptr; ptr++) {
		if (isspace(*ptr)) {
			field_count++;
			if (field_count < 3) {
				*ptr++ = 0;
				while (*ptr && isspace(*ptr))
					ptr++;
				if (*ptr && !isspace(*ptr))
					ptr--;
				else
				if (!*ptr) { /*- no aliases */
					svc->s_aliases = empty_aliases;
					end = 1;
				}
			} else /*- there are aliases */
				end = 1;
		} else
			continue;
		switch (field_count)
		{
		case 1:/*- service */
			svc->s_name = cptr;
			break;
		case 2:/*- port/service */
			scan_int(cptr, &i);
			svc->s_port = htons(i);
			i = str_rchr(cptr, '/');
			if (cptr[i + 1])
				svc->s_proto = cptr + i + 1;
			else
				svc->s_proto = 0;
			break;
		case 3:/*- aliases */
			while (*cptr && isspace(*cptr))
				cptr++;
			if (*cptr) {
				for (x = cptr, s = 0; *x; x++) {
					if (isspace(*x)) {
						s++;
						while (isspace(*x))
							x++;
					}
				}
				if (!alloc_re(&sv_alias_ptr, sizeof(char *) * sv_alias_len, sizeof(char *) * (s + 1)))
					return errno;
				sv_alias_len = s + 1;
				for (x = y = cptr, i = 0; *x; x++) {
					if (isspace(*x)) {
						*x++ = 0;
						sv_alias_ptr[i++] = y;
						while (*x && isspace(*x))
							x++;
						y = x;
					}
				}
				if (*y)
					sv_alias_ptr[i++] = y;
				sv_alias_ptr[i] = NULL;
				svc->s_aliases = sv_alias_ptr;
			} else
				svc->s_aliases = empty_aliases;
			break;
		}
		if (end) {
			*result = svc;
			errno = 0;
			return 0;
		}
		cptr = ptr + 1;
	}
	set_svent = 1;
	errno = ENOENT;
	return 0;
}

int
qgetservbyname_r(const char *name, const char *proto, struct servent *svc,
		char *buf, size_t buflen, struct servent **result)
{
	int             i, count;

	for (count = 0;; count++) {
		if ((i = qgetservent_r(svc, buf, buflen, result)))
			return i;
		if (!*result) {
			if (count)
				errno = ENOENT;
			return errno;
		}
		if (!str_diff(name, (*result)->s_name)) {
			if (!proto)
				return 0;
			if (!str_diff(proto, (*result)->s_proto))
				return 0;
		}
	}
	errno = ENOENT;
	return i;
}

int
qgetservbyport_r(int port, const char *proto, struct servent *svc,
		char *buf, size_t buflen, struct servent **result)
{
	int             i, count;

	for (count = 0;; count++) {
		if ((i = qgetservent_r(svc, buf, buflen, result)))
			return i;
		if (!*result) {
			if (count)
				errno = ENOENT;
			return errno;
		}
		if (port == (*result)->s_port) {
			if (!proto)
				return 0;
			if (!str_diff(proto, (*result)->s_proto))
				return 0;
		}
	}
	errno = ENOENT;
	return i;
}

struct servent  *
qgetservbyname(const char *name, const char *proto)
{
	struct servent *result;
	int             i, count;

	qsvinit(0);
	for (count = 0;; count++) {
		if ((i = qgetservent_r(&_svent, _svbuf, _svbuf_len, &result))) {
			if (errno == ERANGE) {
				qsvinit(1);
				continue;
			}
			return ((struct servent *) NULL);
		}
		if (!result) {
			if (count)
				errno = ENOENT;
			return ((struct servent *) NULL);
		}
		if (!str_diff(name, result->s_name)) {
			if (!proto)
				return (result);
			if (!str_diff(proto, result->s_proto))
				return (result);
		}
	}
	errno = ENOENT;
	return ((struct servent *) NULL);
}

struct servent  *
qgetservbyport(int port, const char *proto)
{
	struct servent *result;
	int             i, count;

	qsvinit(0);
	for (count = 0;; count++) {
		if ((i = qgetservent_r(&_svent, _svbuf, _svbuf_len, &result))) {
			if (errno == ERANGE) {
				qsvinit(1);
				continue;
			}
			return ((struct servent *) NULL);
		}
		if (!result) {
			if (count)
				errno = ENOENT;
			return ((struct servent *) NULL);
		}
		if (port == result->s_port) {
			if (!proto)
				return (result);
			if (!str_diff(proto, result->s_proto))
				return (result);
		}
	}
	errno = ENOENT;
	return ((struct servent *) NULL);
}

struct servent *
qgetservent()
{
	struct servent *result;
	int             i, count;

	qsvinit(0);
	for (count = 0;; count++) {
		if ((i = qgetservent_r(&_svent, _svbuf, _svbuf_len, &result))) {
			if (errno == ERANGE) {
				qsvinit(1);
				continue;
			}
			return ((struct servent *) NULL);
		}
		if (!result) {
			if (!count)
				errno = ENOENT;
			return ((struct servent *) NULL);
		}
		return (result);
	}
	/*- not reached */
}

void
getversion_qgetpwgr_c()
{
	const char     *x = "$Id: qgetpwgr.c,v 1.10 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
