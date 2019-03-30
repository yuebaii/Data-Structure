#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lqueue.h"

void InitQueue(LQueue pq)
{
	assert(pq != NULL);
	pq->front = NULL;
	pq->rear = NULL;
}

//尾插
bool Push(LQueue pq,int val)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = val;
	p->next = NULL;

	if(pq->rear == NULL)//第一次入数据
	{
		pq->front = p;
		pq->rear = p;
	}
	else
	{
		pq->rear->next = p;
		pq->rear = p;
	}

	return true;
}

//获取队头值，但不删除
bool GetTop(LQueue pq,int *rtval)
{
	if(IsEmpty(pq))
	{
		return false;
	}

	*rtval = pq->front->data;

	return true;
}

//获取队头的值，且删除,删除第一个数据节点
bool Pop(LQueue pq,int *rtval)
{
	if(IsEmpty(pq))
	{
		return false;
	}
	Node *p = pq->front;

	*rtval = p->data;

	pq->front = p->next;

	free(p);

	if(pq->front == NULL) //删除了最后一个节点
	{
		pq->rear = NULL;
	}

	return true;
}

bool IsEmpty(LQueue pq)
{
	return pq->front == NULL;
}

void Destroy(LQueue pq)
{
	for(Node* p = pq->front->next; p != NULL; p = p->next)
	{
		pq->front = p->next;
		free(p);
	}
	pq->rear = NULL;
}
