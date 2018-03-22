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
  int head, next;
  head = xts_ready[prio].queue_head;
  next = queuetab[head].qnext;

  queuetab[pid].qnext = next;
  queuetab[pid].qprev = head;
  queuetab[next].qprev = pid;
  queuetab[head].qnext = pid;

  return 0;
}
