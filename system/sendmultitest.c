#include <xinu.h>

void sendmultitest(pid32 pid)
{
    sendblk(pid, "A");
    //kprintf("send: A\n");
    sendblk(pid, "B");
    //kprintf("send: B\n");
    sendblk(pid, "C");
    //kprintf("send: C\n");
    sendblk(pid, "D");
    //kprintf("send: D\n");
}
