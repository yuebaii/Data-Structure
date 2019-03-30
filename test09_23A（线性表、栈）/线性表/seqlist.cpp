#include <stdio.h>
#include <assert.h>
#include "seqlist.h"

//typedef struct SeqList
//{
//	int elem[SIZE];//存放数据的数组
//	int length;//有效数据个数
//}SeqList,*PSeqList;
//初始化
void InitSeqList(PSeqList ps)
{
	assert(ps != NULL);
	if(ps  == NULL)
	{
		return ;
	}

	ps->length = 0;//没有有效数据
}

static bool IsFull(PSeqList ps)
{
	return ps->length == SIZE;
}

//插入，数据必须连续
bool Insert(PSeqList ps,int pos,int val)
{
	if(pos<0 || pos>ps->length || IsFull(ps))
	{
		return false;
	}

	for(int i=ps->length-1;i>=pos;i--)//移动原有数据
	{
		ps->elem[i+1] = ps->elem[i];
	}

	ps->elem[pos] = val;//插入新数据

	ps->length++;

	return true;
}

//查找,成功则返回下标，失败返回-1
int Search(PSeqList ps,int key)//todo
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
bool DeletePos(PSeqList ps,int pos)
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

bool DeleteVal(PSeqList ps,int key)
{
	int index = Search(ps,key);
	if(index < 0)
	{
		return false;
	}

	return DeletePos(ps,index);
}

int GetLength(PSeqList ps)
{
	return ps->length;
}

bool IsEmpty(PSeqList ps)
{
	return ps->length == 0;
}

//清空数据
void Clear(PSeqList ps)
{
	ps->length = 0;
}

//销毁顺序表,销毁动态内存
void Destroy(PSeqList ps)
{
	Clear(ps);
}

void Show(PSeqList ps)
{
	for(int i=0;i<ps->length;i++)
	{
		printf("%d ",ps->elem[i]);
	}
	printf("\n");
}