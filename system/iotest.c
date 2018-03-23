#include <xinu.h>

void iotest()
{
  #ifdef BONUS
    #define tp 15
  #else
    #define tp 30
  #endif
  resume(create((void *)iobound, 2048, tp,"ioboundA", 1, CONSOLE));
  resume(create((void *)iobound, 2048, tp,"ioboundB", 1, CONSOLE));
  resume(create((void *)iobound, 2048, tp,"ioboundC", 1, CONSOLE));
  resume(create((void *)iobound, 2048, tp,"ioboundD", 1, CONSOLE));
  resume(create((void *)iobound, 2048, tp,"ioboundE", 1, CONSOLE));
}
