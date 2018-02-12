#include <xinu.h>
//#include "../system/host2netca.c"
//extern long host2net(long x);
//extern long host2netca(long x);
//extern long host2neta(long x);
extern int appl1(void);

int main()
{
  kprintf("1. main process before appl1():\n");
  kprintf("Base of the stack : Address - 0x%08X, Value - 0x%08X\n", proctab[currpid].prstkbase, *proctab[currpid].prstkbase);
  kprintf("Top of the stack : Address - 0x%08X, Value - 0x%08X\n", proctab[currpid].prstkbase+proctab[currpid].prstklen, *proctab[currpid].prstkbase+proctab[currpid].prstklen);

  resume(create((void *)appl1, 2048, INITPRIO, "appl1", 1, CONSOLE));
  
  //long num = 69;
  //kprintf("%d\n", host2net(num));
  //kprintf("%d\n", host2netca(num));
  //kprintf("%d\n", host2neta(num));
}
