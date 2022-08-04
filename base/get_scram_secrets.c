#ifndef	lint
static char     sccsid[] = "$Id: get_scram_secrets.c,v 1.1 2022-08-04 10:01:50+05:30 Cprogrammer Exp mbhangui $";
#endif

#include <str.h>
#include <scan.h>
#include <stralloc.h>
#include <authmethods.h>

/*-
 * The output is a string of the form
 *  "{mech}count,salt,stored-key,server-key[,salted-password]"
 *  "mech" is the mechanism, "count" is *  the number of times password
 * was hashed,
 *  "salt" is the provided/generated base64-encoded salt,
 *  "stored-key" and "server-key" are the two derived and base64-encoded
 * server-side keys.
 *  "salted-password" is the non-scram derived encrypted password that can
 * be used with non-scram methods
 * {SCRAM-SHA-256}4096,GppkE9F92zRciuyk,n9boN+EV/P7i+Uxn063JLcppQnyOrIktX81FCy8iibk=,cVjrqEdR7DuGDAwKMLrn6YOp5Z4w7zOBjrxo+1mGmfE=,$1$GsamfuEK$eSxzR6dswY.kaNTtPNi5c1 (SCRAM-SHA-256)
 */
int
get_scram_secrets(char *pass_str, int *mech, int *iter, char **salt, char **stored_key, char **server_key, char **salted_pass)
{
	int             m;
	char           *p1, *p2;

	/*- get mechanism */
	if (!str_diffn(pass_str, "{SCRAM-SHA-1}", 13)) {
		m = AUTH_SCRAM_SHA1;
		p1 = pass_str + 13;
	} else
	if (!str_diffn(pass_str, "{SCRAM-SHA-256}", 15)) {
		m = AUTH_SCRAM_SHA256;
		p1 = pass_str + 15;
	} else
	if (!str_diffn(pass_str, "{SCRAM-SHA-512}", 15)) {
		m = AUTH_SCRAM_SHA512;
		p1 = pass_str + 15;
	} else
		m = 0;
	if (mech)
		*mech = m;
	if (!m)
		return 0;
	/*- get iter */
	for (p2 = p1 + 1;*p2 && *p2 != ','; p2++);
	if (*p2 == ',') {
		if (iter) {
			*p2 = 0;
			scan_int(p1, iter);
		}
		p1 = p2 + 1;
	} else
		return 1;
	/*- get salt */
	for (p2 = p1 + 1;*p2 && *p2 != ','; p2++);
	if (*p2 == ',') {
		if (salt) {
			*p2 = 0;
			*salt = p1;
		}
		p1 = p2 + 1;
	} else
		return 2;
	/*- get stored_key */
	for (p2 = p1 + 1;*p2 && *p2 != ','; p2++);
	if (*p2 == ',') {
		if (stored_key) {
			*p2 = 0;
			*stored_key = p1;
		}
		p1 = p2 + 1;
	} else
		return 3;
	/*- get server_key, salted_password */
	for (p2 = p1 + 1;*p2 && *p2 != ','; p2++);
	if (*p2 == ',') {
		if (server_key) {
			*p2 = 0;
			*server_key = p1;
		}
		if (!*(p2 + 1))
			return 5;
		if (salted_pass)
			*salted_pass = p2 + 1;
	} else
		return 4;
	return 6;
}
/*
 * Log: $
 */
