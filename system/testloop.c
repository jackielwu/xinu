#include <xinu.h>

void testloop(void)
{
  #ifdef DEBUG
    struct procent *pr = &proctab[currpid];
    kprintf("Before:\nclkmilli: %u\nprctxswbeg: %u\nprcputot: %u\n", clkmilli, pr->prctxswbeg, getcputot(currpid));
  #endif
  for(uint32 i = 0; i < UPBOUND; i++)
    ;
  
  kprintf("\n%s prcputot: %u\n", proctab[currpid].prname, getcputot(currpid));
  #ifdef DEBUG
    kprintf("After:\nclkmilli: %u\nprctxswbeg: %u\nprcputot: %u\n", clkmilli, pr->prctxswbeg, getcputot(currpid));
  #endif
}
