#include <xinu.h>

void prnsegadd()
{
  kprintf("Start of Text at %X, end of Text at %X.\n", text, etext);
  kprintf("Start of Data at %X, end of Data at %X.\n", data, edata);
  kprintf("Start of Bss at %X, end of Bss at %X.\n", bss, ebss);
  kprintf("End of XINU at %X.\n", end);
  kprintf("Text Length : %d bytes\n", (etext - text));
  kprintf("Data Length : %d bytes\n", (edata - data));
  kprintf("BSS Length : %u bytes\n", (ebss - bss));
}
