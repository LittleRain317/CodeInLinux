#include <signal.h>
#include <unistd.h>
static void sig_alrm(int signo)
{
	return;
}

unsigned int sleep1(unsigned int seconds)
{
	void (*func)(int) = signal(SIGALRM, sig_alrm);
	if (func == SIG_ERR)
		return -1;
	return 0;
}

int main()
{
	sleep1(1);
	return 0;
}
