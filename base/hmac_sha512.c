/*
 * $Log: hmac_sha512.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.2  2021-06-16 14:09:06+05:30  Cprogrammer
 * compile hmac_sha512 if HAVE_SSL is defined
 *
 * Revision 1.1  2020-04-01 18:05:13+05:30  Cprogrammer
 * Initial revision
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_SSL
#include <string.h>
#include <openssl/x509.h>
#include <openssl/hmac.h>

void
hmac_sha512(const unsigned char *text, /*- pointer to data stream        */
			size_t text_len,           /*- length of data stream         */
			const unsigned char *key,  /*- pointer to authentication key */
			size_t key_len,            /*- length of authentication key  */
			void *digest               /*- caller digest to be filled in */)
{
	/*- caller digest to be filled in */
	unsigned char   k_ipad[129];	/*- inner padding - key XORd with ipad */
	unsigned char   k_opad[129];	/*- outer padding - key XORd with opad */
	unsigned char   tk[SHA512_DIGEST_LENGTH];
	unsigned char   tk2[SHA512_DIGEST_LENGTH];
	unsigned char   bufferIn[1024];
	unsigned char   bufferOut[1024];
	int             i;

	/*
 	 * if key is longer than 128 bytes reset it to key=sha512(key) 
 	 */
	if (key_len > 128) {
		SHA512(key, key_len, tk);
		key = tk;
		key_len = SHA512_DIGEST_LENGTH;
	}

	/*
 	 * the HMAC_SHA512 transform looks like:
 	 *
 	 * SHA512(K XOR opad, SHA512(K XOR ipad, text))
 	 *
 	 * where K is an n byte key
 	 * ipad is the byte 0x36 repeated 128 times
 	 * opad is the byte 0x5c repeated 128 times
 	 * and text is the data being protected
 	 */

	/*- start out by storing key in pads */
	memset(k_ipad, 0, sizeof k_ipad);
	memset(k_opad, 0, sizeof k_opad);
	memcpy(k_ipad, key, key_len);
	memcpy(k_opad, key, key_len);

	/*- XOR key with ipad and opad values */
	for (i = 0; i < 128; i++) {
		k_ipad[i] ^= 0x36;
		k_opad[i] ^= 0x5c;
	}

	/*- perform inner SHA512 */
	memset(bufferIn, 0x00, 1024);
	memcpy(bufferIn, k_ipad, 128);
	memcpy(bufferIn + 128, text, text_len);

	SHA512(bufferIn, 128 + text_len, tk2);

	/*- perform outer SHA512 */
	memset(bufferOut, 0x00, 1024);
	memcpy(bufferOut, k_opad, 128);
	memcpy(bufferOut + 128, tk2, SHA512_DIGEST_LENGTH);

	SHA512(bufferOut, 128 + SHA512_DIGEST_LENGTH, digest);
}
#else
#warning "ssl development library missing / not compiled with -DHAVE_SSL"
#endif

void
getversion_hmac_sha512_c()
{
	const char     *x = "$Id: hmac_sha512.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
