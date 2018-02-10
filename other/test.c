#include <stdlib.h>
#include <stdio.h>
//#include "../system/host2netca.c"
extern long host2netca();

int main()
{
  long num = 69;
  printf("%ld\n", host2netca(num));
}
