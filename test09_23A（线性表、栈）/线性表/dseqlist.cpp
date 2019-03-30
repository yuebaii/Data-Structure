#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dseqlist.h"

//typedef struct DSeqList
//{
//	int *elem;//指向存放数据的数组的地址
//	int length;//有效数据个数
//	int listsize;//总格子数
//}DSeqList,*PDSeqList;
//初始化
void InitSeqList(PDSeqList ps)
{
	assert(ps != NULL);
	if(ps == NULL)
	{
		return ;
	}

	ps->elem = (int *)malloc(INITSIZE*sizeof(int));
	ps->length = 0;
	ps->listsize = INITSIZE;
}

static bool IsFull(PDSeqList ps)
{
	return ps->length == ps->listsize;
}

//容量扩大到原来的2倍
static void Inc(PDSeqList ps)
{
	ps->elem = (int *)realloc(ps->elem,ps->listsize*2*sizeof(int));
	ps->listsize *= 2;
	//ps->length;不变
}

//插入
bool Insert(PDSeqList ps,int pos,int val)
{
	if(pos<0 || pos>ps->length)
	{
		return false;
	}
	if(IsFull(ps))
	{
		Inc(ps);
	}

	for(int i=ps->length-1;i>=pos;i--)
	{
		ps->elem[i+1] = ps->elem[i];
	}

	ps->elem[pos] = val;

	ps->length++;

	return true;
}

//查找,成功则返回下标，失败返回-1
int Search(PDSeqList ps,int key)
{
	for(int i=0;i<ps->length;i++)
	{
		if(ps->elem[i] == key)
		{
			return i;
		}
	}
	return -1;
}

//删除
bool DeletePos(PDSeqList ps,int pos)
{
	if(pos<0 || pos>=ps->length)
	{
		return false;
	}

	for(int i=pos;i<ps->length-1;i++)
	{
		ps->elem[i] = ps->elem[i+1];
	}

	ps->length--;

	return true;
}

bool DeleteVal(PDSeqList ps,int key)
{
	int index = Search(ps,key);
	if(index < 0)
	{
		return false;
	}

	return DeletePos(ps,index);
}

int GetLength(PDSeqList ps)//Size
{
	return ps->length;
}

bool IsEmpty(PDSeqList ps)
{
	return ps->length == 0;
}

//清空数据
void Clear(PDSeqList ps)
{
	ps->length = 0;
}

//销毁顺序表
void Destroy(PDSeqList ps)
{
	free(ps->elem);//1
	ps->elem = NULL;//2，健壮性
	ps->length = 0;//3
	ps->listsize = 0;//4
	//ps = NULL;//5，没用
}

void Show(PDSeqList ps)
{
	for(int i=0;i<ps->length;i++)
	{
		printf("%d ",ps->elem[i]);
	}
	printf("\n");
}

bool GetElem(PDSeqList ps,int pos,int *rtval)
{
	if(pos<0 || pos>=ps->length)
	{
		return false;
	}

	*rtval = ps->elem[pos];

	return true;
}

//todo,capacity,at,pop_back,push_back
int Capacity(PDSeqList ps)
{
	return ps->listsize;
}

bool At(PDSeqList ps,int pos,int *rtval);//GetElem

bool Pop_back(PDSeqList ps)
{
	if(IsEmpty(ps))
	{
		return false;
	}
	ps->length--;

	return true;
}

bool Push_back(PDSeqList ps,int val)
{
	return Insert(ps,GetLength(ps),val);
}

void Reverse(PDSeqList ps)
{
	int tmp;

	for(int i=0,j=ps->length-1;i<j;i++,j--)
	{
		tmp = ps->elem[i];
		ps->elem[i] = ps->elem[j];
		ps->elem[j] = tmp;
	}
}
