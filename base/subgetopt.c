/*
 * $Log: subgetopt.c,v $
 * Revision 1.6  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.5  2022-01-30 19:36:39+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.4  2020-11-23 18:05:20+05:30  Cprogrammer
 * use const keyword for opts argument
 *
 * Revision 1.3  2004-10-22 20:31:07+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:24:35+05:30  Cprogrammer
 * added RCS log
 *
 *
 * subgetopt.c, subgetopt.h: (yet another) improved getopt clone, inner layer
 * D. J. Bernstein, djb@pobox.com.
 * No dependencies.
 * No system requirements.
 * 19970228: Cleanups.
 * 931129: Adapted from getopt.c.
 * No known patent problems.
 * 
 * Documentation in subgetopt.3.
 */

#define SUBGETOPTNOSHORT
#include "subgetopt.h"

#define sgopt subgetopt
#define optind subgetoptind
#define optpos subgetoptpos
#define optarg subgetoptarg
#define optproblem subgetoptproblem
#define optdone subgetoptdone

int             optind = 1;
int             optpos = 0;
char           *optarg = 0;
int             optproblem = 0;
int             optdone = SUBGETOPTDONE;

int
sgopt(int argc, char **argv, const char *opts)
{
	int             c;
	const char     *s;

	optarg = 0;
	if (!argv || (optind >= argc) || !argv[optind])
		return optdone;
	if (optpos && !argv[optind][optpos]) {
		++optind;
		optpos = 0;
		if ((optind >= argc) || !argv[optind])
			return optdone;
	}
	if (!optpos) {
		if (argv[optind][0] != '-')
			return optdone;
		++optpos;
		c = argv[optind][1];
		if ((c == '-') || (c == 0)) {
			if (c)
				++optind;
			optpos = 0;
			return optdone;
		}
		/*
		 * otherwise c is reassigned below 
		 */
	}
	c = argv[optind][optpos];
	++optpos;
	s = opts;
	while (*s) {
		if (c == *s) {
			if (s[1] == ':') {
				optarg = argv[optind] + optpos;
				++optind;
				optpos = 0;
				if (!*optarg) {
					optarg = argv[optind];
					if ((optind >= argc) || !optarg) {	/*- argument past end */
						optproblem = c;
						return '?';
					}
					++optind;
				}
			}
			return c;
		}
		++s;
		if (*s == ':')
			++s;
	}
	optproblem = c;
	return '?';
}

void
getversion_subgetopt_c()
{
	const char     *x = "$Id: subgetopt.c,v 1.6 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
