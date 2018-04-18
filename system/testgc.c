/* testgc.c - testgc */

#include <xinu.h>

void testgc(void)
{
  uint32 free_mem = 0;
  uint32 allo_mem = 0;
  uint32 leak_mem = 0;
  struct memblk *memptr;
  for (memptr = memlist.mnext; memptr != NULL; memptr = memptr->mnext)
  {
    free_mem += memptr->mlength;
  }
  kprintf("%10d bytes of free. Free list:\n", free_mem);

  for (memptr = proctab[currpid].gclist.mnext; memptr != NULL; memptr = memptr->mnext)
  {
    allo_mem += memptr->mlength;
  }

  kprintf("%10d bytes used. Alloc list:\n", allo_mem);

  char *ptr = getmem(1024);
  freemem(ptr, 1024);
  
  free_mem = 0;
  for (memptr = memlist.mnext; memptr != NULL; memptr = memptr->mnext)
  {
    free_mem += memptr->mlength;
  }
  kprintf("%10d bytes of free. Free list:\n", free_mem);
  allo_mem;
  for (memptr = proctab[currpid].gclist.mnext; memptr != NULL; memptr = memptr->mnext)
  {
    allo_mem += memptr->mlength;
  }
  kprintf("%10d bytes used. Alloc list:\n", allo_mem);

}
