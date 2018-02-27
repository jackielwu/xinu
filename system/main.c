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
  

  
  /* Problem 3*/  
  resume(create((void *)testloop, 4096, 10,"testloopA", 1, CONSOLE));
  resume(create((void *)testloop, 4096, 10,"testloopB", 1, CONSOLE));
  resume(create((void *)testloop, 4096, 10,"testloopC", 1, CONSOLE));
  resume(create((void *)testloop, 4096, 10,"testloopD", 1, CONSOLE));
  
  /* part f */
  resume(create((void *)testloop, 4096, 20,"testloopE", 1, CONSOLE));
  resume(create((void *)testloop, 4096, 30,"testloopF", 1, CONSOLE));


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
