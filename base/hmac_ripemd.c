/*
 * $Log: hmac_ripemd.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2021-03-11 18:17:19+05:30  Cprogrammer
 * removed undefined variables
 *
 * Revision 1.2  2020-10-10 21:18:48+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.1  2011-12-05 19:53:27+05:30  Cprogrammer
 * Initial revision
 *
 * Revision 2.2  2011-10-28 14:15:02+05:30  Cprogrammer
 * added length arguments to hmac_ripemd()
 *
 * Revision 2.1  2011-10-27 14:30:07+05:30  Cprogrammer
 * hmac_ripemd() function
 *
 */
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include "typesx.h"
#include "ripemd.h"

#define PAD 64
#define TK  20

void hmac_ripemd(u8 *text, /*- pointer to data stream */
		size_t text_len,   /*- length of data stream */
		u8 *key,           /*- pointer to authentication key */
		size_t key_len,    /*- length of authentication key */
		u8 *digest         /*- caller digest to be filled in */)
{
	RIPEMD160_CTX ctx;
	u8 k_ipad[PAD+1]; /* inner padding - key XORd with ipad */
	u8 k_opad[PAD+1]; /* outer padding - key XORd with opad */
	u8 tk[TK];
	int i;

	if (key_len > PAD) {
		RIPEMD160_CTX tctx;
		RIPEMD160_Init(&tctx);
		RIPEMD160_Update(&tctx, key, key_len);
		RIPEMD160_Final(tk, &tctx);
		key = tk;
		key_len = TK;
	}

	/* start out by storing key in pads */
	memset(k_ipad, 0, PAD);
	memcpy(k_ipad, key, key_len);
	memset(k_opad, 0, PAD);
	memcpy(k_opad, key, key_len);

	/* XOR key with ipad and opad values */
	for (i=0; i<PAD; i++) {
		k_ipad[i] ^= 0x36;
		k_opad[i] ^= 0x5c;
	}

	/* perform inner RIPEMD160 */
	RIPEMD160_Init(&ctx);                   /* init ctx for 1st pass */
	RIPEMD160_Update(&ctx, k_ipad, PAD);    /* start with inner pad */
	RIPEMD160_Update(&ctx, text, text_len); /* then text of datagram */
	RIPEMD160_Final(digest, &ctx);          /* finish up 1st pass */

	/* perform outer RIPEMD160 */
	RIPEMD160_Init(&ctx);                   /* init ctx for 2nd pass */
	RIPEMD160_Update(&ctx, k_opad, PAD);    /* start with outer pad */
	RIPEMD160_Update(&ctx, digest, TK);     /* then results of 1st hash */
	RIPEMD160_Final(digest, &ctx);          /* finish up 2nd pass */
}

void
getversion_hmac_ripemd_c()
{
	const char     *x = "$Id: hmac_ripemd.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";
	x++;
}
