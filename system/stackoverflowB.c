#include <xinu.h>
void stackoverflowB(void)
{
  while(1)
  {
    putc(CONSOLE, 'B');
    sleepms(1500);
  }
}
