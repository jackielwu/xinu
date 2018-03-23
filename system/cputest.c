#include <xinu.h>

void cputest()
{
  #ifdef BONUS
    #define tp 15
  #else
    #define tp 30
  #endif
  resume(create((void *)cpubound, 2048, tp,"cpuboundA", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, tp,"cpuboundB", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, tp,"cpuboundC", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, tp,"cpuboundD", 1, CONSOLE));
  resume(create((void *)cpubound, 2048, tp,"cpuboundE", 1, CONSOLE));
}
