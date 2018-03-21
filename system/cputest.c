#include <xinu.h>

void cputest()
{
  resume(create((void *)cpubound, 2048, 30,"cpuboundA", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, 30,"cpuboundB", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, 30,"cpuboundC", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, 30,"cpuboundD", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, 30,"cpuboundE", 1, CONSOLE));
}
