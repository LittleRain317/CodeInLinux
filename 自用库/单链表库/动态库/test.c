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
			printf("����ɾ������\n");
			deleteByVal_LinkList(&a[rand() % MAX], linklist, rand() % 2, equal);
			printf("------�ָ���------\n\n");
			break;
		case 1:
			printf("����ɾ������\n");
			deleteByPos_LinkList(rand() % MAX, linklist);//(&a[rand() % max], linklist, rand() % 2, equal);
			printf("------�ָ���------\n\n");
			break;
		case 2:
			printf("�����޸ĺ���\n");
			changeByPos_LinkList(rand() % MAX, linklist, &a[rand() % MAX]);
			printf("------�ָ���------\n\n");
			break;
		case 3:
			printf("�����滻����\n");
			replace_LinkList(&a[rand() % MAX], &a[rand() % MAX], linklist, rand() % 2, equal);
			printf("------�ָ���------\n\n");
			break;
		case 4:
			printf("����������\n");
			sort_LinkList(linklist, compare);
			printf("��ӡ������\n");
			foreach_LinkList(linklist, output);
			printf("------�ָ���------\n\n");
			break;
		case 5:
			printf("���Խ���������\n");
			printf("%d��\n", numOfNode_LinkList(linklist));
			printf("------�ָ���------\n\n");
			break;
		case 6:
			printf("���Է�ת����\n");
			printf("��תǰ\n");
			foreach_LinkList(linklist, output);
			printf("------�ָ���------\n\n");
			reverse_LinkList(linklist);
			printf("��ת��\n");
			foreach_LinkList(linklist, output);
			printf("------�ָ���------\n\n");
			break;
		case 7:
			printf("���Բ��ҽ�㺯��\n");
			ElemType test = findByPos_LinkList(rand() % MAX, linklist);
			printf("��ӡ���\n");
			output(test);
			printf("\n------�ָ���------\n\n");
			test = NULL;
			break;
		default:
			;
		}
	}
	//���
	clear_Linklist(linklist);
	//����
	destroy_Linklist(linklist);
	system("pause");
	return 0;
}