/* cbhandler.c - cbhandler*/

#include <xinu.h>

void cbhandler()
{
  struct procent *curr = &proctab[currpid];
  if (curr->prhascb && curr->prhasmsg)
  {
    curr->fptr();
  }
}
