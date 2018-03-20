#include <xinu.h>

pri16 xts_priochk(void)
{
  for (int i = PRIO_LEVELS-1; i >= 0; i--)
  {
      if (xts_ready[i].status != 0)
      {
        if (i > 0) 
        {
          return (pri16) i;
        }
      }
  }
  return (pri16) 0;
}
