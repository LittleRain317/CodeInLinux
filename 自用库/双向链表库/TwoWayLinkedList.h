#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#include <Windows.h>

#ifdef __cplusplus
extern "C"
{
#endif
	
	typedef void * TowWayLinkedList;
	typedef void * ElemType;
	typedef unsigned Pos;
	typedef bool(*COMPARE)(const ElemType data1, const ElemType data2);
	typedef bool(*ISEQUAL)(const ElemType data1, const ElemType data2);
	typedef void(*OUTPUT)(const ElemType data);


	//初始化函数
	TowWayLinkedList init_TWLinkedList(void);
	
	//插入元素
	//参数flagHead决定是否进行头插法
	void insert_TWLinkedList(const ElemType data, TowWayLinkedList linklist, bool flagHead);

	//删除指定位置的元素
	void deleteByPos_TWLinkedList(Pos pos, TowWayLinkedList linklist);

	//删除元素
	//参数flagAll决定当存在多个指定元素时是否删除该全部元素
	//调用该函数需传递相等函数的函数名作为实参
	void deleteByVal_TWLinkedList(const ElemType data, TowWayLinkedList linklist, const ISEQUAL isEqual, bool flagAll);

	//替换指定位置上的元素
	void replace_TWLinkedList(Pos pos, const ElemType data, TowWayLinkedList linklist);

	//修改元素
	//参数flagAll决定当存在多个指定元素时是否全部替换
	//参数src为待修改数据,参数dst为新数据
	//调用该函数需传递相等函数的函数名作为实参
	void change_TWLinkedList(const ElemType dst, const ElemType src, TowWayLinkedList linklist, const ISEQUAL isEqual, bool flagAll);

	//排序
	//调用该函数需传递比较函数的函数名作为实参
	void sort_TWLinkedList(TowWayLinkedList linklist, const COMPARE compare);

	//遍历
	void foreach_TWLinkedList(const TowWayLinkedList linklist, const OUTPUT output);

	//查找指定位置上的元素
	ElemType findByPos_TWLinkedList(Pos pos, const TowWayLinkedList linklist);

	//查找指定元素所在位置
	//若指定元素存在多个，则返回第一个的位置
	Pos findByVal_TWLinkedList(const ElemType data, const TowWayLinkedList linklist, const ISEQUAL isEqual);
	//清空(保留头节点)
	void clear_TWLinkedList(TowWayLinkedList linklist);

	//销毁
	void destroy_TWLinkedList(TowWayLinkedList linklist);

	//获得节点数目
	//如果参数为空则返回-1
	int numOfNode_TWLinkedList(const TowWayLinkedList linklist);

	//获取尾部数据
	//如果参数为空则返回空
	//如果链表未插入任何元素也将返回空
	ElemType getTail_TWLinkedList(const TowWayLinkedList linklist);

#ifdef __cplusplus
}
#endif