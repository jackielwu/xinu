#include <xinu.h>

void cpubound()
{
  for (int32 i = 0; i < UP1; i++)
  {
    for (int32 j = 0; j < UP2; j++)
    {
      const char src[50] = "http://www.tutorialspoint.com";
      char dest[50];
      memcpy(dest, src, strlen(src)+1);
      i * j;
      kprintf("PID: %2d\tOuter: %d\tPRCPUTOT: %u\n", currpid, i, getcputot(currpid));
    }
  }
  kprintf("PID: %2d\tPRCPUTOT: %u\tPRPRIO: %d\tPREEMPT: %d\n", currpid, getcputot(currpid), proctab[currpid].prprio, preempt);
}
