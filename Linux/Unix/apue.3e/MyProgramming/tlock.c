#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
pthread_mutex_t f_lock = PTHREAD_MUTEX_INITIALIZER;
void* noLock(void *arg)
{
	pthread_mutex_lock(&f_lock);	
	printf("%s:", __FUNCTION__);
	char buff[2][20] = { "24k傻逼(in1)", "傻逼24k(in1)" };
	write(STDOUT_FILENO, buff[0], strlen(buff[0]));
	write(STDOUT_FILENO, buff[1], strlen(buff[1]));
	pthread_mutex_unlock(&f_lock);
	return (void *)0;
}

void* noLock2(void *arg)
{

	pthread_mutex_lock(&f_lock);	
	printf("%s:", __FUNCTION__);
	char buff[2][20] = { "24k傻逼(in2)", "傻逼24k(in2)" };
	write(STDOUT_FILENO, buff[0], strlen(buff[0]));
	write(STDOUT_FILENO, buff[1], strlen(buff[1]));
	pthread_mutex_unlock(&f_lock);
	return (void *)0;
}

#define MAX 2
int main(void)
{
	int err = 0;
	pthread_t tid[MAX];
	for (int i = 0; i != MAX; ++i)
	{
		if (i & 1)
			err = pthread_create(&tid[i], NULL, noLock, NULL);
		else 
			err = pthread_create(&tid[i], NULL, noLock2, NULL);
		if (err != 0)
		{
			fprintf(stderr, "pthread_create error : %s", strerror(err));
		}
	}
	for (int i = 0; i != MAX; ++i)
	{
		if ((err = pthread_join(tid[i], NULL)) != 0)
		{
			fprintf(stderr, "pthread_join error : %s", strerror(err));
		}
		
	}
	return 0;
}
