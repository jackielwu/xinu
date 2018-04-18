/* childwait.c - childwait */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  childwait  - Process blocked while waiting for child process
 *------------------------------------------------------------------------
 */

pid32 childwait(void)
{
  intmask mask;			/* Saved interrupt mask		*/
	mask = disable();
  struct procent *prptr = &proctab[currpid];
  if (prptr->prnumcld == 0)
  {
    restore(mask);
    return SYSERR;
  }
  prptr->prstate = PR_CHLDWAIT;
  resched();

  if (prptr->first == 2)
  {
    prptr->first = 0;
    prptr->fptr1();
  }
  else if (prptr->first == 0 && prptr->second == 2)
  {
    prptr->second = 0;
    prptr->fptr1();
  }
  else if (prptr->first == 0 && prptr->second == 0 && prptr->third == 2)
  { 
    prptr->third = 0;
    prptr->fptr1();
  }
  return prptr->prchild;
}
