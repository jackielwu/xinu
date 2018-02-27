#include <xinu.h>

syscall getcputot(pid32 pid)
{
  intmask mask;
  struct procent *prptr;
  pri16 prio;

  mask = disable();
  if (isbadpid(pid) || (pid == NULLPROC)) {
    restore(mask);
    return (pri16)SYSERR;
  }
  prptr = &proctab[pid];

  if (currpid == pid) {
    restore(mask);
    return prptr->prcputot;
  }
  else {
    restore(mask);
    return OK;
  }

}
