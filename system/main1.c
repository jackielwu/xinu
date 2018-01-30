/*  main1.c - main1 */

#include <xinu.h>

process main(void)
{
  pid32 cPID = create(onandon, 2048, 30, "onandon", 1, CONSOLE);
  resume(cPID);
  sleep(14);
  kill(cPID);
  return OK;
}
