#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//��������
//��1000000�������У������ظ�������������
#define MAX_NUM 1000000


typedef struct HashTable
{
	int num;//����
	int times;//���ֵĴ���
}HashTable;

void CreateBigFile(const char *path)
{
	FILE *fw = fopen(path,"wb");
	assert(fw != NULL);
	int tmp;

	for(int i=0;i<MAX_NUM;i++)
	{
		tmp = rand();
		fwrite(&tmp,sizeof(int),1,fw);
	}

	fclose(fw);
}
//ͳ�Ƴ��ִ�����������
//����ͳ�Ƶ���������ݳ��ֵķ�Χ��غ������޹�
HashTable GetMaxTimes(const char *path)
{
	int arr[RAND_MAX+1] = {0};//RAND_MAX���������ȡֵ��Χ
	int tmp;

	FILE *fr = fopen(path,"rb");
	assert(fr != NULL);

	while(fread(&tmp,sizeof(int),1,fr) > 0)//10
	{
		arr[tmp]++;//y = ax+b
	}

	fclose(fr);

	HashTable h = {0,0};
	for(int i=0;i<RAND_MAX+1;i++)
	{
		if(h.times < arr[i])
		{
			h.times = arr[i];�� 
			h.num = i;
		}
	}

	return h;
}

////////////////////////////////////////
//��ȡ��ǰ�ļ�path���ظ������������
//�ڴ治�㣬һ������峤��Ϊ10000������
static HashTable HashTimes(const char *path)
{
	int arr[10000] = {0};

	int tmp;
	FILE *fr = fopen(path,"rb");
	assert(fr != NULL);

	while(fread(&tmp,sizeof(int),1,fr) > 0)//0,4,8,12  //1,5,9
	{
		arr[tmp/4]++;//y = x/4;
	}

	fclose(fr);

	HashTable h = {0};
	for(int i=0;i<10000;i++)
	{
		if(h.times < arr[i])
		{
			h.times = arr[i];
			h.num = i*4+tmp%4;
		}
	}

	return h;
}

//�ڴ治�㣬һ������峤��Ϊ10000������
//ԭ���ݵ�ȡֵ��ΧΪ0~32767�����н���������ɢ�г�4����
HashTable GetMaxTimes2(const char *path)
{
	char *path0 = "0.txt";
	char *path1 = "1.txt";
	char *path2 = "2.txt";
	char *path3 = "3.txt";
	FILE * fr = fopen(path,"rb");
	FILE *fw0 = fopen(path0,"wb");
	FILE *fw1 = fopen(path1,"wb");
	FILE *fw2 = fopen(path2,"wb");
	FILE *fw3 = fopen(path3,"wb");
	assert(fr!=NULL && fw0!=NULL && fw1!=NULL && fw2!=NULL && fw3!=NULL);

	int tmp;
	while(fread(&tmp,sizeof(int),1,fr) > 0) // ��ԭ�ļ��е�����ɢ�е�4����ͬ���ļ���
	{
		switch(tmp%4)//��ϣ����ɢ�У� 
		{
		case 0:
			fwrite(&tmp,sizeof(int),1,fw0);
			break;
		case 1:
			fwrite(&tmp,sizeof(int),1,fw1);
			break;
		case 2:
			fwrite(&tmp,sizeof(int),1,fw2);
			break;
		case 3:
			fwrite(&tmp,sizeof(int),1,fw3);
			break;
		}
	}

	HashTable arr[4] = {0};
	arr[0] = HashTimes(path0);//��ȡpath0�ļ����ظ�������������
	arr[1] = HashTimes(path1);
	arr[2] = HashTimes(path2);
	arr[3] = HashTimes(path3);

	int max = 0;//��������������ݵ��±�
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if(arr[max].times < arr[i].times)
		{
			max = i;
		}
	}

	fclose(fr);
	fclose(fw0);
	fclose(fw1);
	fclose(fw2);
	fclose(fw3);
	remove(path0);
	remove(path1);
	remove(path2);
	remove(path3);

	return arr[max];
}
///////////////////////////////////////

int main()
{
	char *path = "big.txt";
	//CreateBigFile(path);

	HashTable a = GetMaxTimes(path);
	HashTable b = GetMaxTimes2(path);
	printf("�ظ�������������=%d,����=%d\n",a.num,a.times);
	printf("�ظ�������������=%d,����=%d\n",b.num,b.times);

	return 0;
}

#if 0
#include <stdio.h>
#include <stack>
#include <iostream>
using namespace std;

void PushQueue(stack<int> & s1,stack<int> & s2,int val)
{
	s1.push(val);
}

int PopQueue(stack<int> & s1,stack<int> & s2)//s1һ������
{
	int tmp;
	int val;

	val = s1.top();
	s1.pop();

	while(!s1.empty())//IsEmpty(s1);thisָ��
	{
		s2.push(val);
		val = s1.top();
		s1.pop();
	}

	while(!s2.empty())
	{
		tmp = s2.top();
		s2.pop();
		s1.push(tmp);
	}

	return val;
}

int main()
{
	stack<int> s1;
	stack<int> s2;

	for(int i=0;i<10;i++)
	{
		PushQueue(s1,s2,i);
	}

	while(!s1.empty())
	{
		printf("%d\n",PopQueue(s1,s2));
	}

	return 0;
}
#endif
/*
#include "nlist.h"

int main()
{
	NList plist;//4
	//NNode head;//8
	InitList(&plist);
	for(int i=0;i<15;i++)
	{
		Insert_head(&plist,i);
	}
	Show(plist);

	return 0;
}
*/
