#pragma once

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <Windows.h>

#ifdef __cplusplus
extern "C"
{
#endif

	typedef void * Stack;
	typedef void * ElemType;

	//��ʼ��
	Stack init_Stack(void);
	//��ջ
	void push_Stack(Stack stack, const ElemType data);
	//��ջ
	//��δ�����κ�Ԫ��ʱ�����г�ջ����
	void pop_Stack(Stack stack);
	//���ջ��Ԫ��
	//��δ�����κ�Ԫ��ʱ�������ؿ�
	ElemType getTop_Stack(const Stack stack);
	//���ջԪ�ظ���
	int numOfNode_Stack(const Stack stack);
	//���ջ(����ͷ�ڵ�)
	void clear_Stack(Stack stack);
	//����ջ
	void destroy_Stack(Stack stack);

#ifdef __cplusplus
}
#endif