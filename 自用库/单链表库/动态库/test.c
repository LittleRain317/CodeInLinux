#include "LinkList.h"
#include <time.h>

#define MAX 1000
bool compare(ElemType data1, ElemType data2)
{
	int * p1 = NULL;
	int * p2 = NULL;
	p1 = (int *)data1, p2 = (int *)data2;
	return *p1 > *p2;
}
bool equal(ElemType data1, ElemType data2)
{
	int * p1 = NULL;
	int * p2 = NULL;
	p1 = (int *)data1, p2 = (int *)data2;
	return *p1 == *p2;
}

void output(void * data)
{
	if (NULL == data)
		return;
	printf("%d ", *((int *)data));
}

int main(void)
{
	LinkList linklist = init_LinkList();
	srand((unsigned)time(NULL));
	int a[MAX] = { 0 };
	for (int i = 0; i < MAX; ++i)
	{
		a[i] = rand();
		insert_LinkList(&a[i], linklist, rand() % 2);
	}
	foreach_LinkList(linklist, output);
	printf("\n");
	for (int i = 0; i < MAX / 10; ++i)
	{
		int select = rand() % 8;
		switch (select)
		{
		case 0:
			printf("测试删除函数\n");
			deleteByVal_LinkList(&a[rand() % MAX], linklist, rand() % 2, equal);
			printf("------分割线------\n\n");
			break;
		case 1:
			printf("测试删除函数\n");
			deleteByPos_LinkList(rand() % MAX, linklist);//(&a[rand() % max], linklist, rand() % 2, equal);
			printf("------分割线------\n\n");
			break;
		case 2:
			printf("测试修改函数\n");
			changeByPos_LinkList(rand() % MAX, linklist, &a[rand() % MAX]);
			printf("------分割线------\n\n");
			break;
		case 3:
			printf("测试替换函数\n");
			replace_LinkList(&a[rand() % MAX], &a[rand() % MAX], linklist, rand() % 2, equal);
			printf("------分割线------\n\n");
			break;
		case 4:
			printf("测试排序函数\n");
			sort_LinkList(linklist, compare);
			printf("打印排序结果\n");
			foreach_LinkList(linklist, output);
			printf("------分割线------\n\n");
			break;
		case 5:
			printf("测试结点个数函数\n");
			printf("%d个\n", numOfNode_LinkList(linklist));
			printf("------分割线------\n\n");
			break;
		case 6:
			printf("测试反转函数\n");
			printf("反转前\n");
			foreach_LinkList(linklist, output);
			printf("------分割线------\n\n");
			reverse_LinkList(linklist);
			printf("反转后\n");
			foreach_LinkList(linklist, output);
			printf("------分割线------\n\n");
			break;
		case 7:
			printf("测试查找结点函数\n");
			ElemType test = findByPos_LinkList(rand() % MAX, linklist);
			printf("打印结果\n");
			output(test);
			printf("\n------分割线------\n\n");
			test = NULL;
			break;
		default:
			;
		}
	}
	//清空
	clear_Linklist(linklist);
	//销毁
	destroy_Linklist(linklist);
	system("pause");
	return 0;
}