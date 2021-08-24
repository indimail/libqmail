/*
 * $Log: check_domain.c,v $
 * Revision 1.1  2021-08-24 11:20:57+05:30  Cprogrammer
 * Initial revision
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_REGEX_H
#include <regex.h>
#endif
#include "strerr.h"
#include "env.h"
#include "check_domain.h"

struct strerr   check_domain_err;
static char     errbuf[128];

int
check_domain(char *domain)
{
	regex_t         re;
	int             r;
	char           *p;
	char           *reg_exp = "^[0-9a-zA-Z_-]+(\\.[0-9a-zA-Z_-]+)*(\\.[a-zA-Z]+)$";

	if (!(p = env_get("CHECK_DOMAIN_REGEXP")))
		p = reg_exp;
	if ((r = regcomp(&re, p, REG_EXTENDED|REG_NEWLINE))) {
		regerror(r, &re, errbuf, sizeof(errbuf));
		regfree(&re);
		STRERR4(-1, check_domain_err, p, ": regcomp: ", errbuf, ": ")
		return -1;
	}
	if ((r = regexec(&re, domain, 0, 0, 0)) == -1) {
		regerror(r, &re, errbuf, sizeof(errbuf));
		regfree(&re);
		STRERR4(-1, check_domain_err, p, ": regexec: ", errbuf, ": ")
		return -1;
	}
	regfree(&re);
	return (r == REG_NOMATCH ? 0 : 1);
}
