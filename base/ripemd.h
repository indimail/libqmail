/*
 * $Log: ripemd.h,v $
 * Revision 1.1  2020-04-01 18:09:07+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef QP_RMD_H
#define QP_RMD_H

#include "typesx.h"
#include <string.h>

typedef struct {
	u32 MD[5]; /* used for the digest */
	u32 X[16]; /* current 16 bit chunk */
	u32 len;   /* full length */
	u8  D[64]; /* 512 bit data block */
	u32 l;     /* current length of data block -> D[l] */
} RIPEMD160_CTX;

void RIPEMD160_Init(RIPEMD160_CTX *ctx);
void RIPEMD160_Update(RIPEMD160_CTX *ctx, const void *data, u32 size);
void RIPEMD160_Final(u8 *result, RIPEMD160_CTX *ctx);

#endif
