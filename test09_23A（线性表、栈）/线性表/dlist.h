#pragma once
//带头节点的双向链表

typedef struct DNode
{
	int data;
	struct DNode *prio;//前驱指针
	struct DNode *next;//后继指针
}DNode,*DList;

//初始化
void InitList(DList plist);

//头插，违背生活规律，尽量少用
bool Insert_head(DList plist,int val);//考试重点

//尾插
bool Insert_tail(DList plist,int val);//考试重点

//查找
DNode* Search(DList plist,int key);

bool Delete(DList plist,int key);//考试重点

int GetLength(DList plist);

bool IsEmpty(DList plist);

//清空数据
void Clear(DList plist);

//销毁顺序表
void Destroy(DList plist);

void Show(DList plist);

//todo void Reverse(DList plist);