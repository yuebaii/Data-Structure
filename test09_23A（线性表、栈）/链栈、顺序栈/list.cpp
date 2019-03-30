#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "list.h"

//��ʼ��
void InitList(List plist)
{
	assert(plist != NULL);
	if(plist==NULL)
	{
		return ;
	}

	plist->next = NULL;
}

//ͷ��
bool Insert_head(List plist,int val)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = val;
	p->next = plist->next;
	plist->next = p;
	//Node newnode;//1
	//newnode.data = val;//2
	//newnode.next = plist->next;//4
	//plist->next = &newnode;//3
	
	return true;
}

//β��
bool Insert_tail(List plist,int val)
{
	Node *q;
	for(q=plist;q->next!=NULL;q=q->next);
	//β�ڵ�q���Ϊq->next==NULL
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = val;
	//��p����q�ĺ���
	p->next = q->next;//p->next = NULL;
	q->next = p;

	return true;
}

//����
Node* Search(List plist,int key)
{
	for(Node *p=plist->next;p!=NULL;p=p->next)
	{
		if(p->data == key)
		{
			return p;
		}
	}

	return NULL;
}

static Node *SearchPri(List plist,int key)
{
	for(Node *p=plist;p->next!=NULL;p=p->next)
	{
		if(p->next->data == key)
		{
			return p;
		}
	}
	return NULL;
}

bool Delete(List plist,int key)
{
	Node *p = SearchPri(plist,key);
	if(p == NULL)
	{
		return false;
	}

	Node *q = p->next;
	p->next = q->next;
	free(q);
	/*free(p->next);
	p->next = p->next->next;*/
	

	return true;
}

int GetLength(List plist)
{
	int count = 0;
	for(Node *p=plist->next;p!=NULL;p=p->next)
	{
		count++;
	}

	return count;
}

bool IsEmpty(List plist)
{
	return plist->next == NULL;
}

//�������
void Clear(List plist)
{
	Destroy(plist);
}

//����˳���
void Destroy(List plist)
{
	Node *p;
	while(plist->next != NULL)//�����Ŷ���
	{
		p = plist->next;
		plist->next = p->next;
		free(p);
	}

	/*
	Node *p = plist->next;//
	//Node *q = p->next;//bug
	Node *q;

	plist->next = NULL;

	while(p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	*/
}

void Show(List plist)
{
	for(Node *p=plist->next;p!=NULL;p=p->next)
	{
		printf("%d ",p->data);
	}
	printf("\n");
}

//todo
void Reverse(List plist)//��������
{
	if(plist==NULL || plist->next==NULL || 
	   plist->next->next==NULL)
	{
		return ;
	}

	Node *p = plist->next;
	Node *q;
	plist->next = NULL;

	while(p != NULL)
	{
		q = p->next;
		p->next = plist->next;
		plist->next = p;
		p = q;
	}

	/*
	Node *p = plist->next;
	Node *q = p->next;
	Node *s;

	p->next = NULL;// 1
	while(q != NULL)
	{
		s = q->next;
		q->next = p;
		p = q;
		q = s;
	}

	plist->next = p;
	*/
}