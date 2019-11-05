#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#define MAX 1000
#define CIN
#define NSYNC
int turn = 0; //0和1对应下标
bool flag[2] = { false, false};
int result = 0;

int s;
void P()
{
	while (s<=0)
		;
	s--;
}
void V()
{
	++s;
}

void* fun0(void* arg)
{
		
#ifdef CIN
		//进入区
		//
		flag[0] = true;
		turn = 1;
		//使用内存栅栏
#ifdef SYNC
		__sync_synchronize();
#endif
		while (flag[1] && turn == 1)
		{
			;
		}
#endif	
		//临界区
		result++;
		//推出区
#ifdef CIN
		flag[0] = false;
#endif
	return 0;
}
void* fun1(void* arg)
{
#ifdef CIN
		flag[1] = true;
		turn = 0;
#ifdef SYNC
		__sync_synchronize();
#endif
		while (flag[0] && turn == 0)
		{
			;
		}
#endif
		//临界区
	result++;
#ifdef CIN
		flag[1] = false;
#endif
	return 0;
}
void *fun(void* arg)
{
	for (int i = 0; i != MAX; ++i)
	{
		if (*(int*)arg == 1)
		{
			fun1(NULL);
		}
		else
		{
			fun0(NULL);
		}
	}
	return 0;
}
int main()
{
	pthread_t pid1;
	pthread_t pid2;
	int a = 0;
	int b = 1;
	pthread_create(&pid1, NULL, fun, &a);
	pthread_create(&pid2, NULL, fun, &b);
	pthread_join(pid1, NULL);
	printf("pid1完成\n");
	pthread_join(pid2, NULL);
	printf("result=%d\n", result);
	return 0;
}
