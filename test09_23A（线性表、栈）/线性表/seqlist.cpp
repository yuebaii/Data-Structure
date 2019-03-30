#include <stdio.h>
#include <assert.h>
#include "seqlist.h"

//typedef struct SeqList
//{
//	int elem[SIZE];//������ݵ�����
//	int length;//��Ч���ݸ���
//}SeqList,*PSeqList;
//��ʼ��
void InitSeqList(PSeqList ps)
{
	assert(ps != NULL);
	if(ps  == NULL)
	{
		return ;
	}

	ps->length = 0;//û����Ч����
}

static bool IsFull(PSeqList ps)
{
	return ps->length == SIZE;
}

//���룬���ݱ�������
bool Insert(PSeqList ps,int pos,int val)
{
	if(pos<0 || pos>ps->length || IsFull(ps))
	{
		return false;
	}

	for(int i=ps->length-1;i>=pos;i--)//�ƶ�ԭ������
	{
		ps->elem[i+1] = ps->elem[i];
	}

	ps->elem[pos] = val;//����������

	ps->length++;

	return true;
}

//����,�ɹ��򷵻��±꣬ʧ�ܷ���-1
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

//ɾ��
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

//�������
void Clear(PSeqList ps)
{
	ps->length = 0;
}

//����˳���,���ٶ�̬�ڴ�
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