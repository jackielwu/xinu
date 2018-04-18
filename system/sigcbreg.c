/* sigcbreg.c - sigcbreg */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  sigcbreg  -  Signal callback functions
 *------------------------------------------------------------------------
 */

syscall sigcbreg(
    uint16 ssig,  /* signal interrupt ID */
    int (* fnp) (void), /* callback function pointer */
    uint32 tmarg  /* delay in sec */
  )
{
  intmask mask;			/* Saved interrupt mask		*/
	struct	procent *prptr;		/* Ptr to sempahore table entry	*/

	mask = disable();

  switch(ssig)
  {
    case XSIGRCV:
      prptr = &proctab[currpid];
      if (prptr->prhascb)
      {
        restore(mask);
        return SYSERR;
      }	
      prptr->prhascb = TRUE;
      prptr->fptr = fnp;
	    if (prptr->first == 0)
      {
        prptr->first = 1;
      }
      else if (prptr->second == 0)
      {
        prptr->second = 1;
      }
      else
      {
        prptr->third = 1;
      }
      restore(mask);		/* Restore interrupts */
	    return OK;
    case XSIGCHL:
      prptr = &proctab[currpid];
      if (prptr->prhascb1 && prptr->prchild == -1)
      {
        restore(mask);
        return SYSERR;
      }
      prptr->prhascb1 = TRUE;
      prptr->fptr1 = fnp;
	    if (prptr->first == 0)
      {
        prptr->first = 2;
      }
      else if (prptr->second == 0)
      {
        prptr->second = 2;
      }
      else
      {
        prptr->third = 2;
      }
      
      restore(mask);
      return OK; 
    case XSIGXTM:
      prptr = &proctab[currpid];
      if (prptr->prhascb2)
      {
        restore(mask);
        return SYSERR;
      }
      prptr->prhascb2 = TRUE;
      prptr->fptr2 = fnp;
      prptr->prtmarg = tmarg;
	    if (prptr->first == 0)
      {
        prptr->first = 3;
      }
      else if (prptr->second == 0)
      {
        prptr->second = 3;
      }
      else
      {
        prptr->third = 3;
      }
      
      restore(mask);
      return OK; 
    case XSIGMY:
      prptr = &proctab[currpid];
      if (prptr->prhascb3)
      {
        restore(mask);
        return SYSERR;
      }
      prptr->prhascb3 = TRUE;
      prptr->fptr3 = fnp;
      prptr->prstate = PR_SUSP;
      
      restore(mask);
      return OK; 
    default:
      break;
  }

}
