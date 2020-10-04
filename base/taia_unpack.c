/*
 * $Log: taia_unpack.c,v $
 * Revision 1.1  2019-07-18 09:54:36+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "uint32.h"
#include "taia.h"

void taia_unpack(const char* s, struct taia* t)
{
  uint32 x;

  tai_unpack((char *) s, &t->sec);
  s += 8;

  x = (unsigned char) s[4];
  x <<= 8; x += (unsigned char) s[5];
  x <<= 8; x += (unsigned char) s[6];
  x <<= 8; x += (unsigned char) s[7];
  t->atto = x;
  x = (unsigned char) s[0];
  x <<= 8; x += (unsigned char) s[1];
  x <<= 8; x += (unsigned char) s[2];
  x <<= 8; x += (unsigned char) s[3];
  t->nano = x;
}
