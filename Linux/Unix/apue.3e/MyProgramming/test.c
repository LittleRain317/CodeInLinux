#include <signal.h>
#include <apue.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void f(int id)
{
	printf("%d\n", id);
}
int main (void){
	pid_t pid;
	if (signal(SIGCHLD, f) == SIG_ERR)
	{
		perror("error for signal");
	}
		pid = fork();
		if (pid < 0)
			exit(-1);
		else if (pid == 0)
		{
			exit(12);
		}
		else
		{
			sleep(4);
		}
	return 0;
}
