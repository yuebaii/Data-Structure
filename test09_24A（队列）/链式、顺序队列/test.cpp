#include <stdio.h>
#include "slist.h"

//todo  int BF(const char *s,const char *sub,int pos);
//�´ον�KMP�㷨  ����Ҫ 

#include<stdio.h>

int BF(const char *s,const char *sub,int pos)
{
	int count = 0;
	int j = 0;
	int i = 0;
	while(sub[i++] != '\0')
	{
		count++;
	}
	
    i = 0;
	while((sub[j]!='\0') && (s[i]!='\0'))
	{
		if(sub[j] == s[i])
		{	
			j++;
			i++;
		}
		if(sub[j] != s[i])
		{
			j = 0;
			i++;
		}
	}
	printf("%d\n", i-count-1);
	return i-count-1;
}

int main()
{
	SList s;//sizeof(s) == 80

	InitSList(s);//s��������

	for(int i=0;i<15;i++)//
	{
		Insert_head(s,i);
	}

	Show(s);

	return 0;
}

/*
#include "lqueue.h"

int main()
{
	HNode q;
	InitQueue(&q);
	for(int i=0;i<15;i++)
	{
		Push(&q,i);
	}

	int tmp;
	while(!IsEmpty(&q))
	{
		Pop(&q,&tmp);
		printf("%d\n",tmp);
	}

	return 0;
}
*/

/*
#include "queue.h"

//todo,��������
//todo,������룬ɾ��
//todo,����������򣬹鲢����

int main()
{
	Queue q;
	InitQueue(&q);
	for(int i=0;i<15;i++)
	{
		Push(&q,i);
	}

	int tmp;
	while(!IsEmpty(&q))
	{
		Pop(&q,&tmp);
		printf("%d\n",tmp);
	}

	return 0;
}
*/