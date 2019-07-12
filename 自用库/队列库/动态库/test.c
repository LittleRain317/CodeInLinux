#include "Queue.h"
#include <time.h>
#define MAX 100

int main(void)
{
	srand((unsigned)time(NULL));
	int a[MAX] = { 0 };
	Queue queue = init_Queue();
	for (int i = 0; i < MAX; ++i)
		a[i] = rand() % MAX;
	for (int i = 0; i < MAX; ++i)
		inqueue_Queue(queue, &a[i]);
	for (int i = 0; i <= MAX; ++i)
	{
		if (NULL != getHead_Queue(queue))
		{
			printf("head_data = %d ", *(int *)getHead_Queue(queue));
		}
		if (NULL != getTail_Queue(queue))
		{
			printf("tail_data = %d ", *(int *)getTail_Queue(queue));
		}
		if (-1 != numOfNode_Queue(queue))
		{
			printf("个数 = %d个\n", numOfNode_Queue(queue));
		}
		dequeue_Queue(queue);
	}
	clear_Queue(queue);
	if (NULL != getHead_Queue(queue))
	{
		printf("head_data = %d ", *(int *)getHead_Queue(queue));
	}
	if (NULL != getTail_Queue(queue))
	{
		printf("tail_data = %d ", *(int *)getTail_Queue(queue));
	}
	if (-1 != numOfNode_Queue(queue))
	{
		printf("个数 = %d个\n", numOfNode_Queue(queue));
	}
	dequeue_Queue(queue);
	destroy_Queue(queue);
	queue = NULL;
	if (NULL != getHead_Queue(queue))
	{
		printf("head_data = %d ", *(int *)getHead_Queue(queue));
	}
	if (NULL != getTail_Queue(queue))
	{
		printf("tail_data = %d ", *(int *)getTail_Queue(queue));
	}
	if (-1 != numOfNode_Queue(queue))
	{
		printf("个数 = %d个\n", numOfNode_Queue(queue));
	}
	dequeue_Queue(queue);
	system("pause");
	return 0;
}