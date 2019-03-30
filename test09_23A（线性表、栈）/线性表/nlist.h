#pragma once
//����ͷ�ڵ�ĵ�����

typedef struct NNode
{
	int data;
	struct NNode *next;
}NNode,*NList;


//��ʼ��
void InitList(NList *pplist);

//ͷ�壬Υ��������ɣ���������
bool Insert_head(NList *pplist,int val);

//β��
bool Insert_tail(NList *pplist,int val);

//����
NNode* Search(NList plist,int key);

bool Delete(NList *pplist,int key);

int GetLength(NList plist);

bool IsEmpty(NList plist);

//�������
void Clear(NList *pplist);

//����˳���
void Destroy(NList *pplist);

void Show(NList plist);