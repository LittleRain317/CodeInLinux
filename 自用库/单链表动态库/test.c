#include "LinkList.h"
#include "default.h"
#include <time.h>
#define MAX 100

bool is_equal(const ElemType * data1, const ElemType * data2)
{
	if (NULL == data1 || NULL == data2)
		return false;
	int * p1 = (int *)data1;
	int * p2 = (int *)data2;
	return *p1 == *p2;
}

bool compare(const ElemType * data1, const ElemType * data2)
{
	if (NULL == data1 || NULL == data2)
		return false;
	int * p1 = (int *)data1;
	int * p2 = (int *)data2;
	return *p1 > *p2;
}
void output(const ElemType * data)
{
	if (NULL == data)
		return;
	printf("data = %d ", *(int *)data);
}
int main(void)
{
	srand((unsigned)time(NULL));
	LinkList linklist = init_LinkList_Default();
	for (int i = 0; i < MAX; ++i)
	{
		int a = rand();
		insert_LinkList_Default(&a, linklist, sizeof(int));
	}
	foreach_LinkList_Default(linklist, output);
	system("pause");
	return 0;
}