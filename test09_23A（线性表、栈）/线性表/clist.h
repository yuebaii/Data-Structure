#pragma once
//带头节点的循环链表,尾节点的next指向头节点

typedef struct CNode 
{
	int data;
	struct CNode *next;
}CNode,*CList;//

//初始化
void InitList(CList plist);

//头插，违背生活规律，尽量少用
bool Insert_head(CList plist,int val);

//尾插
bool Insert_tail(CList plist,int val);

//查找
CNode* Search(CList plist,int key);

bool Delete(CList plist,int key);

int GetLength(CList plist);

bool IsEmpty(CList plist);

//清空数据
void Clear(CList plist);

//销毁顺序表
void Destroy(CList plist);

void Show(CList plist);

//todo void Reverse(CList plist);