#pragma once
//顺序队列，设计呈环形，主要为了将出队的时间复杂度从O(n)变为O(1)
//尾到头的一个格子不使用，是为了解决队空和队满判断冲突的问题

#define SIZE 10 //只能存放SIZE-1个数据

typedef struct Queue
{
	int elem[SIZE];
	int front;//队头指针，队中第一个元素（队头）的下标
	int rear;//队尾指针,队尾的后面一个格子的下标,当前可以存放数据的下标！
}Queue,*PQueue;

void InitQueue(PQueue pq);

bool Push(PQueue pq,int val);

//获取队头值，但不删除
bool GetTop(PQueue pq,int *rtval);

//获取队头的值，且删除
bool Pop(PQueue pq,int *rtval);

bool IsEmpty(PQueue qp);

void Destroy(PQueue pq);