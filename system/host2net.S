/* Start the code section */
.text

/* Define host2net as a global (exported function */
.globl host2net
.type host2net, @function
host2net:
  /* Subroutine Prolouge */
  pushl %ebp
  movl  %esp, %ebp
  movl  8(%ebp), %eax
  bswap %eax
  leave
  ret
  
  
