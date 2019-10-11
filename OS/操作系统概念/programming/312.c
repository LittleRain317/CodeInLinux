#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t pid;
	if ((pid = fork()) < 0)
	{
		perror("fork error");
		return -1;
	}
	else if (pid == 0)
	{
		printf("exit");
		return 0;
	}
	else
	{
		sleep(10000);
	}
	return 1;
}
