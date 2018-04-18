/* sigcbunreg.c - sigcbunreg */

#include <xinu.h>




syscall sigcbunreg(
    uint16 ssig   /* signal interrupt ID */
  )
{
  intmask mask;
  struct procent *prptr;

  mask = disable();

  switch(ssig)
  {
    case XSIGRCV:
      prptr = &proctab[currpid];
      if (!prptr->prhascb)
      {
        restore(mask);
        return SYSERR;
      }
      prptr->prhascb = FALSE;
      prptr->fptr = NULL;
      if (prptr->first == 1)
      {
        prptr->first = 0;
      }
      else if (prptr->second == 1)
      {
        prptr->second = 0;
      }
      else if (prptr->third == 1)
      {
        prptr->third = 0;
      }
      restore(mask);
      return OK;
    case XSIGCHL:
      prptr = &proctab[currpid];
      if (!prptr->prhascb1 && prptr->prchild != -1)
      {
        restore(mask);
        return SYSERR;
      }
      prptr->prhascb1 = FALSE;
      prptr->fptr1 = NULL;
      if (prptr->first == 2)
      {
        prptr->first = 0;
      }
      else if (prptr->second == 2)
      {
        prptr->second = 0;
      }
      else if (prptr->third == 2)
      {
        prptr->third = 0;
      }
      restore(mask);
      return OK;
    case XSIGXTM:
      prptr = & proctab[currpid];
      if (!prptr->prhascb2)
      {
        restore(mask);
        return SYSERR;
      }
      prptr->prhascb2 = FALSE;
      prptr->fptr2 = NULL;
      prptr->prtmarg = 0;
      if (prptr->first == 3)
      {
        prptr->first = 0;
      }
      else if (prptr->second == 3)
      {
        prptr->second = 0;
      }
      else if (prptr->third == 3)
      {
        prptr->third = 0;
      }
      restore(mask);
      return OK;
    case XSIGMY:
      if (!prptr->prhascb3)
      {
        restore(mask);
        return SYSERR;
      }
      prptr->prhascb3 = FALSE;
      prptr->fptr3 = NULL;
      ready(currpid);
      restore(mask);
      return OK;
    default:
      break;
  }
}
