#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"

//��ʼ��
void InitList(DList plist)
{
	assert(plist != NULL);
	plist->next = NULL;
	plist->prio = NULL;
}

//ͷ�壬Υ��������ɣ���������
bool Insert_head(DList plist,int val)
{
	DNode *p = (DNode *)malloc(sizeof(DNode));
	p->data = val;

	p->next = plist->next;
	plist->next = p;
	p->prio = plist;
	if(p->next != NULL)
	{
		p->next->prio = p;
	}

	return true;
}

//β��
bool Insert_tail(DList plist,int val)
{
	DNode *p = (DNode *)malloc(sizeof(DNode));
	p->data = val;

	DNode *q;
	for(q=plist;q->next!=NULL;q=q->next) ;

	//��p������q����
	p->next = q->next;//p->next = NULL;
	q->next = p;
	p->prio = q;

	return true;
}


//����
DNode* Search(DList plist,int key)
{
	for(DNode *p=plist->next;p!=NULL;p=p->next)
	{
		if(p->data == key)
		{
			return p;
		}
	}

	return NULL;
}

bool Delete(DList plist,int key)
{
	DNode *p = Search(plist,key);
	if(p == NULL)
	{
		return false;
	}

	p->prio->next = p->next;
	if(p->next != NULL)
	{
		p->next->prio = p->prio;
	}
	free(p);

	return true;
}

int GetLength(DList plist)
{
	int count = 0;
	for(DNode *p=plist->next;p!=NULL;p=p->next)
	{
		count++;
	}

	return count;
}

bool IsEmpty(DList plist)
{
	return plist->next == NULL;
}

//�������
void Clear(DList plist)
{
	Destroy(plist);
}

//����˳���
void Destroy(DList plist)
{
	DNode *p;
	while(plist->next != NULL)
	{
		p = plist->next;
		plist->next = p->next;
		//
		free(p);
	}
}

void Show(DList plist)
{
	for(DNode *p=plist->next;p!=NULL;p=p->next)
	{
		printf("%d ",p->data);
	}
	printf("\n");
}

void Reverse(DList plist)
{
	DNode* p = plist->next;
	DNode* q;
	for(DNode* q = plist->next; q != NULL; q = q->next);
	DNode* r = q->prio;
	for(int i = 0; i <GetLength(plist)/2; i++)
	{
		int tmp = p->data;
		p->data = r->data;
		r->data = tmp;
		p = p->next;
		r = r->prio;
	}
}
