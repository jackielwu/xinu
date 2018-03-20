#include <xinu.h>

pid32 xts_dequeue(void)
{
  pri16 p = xts_priochk();
  if (isempty(p))
  {
    return EMPTY;
  }
  pid32 pid = getfirst(p);
  queuetab[pid].qprev = EMPTY;
  queuetab[pid].qnext = EMPTY;
  
  return pid;
}
