#include "TwoWayLinkedList.h"

typedef struct Node
{
	ElemType data;
	struct Node * next;
	struct Node * front;
}Node, * ptrNode;

typedef struct LinkList
{
	ptrNode head;
	ptrNode tail;
	unsigned num;
}LinkList, * ptrLinkList;

TowWayLinkedList init_TWLinkedList(void)
{
	ptrLinkList mylinklist = (ptrLinkList)malloc(sizeof(LinkList));
	if (NULL == mylinklist)
	{
		printf("空间不足!\n");
		return NULL;
	}
	memset((void *)mylinklist, 0, sizeof(LinkList));
	mylinklist->head = (ptrNode)malloc(sizeof(Node));
	if (NULL == mylinklist->head)
	{
		printf("空间不足!\n");
		free(mylinklist);
		mylinklist = NULL;
		return NULL;
	}
	memset(mylinklist->head, 0, sizeof(Node));
	mylinklist->tail = mylinklist->head;
	return (TowWayLinkedList)mylinklist;
}

void insert_TWLinkedList(const ElemType data, TowWayLinkedList linklist, bool flagHead)
{
	if (NULL == data || NULL == linklist)
	{
		printf("存在参数为空!\n");
		return;
	}
	ptrLinkList mylinklist = (ptrLinkList)linklist;
	mylinklist->num++;
	//储存新数据
	ptrNode newData = (ptrNode)malloc(sizeof(Node));
	if (NULL == newData)
	{
		printf("空间不足!\n");
		return;
	}
	memset(newData, 0, sizeof(Node));
	newData->data = data;
	//判断是否是第一次插入
	if (1 == mylinklist->num)
	{
		mylinklist->head->next = newData;
		newData->front = mylinklist->head;
		mylinklist->tail = newData;
		return;
	}
	if (flagHead)
	{
		newData->next = mylinklist->head->next;
		mylinklist->head->next = newData;
		newData->front = mylinklist->head;
	}
	else
	{
		newData->front = mylinklist->tail;
		mylinklist->tail->next = newData;
		mylinklist->tail = newData;
	}
}

void deleteByPos_TWLinkedList(Pos pos, TowWayLinkedList linklist)
{
	if (NULL == linklist)
	{
		printf("存在参数为空!\n");
		return;
	}
	ptrLinkList mylinklist = (ptrLinkList)linklist;
	if (pos >= mylinklist->num)
	{
		printf("越界!\n");
		return;
	}
	mylinklist->num--;
	ptrNode pCurrent = mylinklist->head->next;
	ptrNode pFront = mylinklist->head;
	for (Pos i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
		pFront = pFront->next;
	}
	pFront->next = pCurrent->next;
	//判断待删除节点是否为尾节点
	if (pCurrent == mylinklist->tail)
	{
		mylinklist->tail = pFront;
		return;
	}
	pCurrent->next->front = pFront;
	free(pCurrent);
	pCurrent = NULL;
}

void deleteByVal_TWLinkedList(const ElemType data, TowWayLinkedList linklist, const ISEQUAL isEqual, bool flagAll)
{
	if (NULL == data || NULL == linklist || NULL == isEqual)
	{
		printf("存在参数为空!\n");
		return;
	}
	ptrLinkList mylinklist = (ptrLinkList)linklist;
	ptrNode pCurrent = mylinklist->head->next;
	ptrNode pFront = mylinklist->head;
	while (pCurrent)
	{
		if (isEqual(pCurrent->data, data))
		{
			mylinklist->num--;
			pFront->next = pCurrent->next;
			//判断待删除节点是否为尾节点
			if (pCurrent == mylinklist->tail)
			{
				mylinklist->tail = pFront;
				return;
			}
			pCurrent->next->front = pFront;
			free(pCurrent);
			if (!flagAll)
			{
				break;
			}
			else
			{
				pCurrent = pFront->next;
				continue;
			}
		}
		pCurrent = pCurrent->next;
		pFront = pFront->next;
	}
}

void foreach_TWLinkedList(const TowWayLinkedList linklist, const OUTPUT output)
{
	if (NULL == linklist || NULL == output)
	{
		printf("存在参数为空!\n");
		return;
	}
	ptrLinkList mylinklist = (ptrLinkList)linklist;
	ptrNode pCurrent = mylinklist->head->next;
	while (pCurrent)
	{
		output(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

void clear_TWLinkedList(TowWayLinkedList linklist)
{
	if (NULL == linklist)
	{
		printf("参数为空!\n");
		return;
	}
	ptrLinkList mylinklist = (ptrLinkList)linklist;
	mylinklist->tail = mylinklist->head;
	mylinklist->num = 0;
	ptrNode pCurrent = mylinklist->head->next;
	ptrNode temp = NULL;
	while (pCurrent)
	{
		temp = pCurrent->next;
		free((void *)pCurrent);
		pCurrent = temp;
	}
	mylinklist->head->next = NULL;
}

void destroy_TWLinkedList(TowWayLinkedList linklist)
{
	if (NULL == linklist)
	{
		printf("参数为空!\n");
		return;
	}
	clear_TWLinkedList(linklist);
	free(linklist);
}

int numOfNode_TWLinkedList(const TowWayLinkedList linklist)
{
	if (NULL == linklist)
		return -1;
	ptrLinkList mylinklist = (ptrLinkList)linklist;
	return mylinklist->num;
}

ElemType getTail_TWLinkedList(const TowWayLinkedList linklist)
{
	if (NULL == linklist)
	{
		printf("参数为空!\n");
		return NULL;
	}
	ptrLinkList mylinklist = (ptrLinkList)linklist;
	if (0 == mylinklist->num)
	{
		printf("未插入任何元素!\n");
		return NULL;
	}
	else
		return mylinklist->tail->data;
}
