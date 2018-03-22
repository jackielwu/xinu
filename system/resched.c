/* resched.c - resched, resched_cntl */

#include <xinu.h>

struct	defer	Defer;

/*------------------------------------------------------------------------
 *  resched  -  Reschedule processor to highest priority eligible process
 *------------------------------------------------------------------------
 */
void	resched(void)		/* Assumes interrupts are disabled	*/
{
	struct procent *ptold;	/* Ptr to table entry for old process	*/
	struct procent *ptnew;	/* Ptr to table entry for new process	*/

	/* If rescheduling is deferred, record attempt and return */

	if (Defer.ndefers > 0) {
		Defer.attempt = TRUE;
		return;
	}

	/* Point to process table entry for the current (old) process */

	ptold = &proctab[currpid];
  ptold->prcputot += clkmilli - ptold->prctxswbeg; /* CPU ms elapsed time */
  //kprintf("preempt: %u\n", preempt);  
  /* null process cannot be modified */
  /*  
  if (currpid != 0)
    ptold->prprio = MAXPRIO - ptold->prcputot;
  */
	if (ptold->prstate == PR_CURR) {  /* Process remains eligible */
		/*if (ptold->prprio > firstkey(readylist)) {
			return;
		}*/
    if (preempt == 0)
    {
      ptold->prprio = xts_conf[ptold->prprio].xts_tqexp;
      preempt = xts_conf[ptold->prprio].xts_quantum;
      ptold->prstate = PR_READY;
      xts_enqueue(currpid, ptold->prprio);
    }
    /* wake interupt */
    else
    {
        //kprintf("sleep\n");
        return;
    }

		/* Old process will no longer remain current */
    /*
		ptold->prstate = PR_READY;
		insert(currpid, readylist, ptold->prprio);
    */
	}
  else
  {
    /* IO BOUND */
    ptold->prprio = xts_conf[ptold->prprio].xts_slpret;
    preempt = xts_conf[ptold->prprio].xts_quantum;
  }

	/* Force context switch to highest priority ready process */

	//currpid = dequeue(readylist);
  currpid = xts_dequeue();

	ptnew = &proctab[currpid];
	ptnew->prstate = PR_CURR;
	ptnew->prctxswbeg = clkmilli; /* Save clk ms begin ctxsw */
  //preempt = QUANTUM;		/* Reset time slice for process	*/
	ctxsw(&ptold->prstkptr, &ptnew->prstkptr);

	/* Old process returns here when resumed */

	return;
}

/*------------------------------------------------------------------------
 *  resched_cntl  -  Control whether rescheduling is deferred or allowed
 *------------------------------------------------------------------------
 */
status	resched_cntl(		/* Assumes interrupts are disabled	*/
	  int32	defer		/* Either DEFER_START or DEFER_STOP	*/
	)
{
	switch (defer) {

	    case DEFER_START:	/* Handle a deferral request */

		if (Defer.ndefers++ == 0) {
			Defer.attempt = FALSE;
		}
		return OK;

	    case DEFER_STOP:	/* Handle end of deferral */
		if (Defer.ndefers <= 0) {
			return SYSERR;
		}
		if ( (--Defer.ndefers == 0) && Defer.attempt ) {
			resched();
		}
		return OK;

	    default:
		return SYSERR;
	}
}
