#include <xinu.h>

void prnsegadd()
{
  kprintf("Start of Text at 0x%08X, end of Text at 0x%08X.\n", (uint32)&text, (uint32)&etext-1);
  kprintf("Start of Data at 0x%08X, end of Data at 0x%08X.\n", (uint32)&data, (uint32)&edata-1);
  kprintf("Start of Bss at 0x%08X, end of Bss at 0x%08X.\n", (uint32)&bss, (uint32)&ebss-1);
  kprintf("End of XINU at 0x%08X.\n", (uint32)&text);
  kprintf("Text Length : %d bytes\n", (uint32)&etext - (uint32)&text);
  kprintf("Data Length : %d bytes\n", (uint32)&edata - (uint32)&data);
  kprintf("BSS Length : %u bytes\n", (uint32)&ebss - (uint32)&bss);
}
