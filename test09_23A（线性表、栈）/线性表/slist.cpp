#include <stdio.h>
#include <assert.h>
#include "slist.h"

void InitSList(PSList ps)
{
	assert(ps != NULL);

	for(int i=0;i<SIZE;i++)
	{
		ps[i].next = i+1;
	}

	ps[0].next = 0;
	ps[SIZE-1].next = 1;
}

static bool IsFull(PSList ps)
{
	return ps[1].next == 1;
}

//头插
bool Insert_head(PSList ps,int val)
{
	if(IsFull(ps))
	{
		return false;
	}

	int p = ps[1].next;//找到一个空闲节点

	ps[1].next = ps[p].next;//将p从空闲链删除

	ps[p].data = val;//将数据放到p节点中 

	ps[p].next = ps[0].next; //将p头插进有效链
	ps[0].next = p;

	return true;
}

bool IsEmpty(PSList ps)
{
	return ps[0].next == 0;
}

static int SearhcPri(PSList ps,int key)
{
	for(int p=0;ps[p].next!=0;p=ps[p].next)
	{
		//if(p->next->data == key)
		if(ps[ps[p].next].data == key)
		{
			return p;
		}
	}
	return -1;
}

int Search(PSList ps,int key)
{
	for(int p=ps[0].next;p!=0;p=ps[p].next)
	{
		if(ps[p].data == key)
		{
			return p;
		}
	}
	return -1;
}

bool Delete(PSList ps,int key)//todo
{
	int p = Search(ps, key);
	int q;
	for(int q = p; q != 0; q = ps[q].next)
	{
		ps[q] = ps[q+1];
	}
	ps[q].next = 0;
	return true;
}
void Show(PSList ps)
{
	for(int p=ps[0].next;p!=0;p=ps[p].next)
	{
		printf("%d ",ps[p].data);
	}
	printf("\n");
}

void Clear(PSList ps)
{
	ps[0].next = 0;
}
