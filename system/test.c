#include <xinu.h>
//#include "../system/host2netca.c"
extern long host2netca();

int main()
{
  long num = 69;
  kprintf("%ld\n", host2netca(num));
}
