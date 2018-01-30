/* onandon.c - onandon */

#include <unistd.h>//

/*------------------------------------------------------------------------
 *  onandon - Print x infinite loop
 *------------------------------------------------------------------------
 */
void onandon()
{
  while( true )
  {
    putc(CONSOLE, 'x');
    sleep(2);
  }
}

