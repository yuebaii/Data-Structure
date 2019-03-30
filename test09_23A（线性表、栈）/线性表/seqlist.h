#pragma once // ��ֹͷ�ļ��ظ�����
//�̶����ȵ�˳�������˳���
#define SIZE 10

typedef struct SeqList
{
	int elem[SIZE];//������ݵ�����
	int length;//��Ч���ݸ���
}SeqList,*PSeqList;//PSeqList == SeqList*

//��ʼ��
void InitSeqList(PSeqList ps);

//����
bool Insert(PSeqList ps,int pos,int val);

//����,�ɹ��򷵻��±꣬ʧ�ܷ���-1
int Search(PSeqList ps,int key);

//ɾ��
bool DeletePos(PSeqList ps,int pos);

bool DeleteVal(PSeqList ps,int key);

int GetLength(PSeqList ps);

bool IsEmpty(PSeqList ps);

//�������
void Clear(PSeqList ps);

//����˳���
void Destroy(PSeqList ps);

void Show(PSeqList ps);

//typedef SeqList *PSeqList;

//#ifndef  A
//#define A
//int a = 10;
//#endif