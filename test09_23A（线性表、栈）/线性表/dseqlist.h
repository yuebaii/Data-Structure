#pragma once
//������˳���

#define INITSIZE 10

typedef struct DSeqList
{
	int *elem;//ָ������������ĵ�ַ
	int length;//��Ч���ݸ���
	int listsize;//�ܸ�����
}DSeqList,*PDSeqList;


//��ʼ��
void InitSeqList(PDSeqList ps);

//����
bool Insert(PDSeqList ps,int pos,int val);

//����,�ɹ��򷵻��±꣬ʧ�ܷ���-1
int Search(PDSeqList ps,int key);

//ɾ��
bool DeletePos(PDSeqList ps,int pos);

bool DeleteVal(PDSeqList ps,int key);

int GetLength(PDSeqList ps);

bool IsEmpty(PDSeqList ps);

//�������
void Clear(PDSeqList ps);

//����˳���
void Destroy(PDSeqList ps);

void Show(PDSeqList ps);

//rtval�������
bool GetElem(PDSeqList ps,int pos,int *rtval);

//todo,capacity,at,pop_back,push_back
int Capacity(PDSeqList ps);

bool At(PDSeqList ps,int pos,int *rtval);

bool Pop_back(PDSeqList ps);

bool Push_back(PDSeqList ps,int val);


