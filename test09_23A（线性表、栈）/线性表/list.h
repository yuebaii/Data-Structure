#pragma once
//带头节点的单链表,以NULL结尾

typedef struct Node
{
    int data;
    struct Node*next;
}Node,*List;//List == Node*


//初始化
void InitList(List plist);

//头插，违背生活规律，尽量少用
bool Insert_head(List plist,int val);

//尾插
bool Insert_tail(List plist,int val);

//查找
Node* Search(List plist,int key);

bool Delete(List plist,int key);

int GetLength(List plist);

bool IsEmpty(List plist);

//清空数据
void Clear(List plist);

//销毁顺序表
void Destroy(List plist);

void Show(List plist);

 void Reverse(List plist);//经常考试
