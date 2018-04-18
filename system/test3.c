#include <xinu.h>

void cb3(void)
{
  kprintf("XSIGXTM cb\n");
  sigcbunreg(XSIGXTM);
}


void test3(void)
{
  kprintf("begin test\n");
  if (sigcbreg(XSIGXTM, &cb3, 3) != OK)
  {
    kprintf("XSIGXTM registration failed\n");
    return 1;
  }
  //kprintf("sleeping\n");
  sleep(4);
  kprintf("Time passed.\n");
  //sleep(1);
}
