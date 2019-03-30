#pragma once
//不带头节点的单链表

typedef struct NNode
{
	int data;
	struct NNode *next;
}NNode,*NList;


//初始化
void InitList(NList *pplist);

//头插，违背生活规律，尽量少用
bool Insert_head(NList *pplist,int val);

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

void Show(NList plist);