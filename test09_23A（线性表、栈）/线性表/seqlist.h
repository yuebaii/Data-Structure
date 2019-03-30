#pragma once // 防止头文件重复引用
//固定长度的顺序表（定长顺序表）
#define SIZE 10

typedef struct SeqList
{
	int elem[SIZE];//存放数据的数组
	int length;//有效数据个数
}SeqList,*PSeqList;//PSeqList == SeqList*

//初始化
void InitSeqList(PSeqList ps);

//插入
bool Insert(PSeqList ps,int pos,int val);

//查找,成功则返回下标，失败返回-1
int Search(PSeqList ps,int key);

//删除
bool DeletePos(PSeqList ps,int pos);

bool DeleteVal(PSeqList ps,int key);

int GetLength(PSeqList ps);

bool IsEmpty(PSeqList ps);

//清空数据
void Clear(PSeqList ps);

//销毁顺序表
void Destroy(PSeqList ps);

void Show(PSeqList ps);

//typedef SeqList *PSeqList;

//#ifndef  A
//#define A
//int a = 10;
//#endif