/*
 * $Log: taia_half.c,v $
 * Revision 1.1  2019-07-18 09:54:14+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "taia.h"
#include "uint32.h"

/* XXX: breaks tai encapsulation */

void taia_half(struct taia* t, const struct taia* u)
{
  t->atto = u->atto >> 1;
  if (u->nano & 1) t->atto += (uint32)500000000UL;
  t->nano = u->nano >> 1;
  if (u->sec.x & 1) t->nano += (uint32)500000000UL;
  t->sec.x = u->sec.x >> 1;
}
