#include <stdio.h>
#include <assert.h>
#include "queue.h"

void InitQueue(PQueue pq)
{
	assert(pq != NULL);

	pq->front = 0;
	pq->rear = 0;
}

static bool IsFull(PQueue pq)
{
	return (pq->rear+1)%SIZE == pq->front;
}

bool Push(PQueue pq,int val)//ֻ����SIZE-1������
{
	if(IsFull(pq))
	{
		return false;
	}

	pq->elem[pq->rear] = val;

	pq->rear = (pq->rear+1)%SIZE;//��

	return true;
}

//��ȡ��ͷֵ������ɾ��
bool GetTop(PQueue pq,int *rtval)
{
	if(IsEmpty(pq))
	{
		return false;
	}
	*rtval = pq->elem[pq->front];

	return true;
}

//��ȡ��ͷ��ֵ����ɾ��
bool Pop(PQueue pq,int *rtval)
{
	if(IsEmpty(pq))
	{
		return false;
	}

	*rtval = pq->elem[pq->front];
	pq->front = (pq->front+1)%SIZE;

	return true;
}

bool IsEmpty(PQueue pq)
{
	return pq->front == pq->rear;
}

void Destroy(PQueue pq)
{
	pq->front == pq->rear;
}