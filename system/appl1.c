#include <xinu.h>

int appl1()
{
  /* Print #2 */
  kprintf("2. after appl1() is created before fun1() is called:\n");
  kprintf("Base of the stack : Address - 0x%08X, Value - 0x%08X\n", proctab[currpid].prstkbase, *proctab[currpid].prstkbase);
  char *sp;
  asm volatile ("mov %%esp, %0;" : "=r"(sp));
  kprintf("Top of the stack : Address - 0x%08X, Value - 0x%08X\n", sp, *sp);

  fun1('h','i');
  /* Print #4 */
  kprintf("4. after appl1() calls fun1() and after fun1() has returned:\n");
  kprintf("Base of the stack : Address - 0x%08X, Value - 0x%08X\n", proctab[currpid].prstkbase, *proctab[currpid].prstkbase);
  asm volatile ("mov %%esp, %0;" : "=r"(sp));
  kprintf("Top of the stack : Address - 0x%08X, Value - 0x%08X\n", sp, *sp);
  return 0;
}
