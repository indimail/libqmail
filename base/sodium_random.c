/*
 * $Log: sodium_random.c,v $
 * Revision 1.1  2022-08-05 09:00:00+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_SODIUM_H
#include <sodium.h>
#endif
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

#ifdef HAVE_SODIUM
uint32_t
sodium_random(char *str, size_t len)
{
	if (sodium_init() < 0)
		return -1;

	/*- copy len random bytes, not null-terminated */
	randombytes_buf(str, len);

	/*- return a random number between 0 and 9 */
	return (randombytes_uniform(10));
}
#endif

void
getversion_sodium_random_c()
{
	const char     *x = "$Id: sodium_random.c,v 1.1 2022-08-05 09:00:00+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
