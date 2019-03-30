#pragma once
//定长的顺序栈
//todo   将定长的顺序栈改成泛型
//todo   将定长的顺序栈改成不定长

#define SIZE 10

typedef struct Stack
{
	int elem[SIZE];//void *
	int top;//栈顶指针，标记当前可以存放数据的下标
}Stack,*PStack;

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
