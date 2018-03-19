#define PRIO_LEVELS 60

struct xts_tab {
  int xts_quantum;  //new time slice
  int xts_tqexp;    //new priority: CPU-intensive (time quantum expired)
  int xts_slpret;   //new priority: I/O-intensive (sleep return)
};

extern struct xts_tab xts_conf[];
