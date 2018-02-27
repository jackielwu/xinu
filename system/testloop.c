#include <xinu.h>

void testloop(void)
{
  #ifdef DEBUG
    kprintf("clkmilli: %u\nprctxswbeg: %u\n prcputot: %u\n", clkmilli, proctab[currpid].prctxswbeg, proctab[currpid].prcputot);
  #endif
  for(uint32 i = 0; i < UPBOUND; i++)
    ;
  #ifdef DEBUG
    kprintf("clkmilli: %u\nprctxswbeg: %u\n prcputot: %u\n", clkmilli, proctab[currpid].prctxswbeg, proctab[currpid].prcputot);
  #endif
  
  kprintf("\n%s prcputot: %u\n", proctab[currpid].prname, getcputot(currpid));
}
