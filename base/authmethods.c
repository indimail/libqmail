/*
 * $Id: authmethods.c,v 1.1 2022-08-23 07:50:21+05:30 Cprogrammer Exp mbhangui $
 */
#include <authmethods.h>

static char    *authmethod[] = {"LOGIN", "PLAIN", "CRAM-MD5", "CRAM-SHA1", "CRAM-SHA224",
                                "CRAM-SHA256", "CRAM-SHA384", "CRAM-SHA512", "CRAM-RIPEMD",
                                "DIGEST-MD5", "SCRAM-SHA-1", "SCRAM-SHA-256", "SCRAM-SHA-512",
                                "SCRAM-SHA-1-PLUS", "SCRAM-SHA-256-PLUS", "SCRAM-SHA-512-PLUS", 0};
char           *
get_authmethod(int method)
{
	int             i;

	for (i = 0; authmethod[i]; i++);

	return (method && method <= i ?  authmethod[method - 1] : "unknown");
}
