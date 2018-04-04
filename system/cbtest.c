#include <xinu.h>
int32 mrecv_cb(void);

void cbtest(void)
{
    if (cbreg(&mrecv_cb) != OK)
    {
      kprintf("cb registration failed!");
      return 1;
    }

    //sendblk(pid, "A");
    sleep(5);
    sleep(2);
    sleep(2);
    sleep(2);
    sleep(2);
}

int32 mrecv_cb(void)
{
  //extern umsg32 mbuf;
  //mbuf = receive();
  kprintf("callback: %s\n", receive());
  //kprintf("callback\n");  
  return(OK);
}
