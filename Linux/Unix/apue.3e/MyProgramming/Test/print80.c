#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
int num = 1;
void* fun1(void *arg)
{
	int err = 0;
	while (num <= 75)
	{
		pthread_mutex_lock(&mutex);
		printf("线程1:");
		for (int i = 0; i < 5; ++i)
		{	
			printf("%d ", num);
			num++;
		}
		printf("\n");
		pthread_mutex_unlock(&mutex);
		sleep(0);
		if ( (err = pthread_cond_signal(&cond1)) != 0)
		{
			fprintf(stderr, "%s", strerror(err));
		}
		sleep(0);
	}	
	return NULL;
}
void* fun2(void *arg)
{
	int err = 0;
	while (num <= 75)
	{
		pthread_mutex_lock(&mutex);
		err = pthread_cond_wait(&cond1, &mutex);
		if (err != 0)
		{

			fprintf(stderr, "%s", strerror(err));
		}
		printf("线程2:");
		for (int i = 0; i < 5; ++i)
		{	
			printf("%d ", num);
			num++;
		}
		printf("\n");
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main()
{
	pthread_t tid[2];
	pthread_create(&tid[0], NULL, fun1, NULL);
	pthread_create(&tid[1], NULL, fun2, NULL);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	return 0;
}
