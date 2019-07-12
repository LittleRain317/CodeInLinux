#pragma once

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <Windows.h>

#ifdef __cplusplus
extern "C"
{
#endif

	typedef void * Queue;
	typedef void * ElemType;

	//初始化
	Queue init_Queue(void);
	
	//进队
	void inqueue_Queue(Queue queue, const ElemType data);
	
	//出队
	void dequeue_Queue(Queue queue);

	//获得队头元素
	//若未储存任何元素时将返回空
	ElemType getHead_Queue(const Queue queue);
	
	//获得队尾元素
	//未储存任何元素时将返回空
	ElemType getTail_Queue(const Queue queue);
	
	//获得结点个数
	int numOfNode_Queue(const Queue queue);

	//清空队列
	void clear_Queue(Queue queue);

	//销毁队列
	void destroy_Queue(Queue queue);

#ifdef __cplusplus
}
#endif