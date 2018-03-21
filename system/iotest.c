#include <xinu.h>

void iotest()
{
  resume(create((void *)iobound, 2048, 30,"ioboundA", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 30,"ioboundB", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 30,"ioboundC", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 30,"ioboundD", 1, CONSOLE));
  resume(create((void *)iobound, 2048, 30,"ioboundE", 1, CONSOLE));
}
