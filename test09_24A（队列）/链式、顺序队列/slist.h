#pragma once
//静态链表
//利用顺序表模拟带头节点的循环链表
//0下标作为有效链的表头，1下标作为空闲链的表头

#define SIZE 10 

typedef struct SNode
{
	int data;//数据
	int next; //指针，下一个节点的下标
}SNode,*PSList,SList[SIZE];//SList是SNode数组数据类型

void InitSList(PSList ps);

//头插
bool Insert_head(PSList ps,int val); 

bool Delete(PSList ps,int key);

bool IsEmpty(PSList ps);

int Search(PSList ps,int key);

void Show(PSList ps);

void Clear(PSList ps);

