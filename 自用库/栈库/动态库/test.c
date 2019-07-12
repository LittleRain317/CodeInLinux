#include "Stack.h"
#include <time.h>
#define MAX 100000
int main(void)
{
	srand((unsigned)time(NULL));
	Stack stack = init_Stack();
	int a[MAX] = { 0 };
	for (int i = 0; i < MAX; ++i)
		a[i] = rand() % MAX;
	for (int i = 0; i < MAX; ++i)
	{
		int select = rand() % 4;
		switch (select)
		{
		case 0:
			push_Stack(stack, &a[rand() % MAX]);
			break;
		case 1:
			pop_Stack(stack);
			break;
		case 2:
			if (getTop_Stack(stack) != NULL)
				printf("data = %d \n", *(int *)getTop_Stack(stack));
			break;
		case 3:
			printf("节点个数为:%d\n", numOfNode_Stack(stack));
			break;
		default:
			break;
		}
	}
	clear_Stack(stack);
	destroy_Stack(stack);
	stack = NULL;
	system("pause");
	return 0;
}