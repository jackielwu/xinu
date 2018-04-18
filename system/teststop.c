/* teststop.c = teststop */

#include <xinu.h>

void cbstop(void)
{
  kprintf("XSIGMY cb\n");
  sigcbunreg(XSIGMY);
}

void teststop(void)
{
  sigcbreg(XSIGMY, &cbstop, 1);
  kprintf("%d\n", proctab[currpid].prstate);
  proctab[currpid].prstate = PR_SUSP;
  kprintf("%d\n", proctab[currpid].prstate);
}
