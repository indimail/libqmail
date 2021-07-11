/*
 * $Log: envdir.c,v $
 * Revision 1.6  2021-07-11 23:20:33+05:30  Cprogrammer
 * set variables from .dir first to prevent .dir from overriding main
 *
 * Revision 1.5  2021-07-07 20:02:16+05:30  Cprogrammer
 * do lstat after chdir to fix false recursive loop error
 *
 * Revision 1.4  2021-06-30 14:15:59+05:30  Cprogrammer
 * hyperlink feature using .dir link/dir to traverse multiple directories
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
			return "unable to open current directory";
		case -3:
			return "unable to switch to environment directory";
		case -4:
			return "unable to read environment directory";
		case -5:
			return "unable to switch back to original directory";
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
envdir(char *fn, char **e)
{
	DIR            *dir;
	direntry       *d;
	struct stat     st;
	int             i, j, fdorigdir;

	if ((fdorigdir = open_read(".")) == -1)
		return -2; /*- unable open current directory */
	if (chdir(fn) == -1)
		return -3; /*- unable to switch to directory */
	if (lstat(".", &st) == -1)
		return -2;
	/*- add current directory to visited list */
	if ((j = if_visited(st.st_ino)) == -6)
		return -6;
	else
	if (j)
		return -7; /*- recursive loop detected */
	/*- 
	 * if .dir exists, set variables from it before
	 * setting from current directory. This is to prevent
	 * env variables in .dir to override existing 
	 * variables in current directory
	 */
	if (!access(".dir", X_OK) && (i = envdir(".dir", e)))
		return (i);
	if (!(dir = opendir(".")))
		return -4; /*- unable to read env directory */
	for (;;) {
		errno = 0;
		if (!(d = readdir(dir))) {
			if (errno)
				return -4; /*- unable to read env directory */
			break;
		}
		if (d->d_name[0] == '.')
			continue;
		if (openreadclose(d->d_name, &sa, 256) == -1) {
			if (e)
				*e = d->d_name;
			return -1; /*- unable to read */
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
			if (!stralloc_0(&sa))
				return -6; /*- out of memory */
			if (!pathexec_env(d->d_name, sa.s)) /*- set variable */
				return -6;
		} else
		if (!pathexec_env(d->d_name, 0)) /*- remove variable */
			return -6;
	}
	closedir(dir);
	if (fchdir(fdorigdir) == -1)
		return -5; /*- unable to switch back to original directory */
	close(fdorigdir);
	return 0;
}

void
getversion_envdir_c()
{
	static char    *x = "$Id: envdir.c,v 1.6 2021-07-11 23:20:33+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
