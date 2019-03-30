#pragma once
//���ô�ͷ�ڵ�ĵ�����ά��һԪ����ʽ
//�����е�����Ϊ����ʽ��ϵ����ָ��
//ʹ������ά����ԭ�򣺶���ʽ�ϲ��ǣ������ɾ�������϶�

typedef struct Term
{
	double cofe;//ϵ��
	int expn;//ָ��
}Term;

typedef struct PNode
{
	Term data;//
	struct PNode *next;
}PNode,*Poly;

void InitPoly(Poly po);

//ָ����С��������
void Insert(Poly po,double cofe,int expn);

//po1 += po2
void Add(Poly po1,Poly po2);

//po1 -= po2;
void Sub(Poly po1,Poly po2);

//po1 *= po2;
void Multi(Poly po1,Poly po2);

void Show(Poly po1);

void Destroy(Poly po);