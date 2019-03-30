#pragma once
//链式队列，队头在头节点这边


typedef struct Node //数据节点
{
	int data; 
	struct Node*next;
}Node;

typedef struct HNode//队头节点，将队头与对尾指针封装到一个结构体内
{
	Node *front; //指向第一个数据节点
	Node *rear;//指向最后一个数据节点（队尾）
}HNode,*LQueue;

void InitQueue(LQueue pq);

bool Push(LQueue pq,int val);

//获取队头值，但不删除
bool GetTop(LQueue pq,int *rtval);

//获取队头的值，且删除
bool Pop(LQueue pq,int *rtval);

bool IsEmpty(LQueue pq);

void Destroy(LQueue pq);