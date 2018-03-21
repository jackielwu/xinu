#include <xinu.h>

void mixedtest()
{
  resume(create((void *)cpubound, 2048, 30,"cpuboundF", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, 30,"cpuboundG", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, 30,"cpuboundH", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 30,"ioboundF", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 30,"ioboundG", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 30,"ioboundH", 1, CONSOLE));
}
