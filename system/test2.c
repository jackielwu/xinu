#include <xinu.h>

void cb2(void)
{
  kprintf("XSIGCHL cb\n");
  sigcbunreg(XSIGCHL);
}

void child(void)
{
  kprintf("child process\n");
}


void test2(void)
{
  kprintf("begin test\n");
  if (sigcbreg(XSIGCHL, &cb2, 1) != OK)
  {
    kprintf("XSIGCHL registration failed\n");
    return 1;
  }
  //kprintf("making child\n");
  resume(create(child, 2048, 20, "child", 0, NULL));
  childwait();
  //kprintf("waiting\n");
  sleep(5);
  //kprintf("looping\n");
  while(TRUE)
  {
    sleep(1);
  }
}
