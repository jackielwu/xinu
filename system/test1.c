#include <xinu.h>

void cb1(void)
{
  kprintf("XSIGRCV cb\n");
  sigcbunreg(XSIGRCV);
}


void test1(void)
{
  kprintf("begin test\n");
  if (sigcbreg(XSIGRCV, &cb1, 1) != OK)
  {
    kprintf("XSIGRCV registration failed\n");
    return 1;
  }
  //kprintf("sending\n");
  send(currpid, "A");
  //kprintf("sent\n");
  sleep(5);
  /*kprintf("looping\n");
  while(TRUE)
  {
    sleep(1);
  }*/
}
