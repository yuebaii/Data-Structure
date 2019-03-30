#include <stdio.h>
#include <assert.h>
#include "stack.h"

void InitStack(PStack ps)
{
	assert(ps != NULL);

	ps->top = 0;
}

static bool IsFull(PStack ps)
{
	return ps->top == SIZE;
}

//入栈
bool Push(PStack ps,int val)//O(1)
{
	if(IsFull(ps))
	{
		return false;
	}

	ps->elem[ps->top++] = val;
	
	return true;
}

bool IsEmpty(PStack ps)
{
	return ps->top == 0;
}


//获取栈顶元素的值，但不删除
bool GetTop(PStack ps,int *rtval)//O(1)
{
	if(IsEmpty(ps))
	{
		return false;
	}
	*rtval = ps->elem[ps->top - 1];

	return true;
}

//获取栈顶元素的值，且删除
bool Pop(PStack ps,int *rtval)//O(1)
{
	if(IsEmpty(ps))
	{
		return false;
	}
	*rtval = ps->elem[--ps->top];

	return true;
}

void Clear(PStack ps)
{
	Destroy(ps);
}

void Destroy(PStack ps)
{
	ps->top = 0;
}
