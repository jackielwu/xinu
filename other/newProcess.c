/* newProcess.c - newProcess */

#include <unistd.h>//

/*------------------------------------------------------------------------
 *  newProcess - Wrapper function to execute binary
 *------------------------------------------------------------------------
 */
int newProcess(
    const char *filename  /* Filename of executable binary  */
  )
{
  /* Call fork */
  pid_t childPID = fork();
  
  if ( childPID == 0 )
  {
    /* Call execve */
    execve(filename, NULL, NULL);
    _exit(1);
  }

  return 0;
}
