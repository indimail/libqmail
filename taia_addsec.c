/*
 * $Log: taia_addsec.c,v $
 * Revision 1.1  2019-07-18 09:53:45+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "taia.h"

/* XXX: breaks tai encapsulation */

void taia_addsec(struct taia *t,const struct taia *u,long secs)
{
  t->sec.x = u->sec.x + (uint64)(int64)secs;
  t->nano = u->nano;
  t->atto = u->atto;
}
