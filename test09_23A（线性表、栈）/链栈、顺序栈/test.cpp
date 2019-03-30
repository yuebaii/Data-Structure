#include <stdio.h>
#include <ctype.h>
#include "lstack.h"
#include "prio.h"
#include "list.h"
//pa,pb ��С�������򣬹鲢�ɴӴ�С�����pc
//void Merge(List pa,List pb,List pc)
//{
//	Node *p = pa->next;
//	Node *q = pb->next;
//	while(p!=NULL && q!=NULL)
//	{
//		if(p->data < q->data)
//		{
//			Insert_head(pc,p->data);
//			p = p->next;
//		}
//		else
//		{
//			Insert_head(pc,q->data);
//			q = q->next;
//		}
//	}
//
//	while(p != NULL)
//	{
//		Insert_head(pc,p->data);
//		p = p->next;
//	}
//	while(q != NULL)
//	{
//		Insert_head(pc,q->data);
//		q = q->next;
//	}
//}
//
//int main()
//{
//	Node heada;
//	Node headb;
//	Node headc;
//	InitList(&heada);
//	InitList(&headb);
//	InitList(&headc);
//	int i;
//	for(i=0;i<10;i++)
//	{
//		Insert_tail(&heada,i);//0,1,2...9 
//	}
//	for(i=5;i<15;i++)
//	{
//		Insert_tail(&headb,i);//5,6,...14
//	}
//	Merge(&heada,&headb,&headc);
//	Show(&headc);//14,13 
//	return 0;
//}

//#if 0
//todo �ж������Ƿ�Ϊ����  
//todo �ж������Ƿ�Ϊ����  
//"3+4*"
//void Huiwen(int d)
//{
//	int c = 0;
//	int a = d;
//	while(a > 0)
//	{
//		int b = a%10;
//		a /= 10;
//		c = b + c*10;
//	}
//	if(d == c) printf("%d�ǻ������֣�", c);
//	else  printf("%d���ǻ������֣�", c); 
//} 
//
//bool Hwen(List plist, List qlist)
//{
//	for(SNode* p = plist->next, SNode* q = qlist->next; p != NULL; p = p->next, q = q->next)
//	{
//		if(p->data != q->data)
//		{
//			return false;
//		}
//	}
//	
//	return true;
//}
//int main()
//{
//	SNode s;
//	InitStack(&s);
//	SNode t;
//	InitStack(&t);
//	for(int i=0;i<15;i++)
//	{
//		Push(&s,i);
//	}
//	int tmp;
//	while(!IsEmpty(&s))
//	{
//		Pop(&s,&tmp);
//		Push(&t, &tmp);
//	}
//    Hwen(&s, &t);
//	return 0;
//}


int Priority(char opera, bool InStack)
{
	int prio = OPERA_PRIO_ERR;
	if(InStack)
	{
		switch(opera)
		{
		case '+':
			prio  = OPERA_PRIO_PLUS_IN;
			break;
		case '-':
			prio  = OPERA_PRIO_MINUS_IN;
			break;
		case '*':
			prio  = OPERA_PRIO_MULTIPLY_IN;
			break;
		case '/':
			prio  = OPERA_PRIO_DIVISION_IN;
			break;
		case '(':
			prio  = OPERA_PRIO_LEFT_BRACKETS_IN;
			break;
		case '[':
			prio  = OPERA_PRIO_LEFT_MIDKUOHAO_IN;
			break;
		case '{':
			prio  = OPERA_PRIO_LEFT_BIGKUOHAO_IN;
			break;
		default:
			prio = OPERA_PRIO_ERR;
			break;
		}
	}
	else
	{
		switch(opera)
		{
		case '+':
			prio  = OPERA_PRIO_PLUS_OUT;
			break;
		case '-':
			prio  = OPERA_PRIO_MINUS_OUT;
			break;
		case '*':
			prio  = OPERA_PRIO_MULTIPLY_OUT;
			break;
		case '/':
			prio  = OPERA_PRIO_DIVISION_OUT;
			break;
		case '(':
			prio  = OPERA_PRIO_LEFT_BRACKETS_OUT;
			break;
		case ')':
			prio  = OPERA_PRIO_RIGHT_BRACKETS_OUT;
			break;
		case '[':
			prio  = OPERA_PRIO_LEFT_MIDKUOHAO_OUT;
			break;
		case ']':
			prio  = OPERA_PRIO_RIGHT_MIDKUOHAO_OUT;
			break;
		case '{':
			prio  = OPERA_PRIO_LEFT_BIGKUOHAO_OUT;
			break;
		case '}':
			prio  = OPERA_PRIO_RIGHT_BIGKUOHAO_OUT;
			break;
		default:
			prio = OPERA_PRIO_ERR;
			break;
		}
	}
	return prio;
}

void MidtoLast(char *last,const char *mid)
{
	SNode s;
	InitStack(&s);
	int i = 0;//last�±�
	int prioIn;//ջ�ڷ������ȼ�
	int prioOut;//ջ��������ȼ�
	int tmp;

	while(*mid != '\0')
	{
		if(isdigit(*mid))
		{
			last[i++] = *mid++;
		}
		else //�����
		{
			if(IsEmpty(&s))//ջ��
			{
				Push(&s,*mid++);
			}
			else //ջ���գ��Ƚ����ȼ��� �������ȼ��ߵ�����ջ���߳�ջ������
			{
				GetTop(&s,&tmp);
				prioIn = Priority(tmp,true);
				prioOut =  Priority(*mid,false);

				if(prioOut < prioIn)//ջ�����ȼ��ߣ���ջ
				{
					Push(&s,*mid++);
				}
				else if(prioOut > prioIn)//ջ�����ȼ��ͣ���ջ
				{
					Pop(&s,&tmp);
					last[i++] = (char)tmp;
				}
				else//���ȼ���ȣ�����ƥ��,ֱ��ɾ��
				{
					mid++;
					Pop(&s,&tmp);
				}
			}
		}
	}

	while(!IsEmpty(&s))
	{
		Pop(&s,&tmp);
		last[i++] = (char)tmp;
	}

	last[i] = '\0';
}

int main()
{
	char *mid = "435*+23*-";
	char last[100];
	MidtoLast(last,mid);
	printf("%s\n%s\n",mid,last);

	return 0;
}
//#endif
/*
int main()
{
	SNode s;
	InitStack(&s);
	for(int i=0;i<15;i++)
	{
		Push(&s,i);
	}
	int tmp;
	while(!IsEmpty(&s))
	{
		Pop(&s,&tmp);
		printf("%d\n",tmp);
	}

	return 0;
}
*/

/*
#include <stack>//ʹ��C++��STL��
#include <iostream>
using namespace std;

int main()
{
	stack<int> s;
	for(int i=0;i<15;i++)
	{
		s.push(i);
	}

	while(!s.empty())
	{
		printf("%d\n",s.top());
		s.pop();
	}
	return 0;
}
*/
/*
#include "stack.h"

int main()
{
	Stack s;
	InitStack(&s);

	for(int i=0;i<15;i++)
	{
		Push(&s,i);
	}

	int tmp;
	while(!IsEmpty(&s))
	{
		Pop(&s,&tmp);
		printf("%d\n",tmp);
	}

	return 0;
}
*/