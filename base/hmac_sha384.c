/*
 * $Log: hmac_sha384.c,v $
 * Revision 1.1  2021-06-16 17:38:51+05:30  Cprogrammer
 * Initial revision
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_SSL
#include <string.h>
#include <openssl/x509.h>
#include <openssl/hmac.h>

#define KLEN 128

void
hmac_sha384(const unsigned char *text, /*- pointer to data stream        */
			size_t text_len,		   /*- length of data stream         */
			const unsigned char *key,  /*- pointer to authentication key */
			size_t key_len,			   /*- length of authentication key  */
			void *digest)
{
	/*- caller digest to be filled in */
	unsigned char   k_ipad[KLEN + 1];	/*- inner padding - key XORd with ipad */
	unsigned char   k_opad[KLEN + 1];	/*- outer padding - key XORd with opad */
	unsigned char   tk[SHA384_DIGEST_LENGTH];
	unsigned char   tk2[SHA384_DIGEST_LENGTH];
	unsigned char   bufferIn[1024];
	unsigned char   bufferOut[1024];
	int             i;

	/*
 	 * if key is longer than KLEN bytes reset it to key=sha384(key) 
 	 */
	if (key_len > KLEN) {
		SHA384(key, key_len, tk);
		key = tk;
		key_len = SHA384_DIGEST_LENGTH;
	}

	/*
 	 * the HMAC_SHA384 transform looks like:
 	 *
 	 * SHA384(K XOR opad, SHA384(K XOR ipad, text))
 	 *
 	 * where K is an n byte key
 	 * ipad is the byte 0x36 repeated KLEN times
 	 * opad is the byte 0x5c repeated KLEN times
 	 * and text is the data being protected
 	 */

	/*- start out by storing key in pads */
	memset(k_ipad, 0, sizeof k_ipad);
	memset(k_opad, 0, sizeof k_opad);
	memcpy(k_ipad, key, key_len);
	memcpy(k_opad, key, key_len);

	/*- XOR key with ipad and opad values */
	for (i = 0; i < KLEN; i++) {
		k_ipad[i] ^= 0x36;
		k_opad[i] ^= 0x5c;
	}

	/*- perform inner SHA384 */
	memset(bufferIn, 0x00, 1024);
	memcpy(bufferIn, k_ipad, KLEN);
	memcpy(bufferIn + KLEN, text, text_len);

	SHA384(bufferIn, KLEN + text_len, tk2);

	/*- perform outer SHA384 */
	memset(bufferOut, 0x00, 1024);
	memcpy(bufferOut, k_opad, KLEN);
	memcpy(bufferOut + KLEN, tk2, SHA384_DIGEST_LENGTH);

	SHA384(bufferOut, KLEN + SHA384_DIGEST_LENGTH, digest);
}
#else
#warning "ssl development library missing / not compiled with -DHAVE_SSL"
#endif

void
getversion_hmac_sha384_c()
{
	static char    *x = "$Id: hmac_sha384.c,v 1.1 2021-06-16 17:38:51+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
