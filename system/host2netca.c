long host2netca(long x)
{
  return ((x & 0x000000ff) << 24u) | ((x & 0x0000ff00) << 8u) | ((x & 0x00ff0000) >> 8u) | ((x & 0xff000000) >> 24u);
}
