#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "LinkList.lib")
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <memory.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

	typedef void * LinkList;
	typedef void * ElemType;
	typedef unsigned int Pos;

	//比较两个数据大小
	//在test.c中给出例子
	typedef bool(*COMPARE)(const ElemType data1, const ElemType data2);
	//比较两个数据是否相同
	//在test.c中给出例子
	typedef bool(*IS_EQUAL)(const ElemType data1, const ElemType data2);
	//打印data
	//在test.c中给出例子
	typedef void(*OUTPUT)(const ElemType data);
	
	//初始化链表
	extern LinkList init_LinkList(void);

	//插入数据
	//参数flagHead决定是否头插法
	extern void insert_LinkList(const ElemType data, LinkList linklist, bool flagHead);
	
	//删除指定值
	//若存在多个指定值，参数flagContinue决定是否继续删除该值
	extern void deleteByVal_LinkList(const ElemType data, LinkList linklist, bool flagContinue, IS_EQUAL is_equal);
	
	//删除指定位置上的值
	//pos从0开始
	extern void deleteByPos_LinkList(Pos pos, LinkList linklist);
	
	//修改指定位置上的数据
	//pos从0开始
	//data为新数据
	extern void changeByPos_LinkList(Pos pos, LinkList linklist, const ElemType data);
	
	//替换原始数据
	//参数src为原始数据, dst为新数据
	//当原始数据不止一个时flagAll决定是否全部替换
	extern void replace_LinkList(const ElemType src, const ElemType dst, LinkList linklist, bool flagAll, IS_EQUAL is_equal);
	
	//对数据进行排序
	extern void sort_LinkList(LinkList linklist, COMPARE compare);
	
	//计算链表结点个数
	//若参数为空
	//则返回-1
	extern int numOfNode_LinkList(LinkList linklist);
	
	//反转数据顺序
	extern void reverse_LinkList(LinkList linklist);

	//查找指定位置的结点数据
	//pos从0开始
	extern ElemType findByPos_LinkList(Pos pos, const LinkList linklist);
	
	//遍历链表
	extern void foreach_LinkList(const LinkList linklist, OUTPUT output);
	
	//清空链表
	extern void clear_Linklist(LinkList linklist);
	
	//销毁链表
	extern void destroy_Linklist(LinkList linklist);

#ifdef __cplusplus
}
#endif