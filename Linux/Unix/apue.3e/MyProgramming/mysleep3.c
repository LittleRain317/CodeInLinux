#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <setjmp.h>
static jmp_buf env_alrm;
static void (*pFunc)(int signo) = NULL;

static void sig_alrm1(int signo)
{
	longjmp(env_alrm, 1);
}

static void sig_alrm2(int signo)
{
	pFunc(signo);
	longjmp(env_alrm, 2);
}

unsigned int sleep3(unsigned int seconds)
{
	int ago = alarm(0); 
	if (ago < seconds)
	{
		pFunc = signal(SIGALRM, sig_alrm2);
		if (pFunc == SIG_ERR)
		{
			alarm(ago);
			return seconds;
		}
		if (pFunc == SIG_DFL || pFunc == SIG_DFL)
		{
			signal(SIGALRM, pFunc);
		}
		if (setjmp(env_alrm) == 0)
		{
			alarm(ago);
			pause();
		}
		signal(SIGALRM, pFunc);
		return alarm(0);
	}
	else
	{
		pFunc = signal(SIGALRM, sig_alrm1);
		if (pFunc == SIG_ERR)
			return seconds;
		if (setjmp(env_alrm) == 0)
		{
			alarm(seconds);
			pause();
		}
		if (signal(SIGALRM, pFunc) == SIG_ERR)
			return ago - seconds;
		printf("剩余时间:%d\n", alarm(ago - seconds));
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
	if (signal(SIGALRM, func) == SIG_ERR)
		return -1;
	alarm(3);
	//sleep(atoi(argv[1]));
//	sleep(1);
	printf("%d\n", sleep3(atoi(argv[1])));
//	alarm(4);
	sleep(8);
	return 0;
}
