/*
 * $Log: hmac_sha1.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.2  2021-05-04 14:18:57+05:30  Cprogrammer
 * fixed indentation of comments
 *
 * Revision 1.1  2020-04-01 18:03:45+05:30  Cprogrammer
 * Initial revision
 *
 *
 * hmac_sha1 routine
 */
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include "typesx.h"
#include "sha1.h"

#define PAD 64
#define TK  20

void
hmac_sha1(u8 *text,      /*- pointer to data stream */
		size_t text_len, /*- length of data stream */
		u8 *key,         /*- pointer to authentication key */
		size_t key_len,  /*- length of authentication key */
		u8 *digest       /*- caller digest to be filled in */)
{
	SHA1_CTX        ctx;
	u8              k_ipad[PAD + 1];	/* inner padding - key XORd with ipad */
	u8              k_opad[PAD + 1];	/* outer padding - key XORd with opad */
	u8              tk[TK];
	int             i;

	if (key_len > PAD) {
		SHA1_CTX        tctx;
		SHA1_Init(&tctx);
		SHA1_Update(&tctx, key, key_len);
		SHA1_Final(tk, &tctx);
		key = tk;
		key_len = TK;
	}

	/*- start out by storing key in pads */
	memset(k_ipad, 0, PAD);
	memcpy(k_ipad, key, key_len);
	memset(k_opad, 0, PAD);
	memcpy(k_opad, key, key_len);

	/*- XOR key with ipad and opad values */
	for (i = 0; i < PAD; i++) {
		k_ipad[i] ^= 0x36;
		k_opad[i] ^= 0x5c;
	}

	/*- perform inner SHA1 */
	SHA1_Init(&ctx);			/* init ctx for 1st pass */
	SHA1_Update(&ctx, k_ipad, PAD);	/* start with inner pad */
	SHA1_Update(&ctx, text, text_len);	/* then text of datagram */
	SHA1_Final(digest, &ctx);	/* finish up 1st pass */

	/*- perform outer SHA1 */
	SHA1_Init(&ctx);			/* init ctx for 2nd pass */
	SHA1_Update(&ctx, k_opad, PAD);	/* start with outer pad */
	SHA1_Update(&ctx, digest, TK);	/* then results of 1st hash */
	SHA1_Final(digest, &ctx);	/* finish up 2nd pass */
}

void
getversion_hmac_sha1_c()
{
	const char     *x = "$Id: hmac_sha1.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
