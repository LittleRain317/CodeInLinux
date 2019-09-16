#include "../include/apue.h"
#include <unistd.h>
int globvar = 6;		
int main(void)
{
	int var;
	pid_t	pid;
	var = 88;
	printf("before vfork\n");
	if ((pid = vfork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0)
	{
		globvar++;
		var++;
		fclose(stdout);
		_exit(0);
	}
	printf("result = %d\n",printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var));
	exit(0);
}
