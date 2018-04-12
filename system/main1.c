/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

extern void rcvtest(void);
extern void cbtest(void);
extern void sendmultitest(pid32 pid);

process	main(void)
{
	kprintf("\nHello World!\n");
	kprintf("\nI'm the first XINU app and running function main() in system/main.c.\n");
	kprintf("\nI was created by nulluser() in system/initialize.c using create().\n");
	kprintf("\nMy creator will turn itself into the do-nothing null process.\n");
	kprintf("\nI will create a second XINU app that runs shell() in shell/shell.c as an example.\n");
	kprintf("\nYou can do something else, or do nothing; it's completely up to you.\n");
	kprintf("\n...creating a shell\n");
	recvclr();
	
  
  //resume(create((void *)rcvtest, 2048, 10, "receive", 1, CONSOLE));
  pid32 rpid = create((void *)cbtest, 2048, 10, "cbtest", 0, NULL);
  resume(rpid);
  //resume(create((void *)sendmultitest, 2048, 10, "sendmultitest", 1, rpid));
  resume(create(sendblk, 2048, 20, "sendblkA", 2, rpid, "A"));
  resume(create(sendblk, 2048, 20, "sendblkB", 2, rpid, "B"));
  resume(create(sendblk, 2048, 20, "sendblkC", 2, rpid, "C"));
  resume(create(sendblk, 2048, 20, "sendblkD", 2, rpid, "D"));
  
  /*
  resume(create(shell, 8192, 50, "shell", 1, CONSOLE));
  while(TRUE) {
    receive();
    sleepms(200);
    kprintf("\n\nMain process recreating shell\n\n");
    resume(create(shell, 4096, 20, "shell", 1 CONSOLE));
  }
  */
	return OK;
}
