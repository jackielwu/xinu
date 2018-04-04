/* send.c - send */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  sendblk  -  Pass a message to a process and start recipient if waiting
 *------------------------------------------------------------------------
 */
syscall	sendblk(
	  pid32		pid,		/* ID of recipient process	*/
	  umsg32	msg		/* Contents of message		*/
	)
{
	intmask	mask;			/* Saved interrupt mask		*/
	struct	procent *prptr;		/* Ptr to process' table entry	*/

	mask = disable();
	if (isbadpid(pid)) {
		restore(mask);
		return SYSERR;
	}

	prptr = &proctab[pid];
	struct procent *sp = &proctab[currpid];
  if (prptr->prhasmsg)
  {
    sp->prstate = PR_SNDBLK;
    sp->sendblkmsg = msg;
    sp->sendblkflag = TRUE;
    sp->sendblkrcp = pid;
    prptr->rcpblkflag = TRUE;
    /* Insert into blocking queue */
    enqueue(currpid, prptr->sendqueue);
    resched();
    restore(mask);
    return OK;
  }
  
  if ((prptr->prstate == PR_FREE)) {
		restore(mask);
		return SYSERR;
	}
	prptr->prmsg = msg;		/* Deliver message		*/
	prptr->prhasmsg = TRUE;		/* Indicate message is waiting	*/

	/* If recipient waiting or in timed-wait make it ready */

	if (prptr->prstate == PR_RECV) {
		ready(pid);
	} else if (prptr->prstate == PR_RECTIM) {
		unsleep(pid);
		ready(pid);
	}
	restore(mask);		/* Restore interrupts */
	return OK;
}
