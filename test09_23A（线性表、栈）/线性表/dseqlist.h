#pragma once
//不定长顺序表

#define INITSIZE 10

typedef struct DSeqList
{
	int *elem;//指向存放数据数组的地址
	int length;//有效数据个数
	int listsize;//总格子数
}DSeqList,*PDSeqList;


//初始化
void InitSeqList(PDSeqList ps);

//插入
bool Insert(PDSeqList ps,int pos,int val);

//查找,成功则返回下标，失败返回-1
int Search(PDSeqList ps,int key);

//删除
bool DeletePos(PDSeqList ps,int pos);

bool DeleteVal(PDSeqList ps,int key);

int GetLength(PDSeqList ps);

bool IsEmpty(PDSeqList ps);

//清空数据
void Clear(PDSeqList ps);

//销毁顺序表
void Destroy(PDSeqList ps);

void Show(PDSeqList ps);

//rtval输出参数
bool GetElem(PDSeqList ps,int pos,int *rtval);

//todo,capacity,at,pop_back,push_back
int Capacity(PDSeqList ps);

bool At(PDSeqList ps,int pos,int *rtval);

bool Pop_back(PDSeqList ps);

bool Push_back(PDSeqList ps,int val);


