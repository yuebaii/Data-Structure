#pragma once
//˳����У���Ƴʻ��Σ���ҪΪ�˽����ӵ�ʱ�临�Ӷȴ�O(n)��ΪO(1)
//β��ͷ��һ�����Ӳ�ʹ�ã���Ϊ�˽���ӿպͶ����жϳ�ͻ������

#define SIZE 10 //ֻ�ܴ��SIZE-1������

typedef struct Queue
{
	int elem[SIZE];
	int front;//��ͷָ�룬���е�һ��Ԫ�أ���ͷ�����±�
	int rear;//��βָ��,��β�ĺ���һ�����ӵ��±�,��ǰ���Դ�����ݵ��±꣡
}Queue,*PQueue;

void InitQueue(PQueue pq);

bool Push(PQueue pq,int val);

//��ȡ��ͷֵ������ɾ��
bool GetTop(PQueue pq,int *rtval);

//��ȡ��ͷ��ֵ����ɾ��
bool Pop(PQueue pq,int *rtval);

bool IsEmpty(PQueue qp);

void Destroy(PQueue pq);