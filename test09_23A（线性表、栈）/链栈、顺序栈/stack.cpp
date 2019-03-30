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

//��ջ
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


//��ȡջ��Ԫ�ص�ֵ������ɾ��
bool GetTop(PStack ps,int *rtval)//O(1)
{
	if(IsEmpty(ps))
	{
		return false;
	}
	*rtval = ps->elem[ps->top - 1];

	return true;
}

//��ȡջ��Ԫ�ص�ֵ����ɾ��
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
