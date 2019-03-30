#pragma once
//��ʽջ�����ô�ͷ�ڵ�ĵ�����ʵ�֣�ջ���ڱ�ͷ

typedef struct SNode
{
	int data;
	struct SNode *next;
	//��ʽջ��ջ���ڱ�ͷ������Ҫ�������ջ��ָ��
}SNode,*PStack;

void InitStack(PStack ps);

//��ջ
bool Push(PStack ps,int val);

bool IsEmpty(PStack ps);

//��ȡջ��Ԫ�ص�ֵ������ɾ��
bool GetTop(PStack ps,int *rtval);

//��ȡջ��Ԫ�ص�ֵ����ɾ��
bool Pop(PStack ps,int *rtval);

void Clear(PStack ps);

void Destroy(PStack ps);