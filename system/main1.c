/*  main1.c - main1 */

#include <xinu.h>
#include "onandon.h"

process main(void)
{
  recvclr();
  resume(create(onandon, 2048, 30, "onandon", 1, CONSOLE));
  pid_t cPID = fork();

  if (cPID == 0)
  {
    resume(create(onandon, 2048, 30, "onandon", 1, CONSOLE));
    sleep(14);
    kill(cPID);
  }
}
