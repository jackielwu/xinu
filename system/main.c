/* main.c - main */

#include <xinu.h>
#include <stdio.h>

extern void rcvtest(void);
extern void cbtest(void);
extern void sendmultitest(pid32 pid);
extern void test1(void);
extern void test2(void);
extern void test3(void);
extern void testgc(void);
extern void teststop(void);

process main(void)
{
  kprintf("\nHello World!\n");
  kprintf("\nI'm the first XINU app and running function main() in system/main.c\n");
  kprintf("\nI was created by nulluser() in system/initialize.c using create().\n");
  kprintf("\nMy creator will turn itself into the do-nothing null process.\n");
  kprintf("\nI will create a second XINU app that runs shell() in shell/shell.c as an example.\n");
  kprintf("\nYou can do something else, or do nothing; it's completely up to you.\n");
  kprintf("\n...creating a shell\n");
  recvclr();
  /*
  struct memblk *memptr;
  uint32 allo_mem = 0;
  uint32 free_mem = 0;
  for (memptr = memlist.mnext; memptr != NULL; memptr = memptr->mnext)
  {
    free_mem += memptr->mlength;
  }
  kprintf("%10d bytes of free. Free list:\n", free_mem);
  allo_mem;
  for (memptr = proctab[currpid].gclist.mnext; memptr != NULL; memptr = memptr->mnext)
  {
    allo_mem += memptr->mlength;
  }
  kprintf("%10d bytes used. Alloc list:\n", allo_mem);
  */

  //resume(create(test1, 2048, 20, "SIGRCV", 0, NULL));
  //resume(create(test2, 2048, 20, "SIGCHL", 0, NULL));
  //resume(create(test3, 2048, 20, "SIGXTM", 0, NULL));
  //resume(create(testgc, 2048, 20, "gc test", 0, NULL));
  /*
  sleep(5);
  allo_mem = 0;
  free_mem = 0;
  for (memptr = memlist.mnext; memptr != NULL; memptr = memptr->mnext)
  {
    free_mem += memptr->mlength;
  }
  kprintf("%10d bytes of free. Free list:\n", free_mem);
  allo_mem;
  for (memptr = proctab[currpid].gclist.mnext; memptr != NULL; memptr = memptr->mnext)
  {
    allo_mem += memptr->mlength;
  }
  kprintf("%10d bytes used. Alloc list:\n", allo_mem);
  */
  resume(create(teststop, 2048, 20, "SIGSTOP", 0, NULL));
  
  /*
  resume(create(shell, 8192, 50, "shell", 1, CONSOLE));
  while(TRUE) {
    receive();
    sleepms(200);
    kprintf("\n\nMain process recreating shell\n\n");
    resume(create(shell, 4096, 20, "shell", 1 CONSOLE));
  }
  */
  while(TRUE)
  {
    sleepms(100);
  }
  return OK;

}
