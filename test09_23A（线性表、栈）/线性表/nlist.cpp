#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "nlist.h"

//初始化
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

//尾插
bool Insert_tail(NList *pplist,int val);

//查找
NNode* Search(NList plist,int key);

bool Delete(NList *pplist,int key);

int GetLength(NList plist);

bool IsEmpty(NList plist);

//清空数据
void Clear(NList *pplist);

//销毁顺序表
void Destroy(NList *pplist);

void Show(NList plist)
{
	for(NNode *p=plist;p!=NULL;p=p->next)
	{
		printf("%d ",p->data);
	}
	printf("\n");
}