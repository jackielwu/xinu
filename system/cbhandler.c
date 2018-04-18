/* cbhandler.c - cbhandler*/

#include <xinu.h>

void cbhandler()
{
  struct procent *curr = &proctab[currpid];
  if (curr->prhascb && curr->prhasmsg)
  {
    if (curr->first == 1)
    {
      curr->first = 0;  
      curr->fptr();
    }
    else if (curr->first == 0 && curr->second == 1)
    {
      curr->second = 0;
      curr->fptr();
    }
    else if (curr->first == 0 && curr->second == 0 && curr->third == 1)
    {
      curr->third = 0;
      curr->fptr();
    }
  }
}
