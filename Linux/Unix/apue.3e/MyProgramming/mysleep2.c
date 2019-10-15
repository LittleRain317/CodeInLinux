#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void(*pFunc)(int signo) = NULL;
static void sig_alrm1(int signo)
{
		pFunc(signo);
}

static void sig_alrm2(int signo)
{
}

unsigned int sleep1(unsigned int seconds)
{
	int ago = alarm(seconds);
	if (ago < seconds)
	{
		pFunc= signal(SIGALRM, sig_alrm1);
		if (pFunc == SIG_ERR)
			return seconds;
		if (pFunc == SIG_IGN || pFunc == SIG_DFL)
			signal(SIGALRM, pFunc);
		alarm(ago);
		pause();
		signal(SIGALRM, pFunc);
		return alarm(0);
	}
	else 
	{
		pFunc= signal(SIGALRM, sig_alrm2);
		if (pFunc == SIG_ERR)
			return seconds;
		alarm(seconds);
		pause();
		if (signal(SIGALRM, pFunc) == SIG_ERR)
			return alarm(0);
		alarm(ago - seconds);
		return ago - seconds;
	}
}

static void func(int signo)
{
	printf("func = %d\n", signo);
	return;
}
int main(int argc, char *argv[])
{
//	if (signal(SIGALRM, func) == SIG_ERR)
//		return -1;
	alarm(4);
//	sleep(6);
	printf("%d\n", sleep1(atoi(argv[1])));
//	sleep(1);
	sleep(8);
	return 0;
}
