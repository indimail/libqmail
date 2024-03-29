/*
 * $Log: sha1.h,v $
 * Revision 1.2  2023-01-02 20:34:15+05:30  Cprogrammer
 * fixed FSF address
 *
 * Revision 1.1  2020-04-01 18:07:22+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef SW_SHA1_H
#define SW_SHA1_H

/**
 * Copyright (C) 2005-2006 Tino Reichardt
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 2, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "typesx.h"
#include <string.h>

#define SHA1HashSize 20

typedef struct SHA1_CTX
{
    u32 Intermediate_Hash[SHA1HashSize/4]; /* Message Digest  */
    u32 Length_Low;            /* Message length in bits      */
    u32 Length_High;           /* Message length in bits      */
    u32 Message_Block_Index;   /* Index into message block array   */
    u8 Message_Block[64];      /* 512-bit message blocks      */
} SHA1_CTX;

extern void SHA1_Init(SHA1_CTX *ctx);
extern void SHA1_Update(SHA1_CTX *ctx, const void *data, u32 size);
extern void SHA1_Final(u8 *result, SHA1_CTX *ctx);

#endif
