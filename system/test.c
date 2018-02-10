#include <xinu.h>
//#include "../system/host2netca.c"
extern long host2net(long x);
extern long host2netca(long x);

int main()
{
  long num = 69;
  kprintf("%d\n", host2net(num));
  kprintf("%d\n", host2netca(num));
}
