#pragma once
//��ͷ�ڵ��˫������

typedef struct DNode
{
	int data;
	struct DNode *prio;//ǰ��ָ��
	struct DNode *next;//���ָ��
}DNode,*DList;

//��ʼ��
void InitList(DList plist);

//ͷ�壬Υ��������ɣ���������
bool Insert_head(DList plist,int val);//�����ص�

//β��
bool Insert_tail(DList plist,int val);//�����ص�

//����
DNode* Search(DList plist,int key);

bool Delete(DList plist,int key);//�����ص�

int GetLength(DList plist);

bool IsEmpty(DList plist);

//�������
void Clear(DList plist);

//����˳���
void Destroy(DList plist);

void Show(DList plist);

//todo void Reverse(DList plist);