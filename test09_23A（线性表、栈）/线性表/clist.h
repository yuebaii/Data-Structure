#pragma once
//��ͷ�ڵ��ѭ������,β�ڵ��nextָ��ͷ�ڵ�

typedef struct CNode 
{
	int data;
	struct CNode *next;
}CNode,*CList;//

//��ʼ��
void InitList(CList plist);

//ͷ�壬Υ��������ɣ���������
bool Insert_head(CList plist,int val);

//β��
bool Insert_tail(CList plist,int val);

//����
CNode* Search(CList plist,int key);

bool Delete(CList plist,int key);

int GetLength(CList plist);

bool IsEmpty(CList plist);

//�������
void Clear(CList plist);

//����˳���
void Destroy(CList plist);

void Show(CList plist);

//todo void Reverse(CList plist);