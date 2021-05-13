/*
 * $Log: envdir.c,v $
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
#include "error.h"
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
	}
	return "unkown error";
}

int
envdir(char *fn, char **e)
{
	DIR            *dir;
	direntry       *d;
	int             i, fdorigdir;

	if ((fdorigdir = open_read(".")) == -1)
		return -2; /*- unable open current directory */
	if (chdir(fn) == -1)
		return -3; /*- unable to switch to directory */
	if (!(dir = opendir(".")))
		return -4; /*- unable to read env directory */
	for (;;) {
		errno = 0;
		if (!(d = readdir(dir))) {
			if (errno)
				return -4; /*- unable to read env directory */
			break;
		}
		if (d->d_name[0] != '.') {
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
				if (!pathexec_env(d->d_name, sa.s))
					return -6;
			} else
			if (!pathexec_env(d->d_name, 0))
				return -6;
		}
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
	static char    *x = "$Id: envdir.c,v 1.3 2021-05-13 12:20:47+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
