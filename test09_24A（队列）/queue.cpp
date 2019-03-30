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

bool Push(PQueue pq,int val)//只能入SIZE-1个数据
{
	if(IsFull(pq))
	{
		return false;
	}

	pq->elem[pq->rear] = val;

	pq->rear = (pq->rear+1)%SIZE;//环

	return true;
}

//获取队头值，但不删除
bool GetTop(PQueue pq,int *rtval)
{
	if(IsEmpty(pq))
	{
		return false;
	}
	*rtval = pq->elem[pq->front];

	return true;
}

//获取队头的值，且删除
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