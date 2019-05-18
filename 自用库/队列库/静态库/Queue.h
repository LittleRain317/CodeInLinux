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

	//��ʼ��
	Queue init_Queue(void);
	
	//����
	void inqueue_Queue(Queue queue, const ElemType data);
	
	//����
	void dequeue_Queue(Queue queue);

	//��ö�ͷԪ��
	//��δ�����κ�Ԫ��ʱ�����ؿ�
	ElemType getHead_Queue(const Queue queue);
	
	//��ö�βԪ��
	//δ�����κ�Ԫ��ʱ�����ؿ�
	ElemType getTail_Queue(const Queue queue);
	
	//��ý�����
	int numOfNode_Queue(const Queue queue);

	//��ն���
	void clear_Queue(Queue queue);

	//���ٶ���
	void destroy_Queue(Queue queue);

#ifdef __cplusplus
}
#endif