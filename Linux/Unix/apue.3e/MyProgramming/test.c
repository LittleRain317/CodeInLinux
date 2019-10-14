#include <unistd.h>
#include <stdio.h>
#include <signal.h>
void sig_alrm(int arg)
{
	return;
}
int main()
{
	printf("24k傻逼\n");
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
	{
		perror("signal error");
		return -1;
	}
	alarm(1);
	pause();
	perror("what");

	printf("24k傻逼\n");
	return 0;
}
