#pragma once
//������˳��ջ
//todo   ��������˳��ջ�ĳɷ���
//todo   ��������˳��ջ�ĳɲ�����

#define SIZE 10

typedef struct Stack
{
	int elem[SIZE];//void *
	int top;//ջ��ָ�룬��ǵ�ǰ���Դ�����ݵ��±�
}Stack,*PStack;

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
