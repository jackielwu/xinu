#include <xinu.h>
void iobound()
{
   for (int32 i = 0; i < UP1; i++)
   {
     for (int32 j = 0; j < UP2; j++)
     {
       sleepms(5);
       kprintf("PID: %u\tOuter: %d\tPRCPUTOT: %u\n", currpid, i, proctab[currpid].prcputot);
     }
   }
   kprintf("PID: %u\tPRCPUTOT: %u\tPRPRIO: %d\tPREEMPT: %d\n", currpid, getcputot(currpid), proctab[currpid].prprio, preempt);
}
