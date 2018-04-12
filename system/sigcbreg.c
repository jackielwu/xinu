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
	    restore(mask);		/* Restore interrupts */
	    return OK;
    case XSIGCHL:
      
      break;
    case XSIGXTM:
      sleep(tmarg);
      
      break;
    default:
      break;
  }

}
