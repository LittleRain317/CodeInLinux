#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#define MAX 1000
#define CIN
int turn = 0; //0和1对应下标
bool flag[2] = { false, false};
int result = 0;
void* fun1(void* arg);
void* fun0(void* arg);
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
		printf("i=%d\n", i);
	}
	return 0;
}
void* fun0(void* arg)
{
		
#ifdef CIN
		//进入区
		//
//		flag[0] = true;
		turn = 1;
		while (turn == 1)
		{
			printf("turn=%d\n", turn);
			;
		}
#endif	
		//临界区
		result++;
		//推出区
#ifdef CIN
//		flag[0] = false;
#endif
	printf("result=%d\n", result);
	return 0;
}
void* fun1(void* arg)
{
#ifdef CIN
//		flag[1] = true;
		turn = 0;
		while (turn == 0)
		{
			printf("turn=%d\n", turn);
			;
		}
#endif
		//临界区
	result++;
#ifdef CIN
//		flag[1] = false;
#endif
	printf("result=%d\n", result);
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
	pthread_join(pid2, NULL);
	printf("等待完成\n");
	printf("result=%d\n", result);
	return 0;
}
