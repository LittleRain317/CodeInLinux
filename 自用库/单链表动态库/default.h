//����Ĭ����Ϊ
#pragma once
#include "LinkList.h"
//�ú���Ĭ��ֻ��ʼ��������
#define init_LinkList_Default() init_LinkList(NULL, true)
//�ú���Ĭ��ʹ��β�巨���Ҳ��뵽��������
#define insert_LinkList_Default(data, linklist, sizeElem) insert_LinkList(data, linklist, sizeElem, false, true)
//�ú���Ĭ��ɾ���������е�һ��ָ��Ԫ��
#define deleteByVal_LinkList_Default(data, linklist, is_equal) deleteByVal_LinkList(data, linklist, false, is_equal, true)
//�ú���Ĭ�ϴӿ�������ɾ��
#define deleteByPos_LinkList_Default(pos, linklist) deleteByPos_LinkList(pos, linklist, true)
//�ú���Ĭ�ϴӿ��������޸�
#define changeByPos_LinkLis_Default(pos, linklist, data, sizeElem) changeByPos_LinkList(pos,linklist,data, sizeElem, true)
//�ú���Ĭ���滻�������е�һ��ָ��Ԫ��
#define replace_LinkList_Default(src, dst, linklist, is_equal, sizeElem) replace_LinkList(src, dst,linklist, false,is_equal,sizeElem, true)
//�ú���Ĭ�϶Կ���������
#define sort_LinkList_Default(linklist, compare) sort_LinkList(linklist,compare,true)
//�ú���Ĭ�ϼ��㿽�����н�����
#define numOfNode_LinkList_Default(linklist) numOfNode_LinkList(linklist, true)
//�ú���Ĭ�Ϸ�ת�������е�����
#define reverse_LinkList_Default(linklist, sizeElem) reverse_LinkList(linklist, sizeElem, true)
//�ú���Ĭ�ϴӿ������в���
#define findByPos_LinkList_Default(pos, linklist) findByPos_LinkList(pos, linklist, true)
//�ú���Ĭ�ϱ���������
#define foreach_LinkList_Default(linklist, output) foreach_LinkList(linklist, output, true)
//�ú���Ĭ����տ�����
#define clear_Linklist_Default(linklist) clear_Linklist(linklist, true)
//�ú���Ĭ�����ٿ�����
#define destroy_Linklist_Default(linklist) destroy_Linklist(linklist, true, false)