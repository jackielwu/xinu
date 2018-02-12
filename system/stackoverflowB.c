#include <xinu.h>
void stackoverflowB(void)
{
  while(1)
  {
    putc('B');
    sleepms(1500);
  }
}
