/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

extern void stackoverflowA(void);
extern void stackoverflowB(void);
extern int appl1(void);

process	main(void)
{
	kprintf("\nHello World!\n");
	kprintf("(Wu, Jackie)\nwu891\nI'm the first XINU app and running function main() in system/main.c.\n");
	kprintf("\nI was created by nulluser() in system/initialize.c using create().\n");
	kprintf("\nMy creator will turn itself into the do-nothing null process.\n");
	kprintf("\nI will create a second XINU app that runs shell() in shell/shell.c as an example.\n");
	kprintf("\nYou can do something else, or do nothing; it's completely up to you.\n");
	kprintf("\n...creating a shell\n");
  
  recvclr();
  
  /* Problem 4.2 */
  kprintf("1. main process before appl1():\n");
  kprintf("Base of the stack : Address - 0x%08X, Value - 0x%08X\n", proctab[currpid].prstkbase, *proctab[currpid].prstkbase);
  kprintf("Top of the stack : Address - 0x%08X, Value - 0x%08X\n", proctab[currpid].prstkbase+proctab[currpid].prstklen, *proctab[currpid].prstkbase+proctab[currpid].prstklen);


  /* BONUS */
  gocreate((void *)appl1, 2048, INITPRIO, "appl1", 1, CONSOLE);
  
  /* Problem 5 */  
  resume(create((void *)stackoverflowA, 2048, 10,"stackoverflowA", 1, CONSOLE));
  resume(create((void *)stackoverflowB, 2048, 15,"stackoverflowB", 1, CONSOLE));
  sleep(3);  
  //resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */
  /*
	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}*/
	return OK;
}
