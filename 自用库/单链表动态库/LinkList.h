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

	//����ṹ
	//ӵ�����ű�
	//1.��ַ��(�����ݵĵ�ַ����������)
	//2.������(���������ݴ���������)
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
	//����flagBackup�����Ƿ��ʼ��������
	//����linklist�������ѳ�ʼ����ַ����ѳ�ʼ��������ʱ���ٳ�ʼ����һ��ʱ����
	//ֻ��ʼ����ַ�����ֻ��ʼ��������ʱlinklistӦ����NULL���뺯��
	extern LinkList init_LinkList(LinkList linklist, bool flagBackup);

	//��������
	//����flagHead�����Ƿ�ͷ�巨
	//����flagBackup�����Ƿ���뿽������
	extern void insert_LinkList(const ElemType data, LinkList linklist, size_t sizeElem, bool flagHead, bool flagBackup);

	//ɾ��ָ��ֵ
	//�����ڶ��ָ��ֵ������flagContinue�����Ƿ����ɾ����ֵ
	//����flagBackup�����Ƿ�ӿ�������ɾ������
	extern void deleteByVal_LinkList(const ElemType data, LinkList linklist, bool flagContinue, IS_EQUAL is_equal, bool flagBackup);

	//ɾ��ָ��λ���ϵ�ֵ
	//pos��0��ʼ
	//����flagBackup�����Ƿ�ӿ�������ɾ������
	extern void deleteByPos_LinkList(Pos pos, LinkList linklist, bool flagBackup);

	//�޸�ָ��λ���ϵ�����
	//pos��0��ʼ
	//dataΪ������
	//����flagBackup�����Ƿ�ӿ��������޸�����
	extern void changeByPos_LinkList(Pos pos, LinkList linklist, const ElemType data, size_t sizeElem, bool flagBackup);

	//�滻ԭʼ����
	//����srcΪԭʼ����, dstΪ������
	//��ԭʼ���ݲ�ֹһ��ʱflagAll�����Ƿ�ȫ���滻
	//����flagBackup�����Ƿ�ӿ��������滻����
	extern void replace_LinkList(const ElemType src, const ElemType dst, LinkList linklist, bool flagAll, IS_EQUAL is_equal, size_t sizeElem, bool flagBackup);

	//�����ݽ�������
	//����flagBack�����Ƿ�Կ������������
	extern void sort_LinkList(LinkList linklist, COMPARE compare, bool flagBackup);

	//�������������
	//������Ϊ��
	//�򷵻�-1
	//����flagBack�����Ƿ���㿽����Ľ��
	extern int numOfNode_LinkList(LinkList linklist, bool flagBackup);

	//��ת����˳��
	//����flagBackup�����Ƿ�Կ�����������ݷ�ת
	extern void reverse_LinkList(LinkList linklist, size_t sizeElem, bool flagBackup);

	//����ָ��λ�õĽ������
	//pos��0��ʼ
	//����flagBackup�����Ƿ���ҿ������е�Ԫ��
	extern ElemType findByPos_LinkList(Pos pos, const LinkList linklist, bool flagBackup);

	//��������
	//����flagBackup�����Ƿ����������
	extern void foreach_LinkList(const LinkList linklist, OUTPUT output, bool flagBackup);

	//�������
	//����flagBackup�����Ƿ���տ�����
	extern void clear_Linklist(LinkList linklist, bool flagBackup);

	//��������
	//�����ٵ�ַ��Ϳ�����
	extern void destroy_Linklist(LinkList linklist, bool flagBackup, bool flagAll);

#ifdef __cplusplus
}
#endif