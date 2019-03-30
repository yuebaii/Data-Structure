#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lstack.h"

void InitStack(PStack ps)
{
	assert(ps != NULL);

	ps->next = NULL;
}

//��ջ,ͷ��
bool Push(PStack ps,int val)//O(1)
{
	SNode *p = (SNode *)malloc(sizeof(SNode ));
	p->data = val;

	p->next = ps->next;
	ps->next = p;

	return true;
}

bool IsEmpty(PStack ps)
{
	return ps->next == NULL;
}

//��ȡջ��Ԫ�ص�ֵ������ɾ��
bool GetTop(PStack ps,int *rtval)//O(1)
{
	if(IsEmpty(ps))
	{
		return false;
	}

	*rtval = ps->next->data;

	return true;
}

//��ȡջ��Ԫ�ص�ֵ����ɾ��
bool Pop(PStack ps,int *rtval)//O(1)
{
	if(IsEmpty(ps))
	{
		return false;
	}
	SNode *p = ps->next;
	ps->next = p->next;

	*rtval = p->data;

	free(p);

	return true;
}

void Clear(PStack ps)
{
	Destroy(ps);
}

void Destroy(PStack ps)
{
	SNode *p;
	while(ps->next != NULL)
	{
		p = ps->next;
		ps->next = p->next;
		free(p);
	}
}