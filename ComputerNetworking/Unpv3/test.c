#include <signal.h>
#include <unistd.h>
#include <stdio.h>
void func(int signo)
{
	printf("%d\n", signo);
}
int main(int argc, char * argv[])
{
	signal(SIGUSR1, func);
	while (1)
	{
		kill(getpid(), SIGUSR1);
		sleep(2);
	}
	return 0;
}

