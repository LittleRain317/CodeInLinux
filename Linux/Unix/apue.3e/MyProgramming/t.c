#include <stdio.h>
#include <process.h>
int main( void )
{
/* If run froom command line, shows different ID for
* command line than for operating system shell.
*/
printf( "Process id: %d\n", _getpid() );
return 0;
}
