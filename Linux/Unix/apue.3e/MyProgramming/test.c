#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	if ((pid = fork()) < 0)
	{
		printf("error\n");
	}
	else if (pid == 0)
	{
		printf("child\n");
		while (getppid() != 1)
			sleep(1);
	}
	else
	{

	sleep(2);
		printf("father\n");
	}
	int status = 0;
	if (waitpid(pid, &status, WNOHANG) != pid)
	{
		printf("error wait\n");
	}
	printf("done\n pid=%d ppid=%d\n", getpid(), getppid());
	return 0;
}
