//函数默认行为
#pragma once
#include "LinkList.h"
//该函数默认只初始化拷贝表
#define init_LinkList_Default() init_LinkList(NULL, true)
//该函数默认使用尾插法并且插入到拷贝表中
#define insert_LinkList_Default(data, linklist, sizeElem) insert_LinkList(data, linklist, sizeElem, false, true)
//该函数默认删除拷贝表中第一个指定元素
#define deleteByVal_LinkList_Default(data, linklist, is_equal) deleteByVal_LinkList(data, linklist, false, is_equal, true)
//该函数默认从拷贝表中删除
#define deleteByPos_LinkList_Default(pos, linklist) deleteByPos_LinkList(pos, linklist, true)
//该函数默认从拷贝表中修改
#define changeByPos_LinkLis_Default(pos, linklist, data, sizeElem) changeByPos_LinkList(pos,linklist,data, sizeElem, true)
//该函数默认替换拷贝表中第一个指定元素
#define replace_LinkList_Default(src, dst, linklist, is_equal, sizeElem) replace_LinkList(src, dst,linklist, false,is_equal,sizeElem, true)
//该函数默认对拷贝表排序
#define sort_LinkList_Default(linklist, compare) sort_LinkList(linklist,compare,true)
//该函数默认计算拷贝表中结点个数
#define numOfNode_LinkList_Default(linklist) numOfNode_LinkList(linklist, true)
//该函数默认反转拷贝表中的数据
#define reverse_LinkList_Default(linklist, sizeElem) reverse_LinkList(linklist, sizeElem, true)
//该函数默认从拷贝表中查找
#define findByPos_LinkList_Default(pos, linklist) findByPos_LinkList(pos, linklist, true)
//该函数默认遍历拷贝表
#define foreach_LinkList_Default(linklist, output) foreach_LinkList(linklist, output, true)
//该函数默认清空拷贝表
#define clear_Linklist_Default(linklist) clear_Linklist(linklist, true)
//该函数默认销毁拷贝表
#define destroy_Linklist_Default(linklist) destroy_Linklist(linklist, true, false)