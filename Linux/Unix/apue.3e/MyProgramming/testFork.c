#include "../include/apue.h"

int globvar = 6; //.data段
char buf[] = "a write to stdout\n";

int main(void)
{
	int var;
	pid_t	pid;
	var = 88;
	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
		err_sys("write error");
	printf("before fork\n");	/* we don't flush*/
	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0)
	{
		globvar++;
		var++;
	}
	else
	{
		sleep(2);
	}
	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
	exit(0);
}
