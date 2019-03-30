#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "clist.h"

//��ʼ��
void InitList(CList plist)
{
	assert(plist !=NULL);
	if(plist== NULL)
	{
		return ;
	}

	plist->next = plist;
}

//ͷ�壬Υ��������ɣ��������ã��� 
bool Insert_head(CList plist,int val)
{
	CNode *p = (CNode *)malloc(sizeof(CNode));
	p->data = val;
	
	p->next = plist->next;
	plist->next = p;

	return true;
}

//β��
bool Insert_tail(CList plist,int val)
{
	CNode *p = (CNode *)malloc(sizeof(CNode ));
	p->data = val;

	CNode *q;
	for(q=plist;q->next!=plist;q=q->next) ;

	p->next = q->next;//p->next = plist;
	q->next = p;

	return true;
}

//����
CNode* Search(CList plist,int key)
{
	for(CNode *p=plist->next;p!=plist;p=p->next)
	{
		if(p->data == key)
		{
			return p;
		}
	}
	return NULL;
}

bool Delete(CList plist,int key)
{
	CNode *p;
	for(p=plist;p->next!=plist;p=p->next)
	{
		if(p->next->data == key)
		{
			break;
		}
	}
	if(p->next == plist)
	{
		return false;
	}

	CNode *q = p->next;
	p->next = q->next;
	free(q);

	return true;
}

int GetLength(CList plist)
{
	int count = 0;
	for(CNode *p=plist->next;p!=plist;p=p->next)
	{
		count++;
	}

	return count;
}

bool IsEmpty(CList plist)
{
	return plist->next == plist;
}

//�������
void Clear(CList plist)
{
	Destroy(plist);
}

//����˳���
void Destroy(CList plist)
{
	CNode *p;
	while(plist->next != plist)
	{
		p = plist->next;
		plist->next = p->next;
		free(p);
	}
}

void Show(CList plist)
{
	for(CNode *p=plist->next;p!=plist;p=p->next)
	{
		printf("%d ",p->data);
	}
	printf("\n");
}

void Reverse(CList plist)
{	
	if(plist==NULL || plist->next==plist || plist->next->next==plist)
	{
		return;
	}

	CList p = plist->next;
	plist->next = plist;

	while(p != plist)
	{
		CList q = p->next;
		p->next = plist->next;
		plist->next = p;
		p = q;
	}
}
