#include <xinu.h>

void rcvtest(void)
{

    umsg32 m1 = receive();
    kprintf("receive: %s\n",m1);
    //kill(currpid);
    umsg32 m2 = receive();
    kprintf("receive: %s\n",m2);
    umsg32 m3 = receive();
    kprintf("receive: %s\n",m3);
    umsg32 m4 = receive();
    kprintf("receive: %s\n",m4);
    
}
