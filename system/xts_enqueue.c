#include <xinu.h>

int xts_enqueue(pid32 pid, pri16 prio)
{
  if (isbadpid(pid)) {
    return -1;
  }
  if (xts_ready[prio].status == 0)
  {
    xts_ready[prio].status = 1;
    //xts_ready[prio].queue_head = queuehead(prio);
    //xts_ready[prio].queue_tail = queuetail(prio);
  }
  int tail, prev;
  tail = xts_ready[prio].queue_tail;
  prev = queuetab[tail].qprev;

  queuetab[pid].qnext = tail;
  queuetab[pid].qprev = prev;
  queuetab[prev].qnext = pid;
  queuetab[tail].qprev = pid;

  return 0;
}
