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

	//链表结构
	//拥有两张表
	//1.地址表(将数据的地址串联成链表)
	//2.拷贝表(将数据内容串联成链表)
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
	//参数flagBackup决定是否初始化拷贝表
	//参数linklist用于在已初始化地址表或已初始化拷贝表时需再初始化另一表时填入
	//只初始化地址表或者只初始化拷贝表时linklist应传递NULL进入函数
	extern LinkList init_LinkList(LinkList linklist, bool flagBackup);

	//插入数据
	//参数flagHead决定是否头插法
	//参数flagBackup决定是否插入拷贝表中
	extern void insert_LinkList(const ElemType data, LinkList linklist, size_t sizeElem, bool flagHead, bool flagBackup);

	//删除指定值
	//若存在多个指定值，参数flagContinue决定是否继续删除该值
	//参数flagBackup决定是否从拷贝表中删除数据
	extern void deleteByVal_LinkList(const ElemType data, LinkList linklist, bool flagContinue, IS_EQUAL is_equal, bool flagBackup);

	//删除指定位置上的值
	//pos从0开始
	//参数flagBackup决定是否从拷贝表中删除数据
	extern void deleteByPos_LinkList(Pos pos, LinkList linklist, bool flagBackup);

	//修改指定位置上的数据
	//pos从0开始
	//data为新数据
	//参数flagBackup决定是否从拷贝表中修改数据
	extern void changeByPos_LinkList(Pos pos, LinkList linklist, const ElemType data, size_t sizeElem, bool flagBackup);

	//替换原始数据
	//参数src为原始数据, dst为新数据
	//当原始数据不止一个时flagAll决定是否全部替换
	//参数flagBackup决定是否从拷贝表中替换数据
	extern void replace_LinkList(const ElemType src, const ElemType dst, LinkList linklist, bool flagAll, IS_EQUAL is_equal, size_t sizeElem, bool flagBackup);

	//对数据进行排序
	//参数flagBack决定是否对拷贝表进行排序
	extern void sort_LinkList(LinkList linklist, COMPARE compare, bool flagBackup);

	//计算链表结点个数
	//若参数为空
	//则返回-1
	//参数flagBack决定是否计算拷贝表的结点
	extern int numOfNode_LinkList(LinkList linklist, bool flagBackup);

	//反转数据顺序
	//参数flagBackup决定是否对拷贝表进行数据反转
	extern void reverse_LinkList(LinkList linklist, size_t sizeElem, bool flagBackup);

	//查找指定位置的结点数据
	//pos从0开始
	//参数flagBackup决定是否查找拷贝表中的元素
	extern ElemType findByPos_LinkList(Pos pos, const LinkList linklist, bool flagBackup);

	//遍历链表
	//参数flagBackup决定是否遍历拷贝表
	extern void foreach_LinkList(const LinkList linklist, OUTPUT output, bool flagBackup);

	//清空链表
	//参数flagBackup决定是否清空拷贝表
	extern void clear_Linklist(LinkList linklist, bool flagBackup);

	//销毁链表
	//将销毁地址表和拷贝表
	extern void destroy_Linklist(LinkList linklist, bool flagBackup, bool flagAll);

#ifdef __cplusplus
}
#endif