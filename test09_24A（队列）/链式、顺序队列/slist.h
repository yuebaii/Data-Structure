#pragma once
//��̬����
//����˳���ģ���ͷ�ڵ��ѭ������
//0�±���Ϊ��Ч���ı�ͷ��1�±���Ϊ�������ı�ͷ

#define SIZE 10 

typedef struct SNode
{
	int data;//����
	int next; //ָ�룬��һ���ڵ���±�
}SNode,*PSList,SList[SIZE];//SList��SNode������������

void InitSList(PSList ps);

//ͷ��
bool Insert_head(PSList ps,int val); 

bool Delete(PSList ps,int key);

bool IsEmpty(PSList ps);

int Search(PSList ps,int key);

void Show(PSList ps);

void Clear(PSList ps);

