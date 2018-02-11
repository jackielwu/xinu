long host2neta(long x)
{
  long res;
  asm ("bswap %0"
      : "=r" (res) :"0" (x));
  return res;
}
