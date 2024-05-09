/*
 * $Log: sgetopt.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2020-11-23 18:04:36+05:30  Cprogrammer
 * use const keyword for options argument
 *
 *
 * sgetopt.c, sgetopt.h: (yet another) improved getopt clone, outer layer
 * D. J. Bernstein, djb@pobox.com.
 * Depends on subgetopt.h, substdio.h, subfd.h.
 * No system requirements.
 * 19970208: Cleanups.
 * 931201: Baseline.
 * No known patent problems.
 * 
 * Documentation in sgetopt.3.
 */

#include "substdio.h"
#include "subfd.h"
#define SGETOPTNOSHORT
#include "sgetopt.h"
#define SUBGETOPTNOSHORT
#include "subgetopt.h"

#define getopt sgetoptmine
#define optind subgetoptind
#define opterr sgetopterr
#define optproblem subgetoptproblem
#define optprogname sgetoptprogname

int             opterr = 1;
const char     *optprogname = 0;

int
getopt(int argc, char **argv, const char *opts)
{
	int             c;
	const char     *s;

	if (!optprogname) {
		optprogname = *argv;
		if (!optprogname)
			optprogname = "";
		for (s = optprogname; *s; ++s)
			if (*s == '/')
				optprogname = s + 1;
	}
	c = subgetopt(argc, argv, opts);
	if (opterr) {
		if (c == '?') {
			char            chp[2];
			chp[0] = optproblem;
			chp[1] = '\n';
			substdio_puts(subfderr, optprogname);
			if (argv[optind] && (optind < argc))
				substdio_puts(subfderr, ": illegal option -- ");
			else
				substdio_puts(subfderr, ": option requires an argument -- ");
			substdio_put(subfderr, chp, 2);
			substdio_flush(subfderr);
		}
	}
	return c;
}

void
getversion_sgetopt_c()
{
	const char     *x = "$Id: sgetopt.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
