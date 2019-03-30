#pragma once
//利用带头节点的单链表维护一元多项式
//链表中的数据为多项式的系数和指数
//使用链表维护的原因：多项式合并是，插入和删除操作较多

typedef struct Term
{
	double cofe;//系数
	int expn;//指数
}Term;

typedef struct PNode
{
	Term data;//
	struct PNode *next;
}PNode,*Poly;

void InitPoly(Poly po);

//指数从小到大有序
void Insert(Poly po,double cofe,int expn);

//po1 += po2
void Add(Poly po1,Poly po2);

//po1 -= po2;
void Sub(Poly po1,Poly po2);

//po1 *= po2;
void Multi(Poly po1,Poly po2);

void Show(Poly po1);

void Destroy(Poly po);