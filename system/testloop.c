#include <xinu.h>

void testloop(pid32 id)
{
  for(uint32 i = 0; i < UPBOUND; i++)
    ;
  kprintf("prcputot: %u", proctab[id].prcputot);
}
