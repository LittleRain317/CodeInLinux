#include "../include/apue.h"
#include <sys/wait.h>

static void sig_cld(int);

int main(void)
{
	pid_t pid;
	if (signal(SIGCHLD, sig_cld) == SIG_ERR)
	{
		perror("signal error");
	}

	
	pause();
	exit(0);
}

static void sig_cld(int signo)
{
	printf("SIGCLD received\n");
	if (signal(SIGCHLD, sig_cld) == SIG_ERR)
		perror("signal error");
/*	
	if ((pid = wait(&status)) < 0)
		perror("wait error");
	printf("pid = %d\n", pid);
	*/
}
