#pragma once
//��ʽ���У���ͷ��ͷ�ڵ����


typedef struct Node //���ݽڵ�
{
	int data; 
	struct Node*next;
}Node;

typedef struct HNode//��ͷ�ڵ㣬����ͷ���βָ���װ��һ���ṹ����
{
	Node *front; //ָ���һ�����ݽڵ�
	Node *rear;//ָ�����һ�����ݽڵ㣨��β��
}HNode,*LQueue;

void InitQueue(LQueue pq);

bool Push(LQueue pq,int val);

//��ȡ��ͷֵ������ɾ��
bool GetTop(LQueue pq,int *rtval);

//��ȡ��ͷ��ֵ����ɾ��
bool Pop(LQueue pq,int *rtval);

bool IsEmpty(LQueue pq);

void Destroy(LQueue pq);