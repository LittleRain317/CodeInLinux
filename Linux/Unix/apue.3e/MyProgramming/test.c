#include <apue/apue.h>
extern unsigned int sleep2(unsigned int seconds);

static void sig_int(int signo)
{
	int i, j;
	volatile int k;

	printf("\nsig_int starting\n");
	for ( i = 0; i < 300000; i++)
		for (j = 0; j < 4000; j++)
			k += i * j;
	printf("sig_int finished\n");
}

int main(void)
{
	unsigned int unslept;
	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal error");
	unslept = sleep2(5);
	printf("slee2 returned: %u\n", unslept);
	return 0;	
}


