#include "apue.h"
#include <sys/wait.h>
int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status = 0;
	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;
		if ((pid = fork()) < 0)
		{
			err_sys("fork error");
		}
		else if (pid > 0)//child thread
		{
			execlp(buf, buf, (char *)0);
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}
		else if ((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		printf("%% ");
	}
	exit (0);
}
