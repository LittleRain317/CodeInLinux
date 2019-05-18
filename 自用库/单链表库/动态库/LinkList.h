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

	//�Ƚ��������ݴ�С
	//��test.c�и�������
	typedef bool(*COMPARE)(const ElemType data1, const ElemType data2);
	//�Ƚ����������Ƿ���ͬ
	//��test.c�и�������
	typedef bool(*IS_EQUAL)(const ElemType data1, const ElemType data2);
	//��ӡdata
	//��test.c�и�������
	typedef void(*OUTPUT)(const ElemType data);
	
	//��ʼ������
	extern LinkList init_LinkList(void);

	//��������
	//����flagHead�����Ƿ�ͷ�巨
	extern void insert_LinkList(const ElemType data, LinkList linklist, bool flagHead);
	
	//ɾ��ָ��ֵ
	//�����ڶ��ָ��ֵ������flagContinue�����Ƿ����ɾ����ֵ
	extern void deleteByVal_LinkList(const ElemType data, LinkList linklist, bool flagContinue, IS_EQUAL is_equal);
	
	//ɾ��ָ��λ���ϵ�ֵ
	//pos��0��ʼ
	extern void deleteByPos_LinkList(Pos pos, LinkList linklist);
	
	//�޸�ָ��λ���ϵ�����
	//pos��0��ʼ
	//dataΪ������
	extern void changeByPos_LinkList(Pos pos, LinkList linklist, const ElemType data);
	
	//�滻ԭʼ����
	//����srcΪԭʼ����, dstΪ������
	//��ԭʼ���ݲ�ֹһ��ʱflagAll�����Ƿ�ȫ���滻
	extern void replace_LinkList(const ElemType src, const ElemType dst, LinkList linklist, bool flagAll, IS_EQUAL is_equal);
	
	//�����ݽ�������
	extern void sort_LinkList(LinkList linklist, COMPARE compare);
	
	//�������������
	//������Ϊ��
	//�򷵻�-1
	extern int numOfNode_LinkList(LinkList linklist);
	
	//��ת����˳��
	extern void reverse_LinkList(LinkList linklist);

	//����ָ��λ�õĽ������
	//pos��0��ʼ
	extern ElemType findByPos_LinkList(Pos pos, const LinkList linklist);
	
	//��������
	extern void foreach_LinkList(const LinkList linklist, OUTPUT output);
	
	//�������
	extern void clear_Linklist(LinkList linklist);
	
	//��������
	extern void destroy_Linklist(LinkList linklist);

#ifdef __cplusplus
}
#endif