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

	//初始化
	Stack init_Stack(void);
	//进栈
	void push_Stack(Stack stack, const ElemType data);
	//出栈
	//当未储存任何元素时不进行出栈操作
	void pop_Stack(Stack stack);
	//获得栈顶元素
	//当未储存任何元素时函数返回空
	ElemType getTop_Stack(const Stack stack);
	//获得栈元素个数
	int numOfNode_Stack(const Stack stack);
	//清空栈(保留头节点)
	void clear_Stack(Stack stack);
	//销毁栈
	void destroy_Stack(Stack stack);

#ifdef __cplusplus
}
#endif