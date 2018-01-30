/*  main1.c - main1 */

#include <xinu.h>
#include "onandon.h"

process main(void)
{
  pid_t cPID = create(onandon, 2048, 30, "onandon", 1, CONSOLE);
  resume(cPID);
  sleep(14);
  kill(cPID);
}
