#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "nlist.h"

//��ʼ��
void InitList(NList *pplist)
{
	assert(pplist != NULL);

	*pplist = NULL;
}

bool Insert_head(NList *pplist,int val)
{
	NNode *p = (NNode *)malloc(sizeof(NNode));
	p->data = val;
	//p->next = *pplist;
	//*pplist = p;
	NList plist = *pplist;//bug
	p->next = plist;
	plist = p;//error
	//*pplist = p;

	return true;
}

//β��
bool Insert_tail(NList *pplist,int val);

//����
NNode* Search(NList plist,int key);

bool Delete(NList *pplist,int key);

int GetLength(NList plist);

bool IsEmpty(NList plist);

//�������
void Clear(NList *pplist);

//����˳���
void Destroy(NList *pplist);

void Show(NList plist)
{
	for(NNode *p=plist;p!=NULL;p=p->next)
	{
		printf("%d ",p->data);
	}
	printf("\n");
}