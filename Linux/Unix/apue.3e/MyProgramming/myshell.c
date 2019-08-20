#include "../include/apue.h"
#include <sys/wait.h>
int main(void)
{
	char buf[MAXLINE] = { 0 };
	pid_t	pid;
	int status = 0;

	printf("%% ");	/* print prompt (printf requires %% to print %) */
	while (fgets(buf, MAXLINE, stdin) != NULL) 
	{
		if (buf[strlen(buf) - 1] == '\n')
		{
			buf[strlen(buf) - 1] = 0; /* replace newline with null */
		}
		if ((pid = fork()) < 0)
		{
			err_sys("fork error");
		}
		else if (pid == 0)
		{
			execlp(buf, buf, (char*)0);
			err_ret("couldn' execute: %s", buf);
			exit(127);
		}
		if ((pid = waitpid(pid, &status, 0)) < 0)
		{
			err_sys("waitpid error");
		}
		printf("%% ");
	}
	exit(0);
}
