/*
 * $Log: envdir.c,v $
 * Revision 1.10  2021-07-16 16:21:26+05:30  Cprogrammer
 * treat openreadclose returning 0 as an error
 *
 * Revision 1.9  2021-07-14 13:13:59+05:30  Cprogrammer
 * added option to ignore read errors and eliminate use of chdir
 *
 * Revision 1.8  2021-07-13 23:19:59+05:30  Cprogrammer
 * return directory/file names in error
 *
 * Revision 1.7  2021-07-12 17:30:29+05:30  Cprogrammer
 * added feature to process .envfile and .envdir as a file containing list of directories
 *
 * Revision 1.6  2021-07-11 23:20:33+05:30  Cprogrammer
 * set variables from .envdir first to prevent .envdir from overriding main
 *
 * Revision 1.5  2021-07-07 20:02:16+05:30  Cprogrammer
 * do lstat after chdir to fix false recursive loop error
 *
 * Revision 1.4  2021-06-30 14:15:59+05:30  Cprogrammer
 * hyperlink feature using .envdir link/dir to traverse multiple directories
 *
 * Revision 1.3  2021-05-13 12:20:47+05:30  Cprogrammer
 * refactored envdir_set and renamed to envdir
 *
 * Revision 1.2  2021-05-12 18:51:24+05:30  Cprogrammer
 * fixed error message
 *
 * Revision 1.1  2010-06-08 19:06:28+05:30  Cprogrammer
 * Initial revision
 *
 */
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "alloc.h"
#include "error.h"
#include "envdir.h"
#include "str.h"
#include "open.h"
#include "pathexec.h"
#include "openreadclose.h"
#include "byte.h"
#include "direntry.h"
#include "stralloc.h"

static stralloc sa;

char *
envdir_str(int code)
{
	switch (code)
	{
		case -1:
			return "unable to open environment file";
		case -2:
			return "unable to open environment directory";
		case -3:
			return "unable to read environment directory";
		case -4:
			return "unable to open .envdir";
		case -5:
			return "unable to open .envfile";
		case -6:
			return "out of memory";
		case -7:
			return "recursive loop";
	}
	return "unkown error";
}

int
if_visited(ino_t inum)
{
	int            i;
	static ino_t  *ino_ptr;
	static int     ino_count;

	if (ino_ptr) {
		for (i = 0; i < ino_count; i++) {
			if (ino_ptr[i] == inum)
				return 1;
		}
		if (!alloc_re(&ino_ptr, sizeof(ino_t) * ino_count, sizeof(ino_t) * (ino_count + 1)))
			return -6; /*- out of memory */
	} else {
		if (!(ino_ptr = (ino_t *) alloc(sizeof(ino_t) * (ino_count + 1))))
			return -6; /*- out of memory */
	}
	ino_ptr[ino_count++] = inum;
	return 0;
}

int
process_dot_envfile(char *fn, char **e, int ignore_unreadable, int *unreadable)
{
	struct stat     st;
	char           *ptr, *cptr;
	int             i, j;

	if (lstat(fn, &st)) { /*- read file having env1=var1 lines */
		if (errno == error_noent)
			return 0;
		(*unreadable)++;
		if (e)
			*e = fn;
		return (ignore_unreadable ? 0 : -5);
	}
	switch (st.st_mode & S_IFMT)
	{
	case S_IFDIR: /*- ignore */
		break;
	case S_IFREG:
		i = openreadclose(fn, &sa, st.st_size);
		if (i == -1 || !i) {
			(*unreadable)++;
			if (e)
				*e = fn;
			return (ignore_unreadable ? 0 : -4);
		}
		if (!sa.len)
			break;
		sa.len = byte_chr(sa.s, sa.len, '\n');
		for (i = 0; i < sa.len; ++i) {
			if (!sa.s[i])
				sa.s[i] = '\n';
		}
		for (cptr = ptr = sa.s; *cptr; cptr++) {
			if (*cptr != '\n')
				continue;
			*cptr = 0;
			i = str_chr(ptr, '=');
			if (ptr[i]) {
				ptr[i] = 0;
				j = str_rchr(ptr + i, ' ');
				if (ptr[i + j])
					ptr[i + j] = 0;
				j = str_rchr(ptr + i, '\t');
				if (ptr[i + j])
					ptr[i + j] = 0;
				if (!pathexec_env(ptr, ptr + i + 1)) { /*- set variable */
					if (e)
						*e = error_str(errno);
					return -6;
				}
			} else
			if (!pathexec_env(ptr, 0)) { /*- remove variable */
				if (e)
					*e = error_str(errno);
				return -6;
			}
			*cptr = '\n';
			ptr = cptr + 1;
		} /* for (cptr = ptr = sa.s; *cptr; cptr++) */
		break;
	}
	return 0;
}

int
process_dot_envdir(char *fn, char **e, int ignore_unreadable, int *unreadable)
{
	struct stat     st;
	char           *ptr, *cptr;
	int             i;

	if (lstat(fn, &st)) {
		if (errno == error_noent)
			return 0;
		(*unreadable)++;
		if (e)
			*e = fn;
		return (ignore_unreadable ? 0 : -4);
	}
	switch (st.st_mode & S_IFMT)
	{
	case S_IFDIR:
		if ((i = envdir(fn, e, ignore_unreadable, unreadable)))
			return (i);
		break;
	case S_IFREG:
		i = openreadclose(fn, &sa, st.st_size);
		if (i == -1 || !i) {
			(*unreadable)++;
			if (e)
				*e = fn;
			return (ignore_unreadable ? 0 : -4);
		}
		if (!sa.len)
			break;
		for (cptr = ptr = sa.s; *cptr; cptr++) {
			if (*cptr != '\n')
				continue;
			*cptr = 0;
			if ((i = envdir(ptr, e, ignore_unreadable, unreadable)))
				return i;
			*cptr = '\n';
			ptr = cptr + 1;
		}
		break;
	}
	return 0;
}

void
exit_nicely(char *d, DIR *dir)
{
	int             i;

	i = errno;
	alloc_free(d);
	pathexec_clear();
	if (dir)
		closedir(dir);
	errno = i;
}

int
envdir(char *fn, char **e, int ignore_unreadable, int *unreadable)
{
	DIR            *dir;
	direntry       *dt;
	struct stat     st;
	int             i, j, alen, len;
	char           *d;

	if (lstat(fn, &st) == -1) {
		if (e)
			*e = fn;
		return -2;
	}
	/*- add current directory to visited list */
	if ((j = if_visited(st.st_ino)) == -6) {
		if (e)
			*e = error_str(errno);
		return -6;
	} else
	if (j) /*- recursive loop detected. Ignore and return */
		return 0;
	alen = (len = str_len(fn)) + 10; /*- str_len(fn) + str_len("/.envfile") + 1 */
	if (!(d = alloc(alen))) {
		if (e)
			*e = error_str(errno);
		return -6;
	}
	str_copy(d, fn);
	str_copy(d + len, "/.envfile");
	if ((j = process_dot_envfile(d, e, ignore_unreadable, unreadable))) {
		exit_nicely(d, 0);
		return j;
	}
	/*- 
	 * if .envdir exists, set variables from it before
	 * setting from current directory. This is to prevent
	 * env variables in .envdir to override existing 
	 * variables in current directory
	 */
	str_copy(d, fn);
	str_copy(d + len, "/.envdir");
	if ((j = process_dot_envdir(d, e, ignore_unreadable, unreadable))) {
		exit_nicely(d, 0);
		return j;
	}
	d[len] = 0; /*- fn */
	if (!(dir = opendir(d))) {
		if (e)
			*e = fn;
		exit_nicely(d, 0);
		return -2; /*- unable to read env directory */
	}
	for (;;) {
		errno = 0;
		if (!(dt = readdir(dir))) {
			if (errno) { /*- error occured */
				if (e)
					*e = fn;
				exit_nicely(d, dir);
				return -3; /*- unable to read env directory */
			}
			break; /*- no more dir entries */
		}
		if (dt->d_name[0] == '.')
			continue;
		if (!alloc_re(&d, alen, len + str_len(dt->d_name) + 2)) {
			if (e)
				*e = error_str(errno);
			exit_nicely(d, dir);
			return -6; /*- out of memory */
		}
		alen = len + str_len(dt->d_name) + 2;
		str_copy(d + len, "/");
		str_copy(d + len + 1, dt->d_name);
		i = openreadclose(d, &sa, 256);
		if (i == -1 || !i) {
			(*unreadable)++;
			if (ignore_unreadable)
				continue;
			i = errno;
			if (!stralloc_copyb(&sa, d, alen)) {
				errno = i;
				if (e)
					*e = "unreadable file found";
			} else
			if (e)
				*e = sa.s;
			errno = i;
			exit_nicely(d, dir);
			return -1;
		}
		if (sa.len) {
			sa.len = byte_chr(sa.s, sa.len, '\n');
			while (sa.len) {
				if (sa.s[sa.len - 1] != ' ' && sa.s[sa.len - 1] != '\t')
					break;
				--sa.len;
			}
			for (i = 0; i < sa.len; ++i) {
				if (!sa.s[i])
					sa.s[i] = '\n';
			}
			if (!stralloc_0(&sa)) {
				if (e)
					*e = error_str(errno);
				exit_nicely(d, dir);
				return -6; /*- out of memory */
			}
			if (!pathexec_env(dt->d_name, sa.s)) { /*- set variable */
				if (e)
					*e = error_str(errno);
				exit_nicely(d, dir);
				return -6;
			}
		} else
		if (!pathexec_env(dt->d_name, 0)) { /*- remove variable */
			if (e)
				*e = error_str(errno);
			exit_nicely(d, dir);
			return -6;
		}
	}
	alloc_free(d);
	closedir(dir);
	return 0;
}

void
getversion_envdir_c()
{
	static char    *x = "$Id: envdir.c,v 1.10 2021-07-16 16:21:26+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
