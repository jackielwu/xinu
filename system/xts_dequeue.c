#include <xinu.h>

pid32 xts_dequeue(void)
{
  pri16 p = xts_priochk();
  if (isempty(xts_ready[p].queue_head))
  {
    return EMPTY;
  }
  pid32 pid = getfirst(xts_ready[p].queue_head);
  xts_ready[p].status = !isempty(xts_ready[p].queue_head);
  queuetab[pid].qprev = EMPTY;
  queuetab[pid].qnext = EMPTY;
  
  return pid;
}
