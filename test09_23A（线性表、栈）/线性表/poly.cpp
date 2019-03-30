#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "poly.h"

void InitPoly(Poly po)
{
	assert(po != NULL);
	po->next = NULL;
}

static PNode *SearchPri(Poly po,int expn)
{
	PNode *p;
	for(p=po;p->next!=NULL;p=p->next)
	{
		if(p->next->data.expn >= expn)
		{
			//return p;
			break;
		}
	}

	return p;
}

#define EPS 0.0000001

//ָ����С��������
void Insert(Poly po,double cofe,int expn)
{
	PNode *p;
	PNode *q;
	p = SearchPri(po,expn);
	if(p->next!=NULL && p->next->data.expn==expn)//��Ҫ�ϲ�ͬ����
	{
		p->next->data.cofe += cofe;
		//�ж�ϵ���Ƿ�Ϊ0���������ɾ��
		q = p->next;
		if(-EPS<q->data.cofe && q->data.cofe<EPS)
		{
			p->next = q->next;
			free(q);
		}
	}
	else//�����������
	{
		q = (PNode *)malloc(sizeof(PNode));
		q->data.cofe = cofe;
		q->data.expn = expn;
		//��q������p�ĺ���
		q->next = p->next;
		p->next = q;
	}
}

//po1 += po2
void Add(Poly po1,Poly po2);

//po1 -= po2;
void Sub(Poly po1,Poly po2);

//po1 *= po2;
void Multi(Poly po1,Poly po2);

void Show(Poly po1);

void Destroy(Poly po);