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
  
  cputest();
  sleep(15);
  iotest();
  sleep(15);
  mixedtest();
  
  /* Problem 3*/
  /*  
  resume(create((void *)testloop, 2048, 10,"testloopA", 1, CONSOLE));
  resume(create((void *)testloop, 2048, 10,"testloopB", 1, CONSOLE));
  resume(create((void *)testloop, 2048, 10,"testloopC", 1, CONSOLE));
  resume(create((void *)testloop, 2048, 10,"testloopD", 1, CONSOLE));
  */
  /* part f */
  /*
  resume(create((void *)testloop, 2048, 20,"testloopE", 1, CONSOLE));
  resume(create((void *)testloop, 2048, 30,"testloopF", 1, CONSOLE));
  */
  /* Problem 4.3 */
  
  /* CPU Bound */
  /*  
  resume(create((void *)cpubound, 2048, 50,"cpuboundA", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, 50,"cpuboundB", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, 50,"cpuboundC", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, 50,"cpuboundD", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, 50,"cpuboundE", 1, CONSOLE));
  */

  /* IO Bound */ 
  /*  
  resume(create((void *)iobound, 2048, 50,"ioboundA", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 50,"ioboundB", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 50,"ioboundC", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 50,"ioboundD", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 50,"ioboundE", 1, CONSOLE));
  */

  /* Half and Half */
  /*
  resume(create((void *)cpubound, 2048, 50,"cpuboundA", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, 50,"cpuboundB", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, 50,"cpuboundC", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 50,"ioboundA", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 50,"ioboundB", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 50,"ioboundC", 1, CONSOLE));
  */


  //sleep(3);  
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
