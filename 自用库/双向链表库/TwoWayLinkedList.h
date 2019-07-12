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


	//��ʼ������
	TowWayLinkedList init_TWLinkedList(void);
	
	//����Ԫ��
	//����flagHead�����Ƿ����ͷ�巨
	void insert_TWLinkedList(const ElemType data, TowWayLinkedList linklist, bool flagHead);

	//ɾ��ָ��λ�õ�Ԫ��
	void deleteByPos_TWLinkedList(Pos pos, TowWayLinkedList linklist);

	//ɾ��Ԫ��
	//����flagAll���������ڶ��ָ��Ԫ��ʱ�Ƿ�ɾ����ȫ��Ԫ��
	//���øú����贫����Ⱥ����ĺ�������Ϊʵ��
	void deleteByVal_TWLinkedList(const ElemType data, TowWayLinkedList linklist, const ISEQUAL isEqual, bool flagAll);

	//�滻ָ��λ���ϵ�Ԫ��
	void replace_TWLinkedList(Pos pos, const ElemType data, TowWayLinkedList linklist);

	//�޸�Ԫ��
	//����flagAll���������ڶ��ָ��Ԫ��ʱ�Ƿ�ȫ���滻
	//����srcΪ���޸�����,����dstΪ������
	//���øú����贫����Ⱥ����ĺ�������Ϊʵ��
	void change_TWLinkedList(const ElemType dst, const ElemType src, TowWayLinkedList linklist, const ISEQUAL isEqual, bool flagAll);

	//����
	//���øú����贫�ݱȽϺ����ĺ�������Ϊʵ��
	void sort_TWLinkedList(TowWayLinkedList linklist, const COMPARE compare);

	//����
	void foreach_TWLinkedList(const TowWayLinkedList linklist, const OUTPUT output);

	//����ָ��λ���ϵ�Ԫ��
	ElemType findByPos_TWLinkedList(Pos pos, const TowWayLinkedList linklist);

	//����ָ��Ԫ������λ��
	//��ָ��Ԫ�ش��ڶ�����򷵻ص�һ����λ��
	Pos findByVal_TWLinkedList(const ElemType data, const TowWayLinkedList linklist, const ISEQUAL isEqual);
	//���(����ͷ�ڵ�)
	void clear_TWLinkedList(TowWayLinkedList linklist);

	//����
	void destroy_TWLinkedList(TowWayLinkedList linklist);

	//��ýڵ���Ŀ
	//�������Ϊ���򷵻�-1
	int numOfNode_TWLinkedList(const TowWayLinkedList linklist);

	//��ȡβ������
	//�������Ϊ���򷵻ؿ�
	//�������δ�����κ�Ԫ��Ҳ�����ؿ�
	ElemType getTail_TWLinkedList(const TowWayLinkedList linklist);

#ifdef __cplusplus
}
#endif