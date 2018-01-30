/* onandon.c - onandon */

#include <xinu.h>//

/*------------------------------------------------------------------------
 *  onandon - Print x infinite loop
 *------------------------------------------------------------------------
 */
void onandon()
{
  while( 1 )
  {
    putc(CONSOLE, 'x');
    sleep(2);
  }
}

