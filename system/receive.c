/* receive.c - receive */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  receive  -  Wait for a message and return the message to the caller
 *------------------------------------------------------------------------
 */
umsg32	receive(void)
{
	intmask	mask;			/* Saved interrupt mask		*/
	struct	procent *prptr;		/* Ptr to process' table entry	*/
	umsg32	msg;			/* Message to return		*/

	mask = disable();
	prptr = &proctab[currpid];
	
  if (prptr->prhasmsg == FALSE && prptr->rcpblkflag == FALSE) {
		prptr->prstate = PR_RECV;
		resched();		// Block until message arrives	
	}
   
	msg = prptr->prmsg;		/* Retrieve message		*/
	prptr->prhasmsg = FALSE;	/* Reset message flag		*/
  if (prptr->rcpblkflag)
  {
    pid32 p = dequeue(prptr->sendqueue);
    struct procent *sp = &proctab[p];
    prptr->prmsg = sp->sendblkmsg;
    //kprintf("dequeue: %s\n",prptr->prmsg); 
    prptr->rcpblkflag = !isempty(prptr->sendqueue);
    //kprintf("stuff: %u\n", prptr->rcpblkflag);
    prptr->prhasmsg = TRUE;
    ready(p);
  }
	//msg = prptr->prmsg;		/* Retrieve message		*/
	//prptr->prhasmsg = FALSE;	/* Reset message flag		*/
  restore(mask);
	return msg;
}
