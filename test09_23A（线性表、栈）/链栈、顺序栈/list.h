#pragma once
//��ͷ�ڵ�ĵ�����,��NULL��β

typedef struct Node
{
    int data;
    struct Node*next;
}Node,*List;//List == Node*


//��ʼ��
void InitList(List plist);

//ͷ�壬Υ��������ɣ���������
bool Insert_head(List plist,int val);

//β��
bool Insert_tail(List plist,int val);

//����
Node* Search(List plist,int key);

bool Delete(List plist,int key);

int GetLength(List plist);

bool IsEmpty(List plist);

//�������
void Clear(List plist);

//����˳���
void Destroy(List plist);

void Show(List plist);

 void Reverse(List plist);//��������
