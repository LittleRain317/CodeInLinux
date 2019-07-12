#include "TwoWayLinkedList.h"
#include <time.h>
#define MAX 100
void output(const ElemType data)
{
	if (NULL == data)
		return;
	printf("data = %d ", *((int *)data));
}
bool isEqual(const ElemType data1, const ElemType data2)
{
	if (NULL == data1 || NULL == data2)
		return false;
	int * p1 = (int *)data1;
	int * p2 = (int *)data2;
	return *p1 == *p2;
}
int main(void)
{
	srand((unsigned)time(NULL));
	TowWayLinkedList linklist = init_TWLinkedList();
	int a[MAX] = { 0 };
	for (int i = 0; i < MAX; ++i)
		a[i] = 1;//rand();
	for (int i = 0; i < MAX; ++i)
		insert_TWLinkedList(&a[rand() % MAX], linklist, rand() % 2);
	//printf("节点个数%d \n", numOfNode_TWLinkedList(linklist));
	//printf("未删除前的结果!\n");
	//foreach_TWLinkedList(linklist, output);
	//printf("\n");
	//clear_TWLinkedList(linklist);
	//printf("%d \n", numOfNode_TWLinkedList(linklist));
	//deleteByVal_TWLinkedList(&a[0], linklist, isEqual, true);
	//printf("节点个数%d \n", numOfNode_TWLinkedList(linklist));
	//printf("删除第二个节点后的结果!\n");
	//foreach_TWLinkedList(linklist, output);
	//printf("\n");
	clear_TWLinkedList(linklist);
	printf("清空后的结果!\n");
	deleteByVal_TWLinkedList(&a[0], linklist, isEqual, true);
	//foreach_TWLinkedList(linklist, output);
	printf("\n");
	destroy_TWLinkedList(linklist);
	linklist = NULL;
	system("pause");
	return 0;
}