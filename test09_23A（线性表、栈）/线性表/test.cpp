#include <stdio.h>
#include <stdlib.h>
//#include <vld.h>
//#include "list.h"
#include "nlist.h"
int main()
{
	Node *head;
	//head.data = 1;
	InitList(&head);
	for(int i=0;i<15;i++)
	{
		//Insert_head(&head,i);
		Insert_tail(&head,i);
	}
	//Reverse(&head);
	//Destroy(&head);
	printf("%d\n", GetLength(head));
	Show(head);

	return 0;
}
//#include "dlist.h"

/*
int main()
{
	DNode head;
	InitList(&head);
	for(int i=0;i<15;i++)
	{
		Insert_head(&head,i);
	}
	Show(&head);

	return 0;
}
*/
/*
#include "dseqlist.h"

//从小到大有序
void Insert_x(PDSeqList ps,int x)
{
	int tmp;
	int i;
	for(i=0;i<GetLength(ps);i++)//1 3 5 7    9
	{
		GetElem(ps,i,&tmp);
		if(tmp > x)
		{
			break;
		}
	}

	Insert(ps,i,x);
}

int Cmp_seq(PDSeqList ps1,PDSeqList ps2)
{
	int gap;
	int len1 = GetLength(ps1);
	int len2 = GetLength(ps2);
	int tmp1;
	int tmp2;
	for(int i=0;i<len1 && i<len2;i++)
	{
		GetElem(ps1,i,&tmp1);
		GetElem(ps2,i,&tmp2);
		if((gap=tmp1-tmp2) != 0)
		{
			return gap;
		}
	}

	return len1 - len2;
}

int main()
{
	return 0;
}
*/

/*
#include "clist.h"

int main()
{
	CNode head;
	InitList(&head);

	for(int i=0;i<15;i++)
	{
		Insert_head(&head,i);
	}

	Show(&head);

	return 0;
}
*/
/*
#include "list.h"

int main()
{
	Node head;
	InitList(&head);
	for(int i=0;i<15;i++)
	{
		//Insert_head(&head,i);//
		Insert_tail(&head,i);
	}
	Show(&head);
	//List list;//Node *list;error
	//InitList(list);
	Destroy(&head);
	Destroy(&head);

	return 0;
}
*/

#if 0
//#include "dseqlist.h"

//A = AUB
void Merge(PDSeqList psA,PDSeqList psB)
{
	int tmp;
	int index;
	//for(int i=0;i<psB->length;i++)//1，不好
	for(int i=0;i<GetLength(psB);i++)//2
	{//团队思想
		//tmp = psB->elem[i];
		GetElem(psB,i,&tmp);
		index = Search(psA,tmp);
		if(index < 0)
		{
			Insert(psA,0,tmp);//todo ,尾插
		}
	}
}

//todo  A=A n B

int CmpSeqList(const PDSeqList ps1,const PDSeqList ps2)
{
	int gap;
	int tmp1;
	int tmp2;
	for(int i=0;i<GetLength(ps1)&&i<GetLength(ps2);i++)
	{
		GetElem(ps1,i,&tmp1);
		GetElem(ps2,i,&tmp2);
		if((gap=tmp1-tmp2) != 0)
		{
			return gap;
		}
	}

	return GetLength(ps1) - GetLength(ps2);//abc,abcc
}

int main()
{
	DSeqList dsA;
	DSeqList dsB;
	InitSeqList(&dsA);
	InitSeqList(&dsB);
	int i;
	for(i=0;i<10;i++)
	{
		Insert(&dsA,i,i);
	}
	for(i=0;i<10;i++)
	{
		Insert(&dsB,i,i+5);
	}
	Show(&dsA);
	Show(&dsB);

	Merge(&dsA,&dsB);

	Show(&dsA);
	Show(&dsB);
	Destroy(&dsA);
	Destroy(&dsA);

	/*DSeqList ds;
	InitSeqList(&ds);

	for(int i=0;i<15;i++)
	{
		Insert(&ds,i,i);
	}
	Show(&ds);*/

	return 0;
}
#endif

/*
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> v1;

	cout<<"容量  "<<"有效数据个数"<<endl;

	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
		cout<<v1.capacity()<<"     "<<v1.size()<<endl;
	}

	return 0;
}
*/

//Fun()//int 
//{
//	return 0;
//}

/*
int main()
{
	SeqList sl;
	InitSeqList(&sl);
	int i;
	for(i=0;i<15;i++)
	{
		Insert(&sl,i,i);
	}
	DeletePos(&sl,9);
	Show(&sl);

	return 0;
}
*/
/*
typedef int(*Arr)[4] ;

//动态创建3*4的二维数组
int main()
{// int(*arr)[4]
	//int (**arr) = (int **)malloc(3*4*sizeof(int));//error
	//int (*arr)[4] = (int (*)[4])malloc(3*4*sizeof(int));
	Arr arr = (Arr)malloc(3*4*sizeof(int));

	int i;
	int j;

	int count = 0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			arr[i][j] = count++;
		}
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
*/
/*
int main()
{
	int **arr = (int **)malloc(3*sizeof(int *));
	int i;
	int j;
	for(i=0;i<3;i++)
	{
		arr[i] = (int *)malloc(4*sizeof(int));
	}

	int count = 0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			arr[i][j] = count++;
		}
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<3;i++)
	{
		free(arr[i]);
	}
	free(arr);
	arr = NULL;

	return 0;
}
*/

#if 0
void Swap(int &x,int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int a = 10;
	int b = 20;
	Swap(a,b);
	printf("%d,%d\n",a,b);
	/*b = 20;
	int &c = a;
	c = 100;
	printf("%d,%d\n",&c,&a);*/

	return 0;
}
#endif