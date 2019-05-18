#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main(void)
{
	//生产者进程3个
	pid_t producer[3];
	//消费者进程5个
	pid_t consumer[5];
	for (int i = 0; i < 3; ++i)
		producer[i] = fork();
	for (int i = 0; i < 5; ++i)
		consumer[i] = fork();
	for (int i = 0; i < 3; ++i)
		if (producer[i] == 0)
		{	
			execlp("./317", NULL, NULL);
			printf("生产者:%d", getpid());
		}
			else
			wait(NULL);
	for (int i = 0; i < 5; ++i)
		if (consumer[i] == 0)
		{	execlp("./318", NULL, NULL);
			printf("消费者:%d", getpid());
		}else
			wait(NULL);
	return 0;
}
