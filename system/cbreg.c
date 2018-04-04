/* cbreg.c - cbreg */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  cbreg  -  Pass a message to a process and start recipient if waiting
 *------------------------------------------------------------------------
 */
syscall	cbreg(
	  int (* fnp) (void)		/* Callback function pointer	*/
	)
{
	intmask	mask;			/* Saved interrupt mask		*/
	struct	procent *prptr;		/* Ptr to process' table entry	*/

	mask = disable();

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
}
