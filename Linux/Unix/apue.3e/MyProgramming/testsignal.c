#include "../include/apue.h"
#include <sys/wait.h>

static void sig_int(int e)
{
	printf("hello\n");
}

int main(void)
{
	char buf[MAXLINE];
	pid_t	pid;
	int status;

	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal error");
	while (1);
	exit(0);
}
