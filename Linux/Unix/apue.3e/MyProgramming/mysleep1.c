#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
static void sig_alrm(int signo)
{
}

unsigned int sleep1(unsigned int seconds)
{
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		return seconds;
	printf("之前的%d\n", alarm(seconds));
	pause();
	return alarm(0);
}

int main()
{
	alarm(30);
	printf("%d\n", sleep1(1));
	return 0;
}
