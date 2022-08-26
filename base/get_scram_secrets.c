#ifndef	lint
static char     sccsid[] = "$Id: get_scram_secrets.c,v 1.3 2022-08-26 11:51:26+05:30 Cprogrammer Exp mbhangui $";
#endif

#include <str.h>
#include <scan.h>
#include <stralloc.h>
#include <authmethods.h>

/*-
 * The input is a string (either one of case 1 or case 2)
 *
 * case 1
 *  "{mech}count,salt,stored-key,server-key,salted-password"
 *
 * case 2
 *  "{mech}count,salt,stored-key,server-key:hexsaltpw:cleartxt,salted-password"
 *
 * case 1
 * The function extracts details in mech, iter, salt, stored_key
 * server_key and saltedpw,
 * total of 6 fields if hexsaltpw and cleartxt are not stored 
 *
 * case 2
 * The function extracts details in mech, iter, salt, stored_key
 * server_key, hexsaltpw, cleartxt and saltedpw,
 * total of 8 fields if hexsaltpw and cleartxt are stored
 *
 *  "mech" is the mechanism, "count" is *  the number of times password
 * was hashed,
 *  "iter" is the iteration cound to be used.
 *  "salt" is the provided/generated base64-encoded salt,
 *  "stored-key" and "server-key" are the two derived and base64-encoded
 * server-side keys. It returns the number of fields extracted.
 *  "salted-password" is the non-scram derived encrypted password from
 * crypt(3) that can be used with non-scram methods
 *  "hexsaltpw" is the scram salted passwd that can be used instead of
 * storedkey/serverkey combination
 *  "cleartxt" is the user's password in clear text. This is used for
 *  cram methods
 *
 * Examples
 *
 * case 1
 * {SCRAM-SHA-256}4096,GppkE9F92zRciuyk,n9boN+EV/P7i+Uxn063JLcppQnyOrIktX81FCy8iibk=,cVjrqEdR7DuGDAwKMLrn6YOp5Z4w7zOBjrxo+1mGmfE=,$1$GsamfuEK$eSxzR6dswY.kaNTtPNi5c1 (SCRAM-SHA-256)
 *
 * case 1
 * {SCRAM-SHA-256}4096,GppkE9F92zRciuyk,n9boN+EV/P7i+Uxn063JLcppQnyOrIktX81FCy8iibk=,cVjrqEdR7DuGDAwKMLrn6YOp5Z4w7zOBjrxo+1mGmfE=:86e346545877b822f8d904ae90595f3f7050d453b33eaf6b78dc95b4a3bfde3b:pass,$1$GsamfuEK$eSxzR6dswY.kaNTtPNi5c1
 *
 * This function is used by qmail-smtpd. vpasswd and vmoduser from the indimail
 * package sets passwords in this form. This form allows flexibility for clients
 * to use any of AUTH PLAIN, LOGIN, any of the CRAM-* and DIGEST-MD5,
 * SCRAM-* methods.
 */
int
get_scram_secrets(char *pass_str, int *mech, int *iter, char **salt,
		char **stored_key, char **server_key, char **hexsaltpw,
		char **cleartxt, char **saltedpw)
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
	for (p2 = p1 + 1; *p2 && *p2 != ','; p2++);
	if (*p2 == ',') {
		if (iter) {
			*p2 = 0;
			scan_int(p1, iter);
		}
		p1 = p2 + 1;
	} else
		return 1;
	/*- get salt */
	for (p2 = p1 + 1; *p2 && *p2 != ','; p2++);
	if (*p2 == ',') {
		if (salt) {
			*p2 = 0;
			*salt = p1;
		}
		p1 = p2 + 1;
	} else
		return 2;
	/*- get stored_key */
	for (p2 = p1 + 1; *p2 && *p2 != ','; p2++);
	if (*p2 == ',') {
		if (stored_key) {
			*p2 = 0;
			*stored_key = p1;
		}
		p1 = p2 + 1;
	} else
		return 3;
	/*- get server_key,saltedpw or server_key:hexsaltpw:cleartxt,saltedpw*/
	for (p2 = p1 + 1; *p2 && *p2 != ','; p2++);
	if (*p2 == ',') {
		if (server_key)
			*server_key = p1;
		if (server_key || hexsaltpw || cleartxt)
			*p2 = 0;
		if (!*(p2 + 1))
			return 5;
		if (saltedpw)
			*saltedpw = p2 + 1;
		/*-
		 * server key can be serverkey,saltedpw
		 * or
		 * server key can be serverkey:hexsaltpw:cleartxt,saltedpw
		 */
		for (p2 = p1; *p2 && *p2 != ':'; p2++);
		if (*p2 == ':') {
			*p2 = 0;
			if (hexsaltpw)
				*hexsaltpw = p2 + 1;
			p1 = p2 + 1; /*- hexsaltpw */
			if (!*(p2 + 1))
				return 6;
			for (p2 = p1; *p2 && *p2 != ':'; p2++);
			if (*p2 == ':') {
				*p2 = 0;
				if (cleartxt)
					*cleartxt = p2 + 1;
				return *(p2 + 1) ? 8 : 7;
			} else
				return 7;
		}
	} else
		return 4;
	return 6;
}
/*
 * $Log: get_scram_secrets.c,v $
 * Revision 1.3  2022-08-26 11:51:26+05:30  Cprogrammer
 * handle additional CRAM-* formats if set in password field
 *
 * Revision 1.2  2022-08-16 08:19:55+05:30  Cprogrammer
 * updated function documentation
 *
 */
