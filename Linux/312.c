#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
	pid_t pid;
	pid = fork();
	if (pid < 0)
	{
		printf("Fork Failed!\n");
		return 1;
	}
	else if (pid == 0)
	{
		printf("Child run.!\n");
	}
	else 
	{
		printf("parent run!\n");
		sleep(10);
	}
	return 0;
}
