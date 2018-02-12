#include <xinu.h>

char fun1(int x, int y)
{
  /* Print #3 */  
  kprintf("3. after appl1() calls fun1() and before fun1() returns:\n");
  kprintf("Base of the stack : Address - 0x%08X, Value - 0x%08X\n", proctab[currpid].prstkbase, *proctab[currpid].prstkbase);
  char *sp;
  asm volatile ("mov %%esp, %0;" : "=r"(sp));
  kprintf("Top of the stack : Address - 0x%08X, Value - 0x%08X\n", sp, *sp);

  return (char) (y-x);
}
