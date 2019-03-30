#pragma once
//链式栈，利用带头节点的单链表实现，栈顶在表头

typedef struct SNode
{
	int data;
	struct SNode *next;
	//链式栈的栈顶在表头，不需要额外添加栈顶指针
}SNode,*PStack;

void InitStack(PStack ps);

//入栈
bool Push(PStack ps,int val);

bool IsEmpty(PStack ps);

//获取栈顶元素的值，但不删除
bool GetTop(PStack ps,int *rtval);

//获取栈顶元素的值，且删除
bool Pop(PStack ps,int *rtval);

void Clear(PStack ps);

void Destroy(PStack ps);