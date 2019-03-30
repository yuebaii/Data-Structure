#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//大数处理
//在1000000个数字中，查找重复次数最多的数字
#define MAX_NUM 1000000


typedef struct HashTable
{
	int num;//数字
	int times;//出现的次数
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
//统计出现次数最多的数字
//定义统计的数组和数据出现的范围相关和数量无关
HashTable GetMaxTimes(const char *path)
{
	int arr[RAND_MAX+1] = {0};//RAND_MAX是随机数的取值范围
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
			h.times = arr[i];· 
			h.num = i;
		}
	}

	return h;
}

////////////////////////////////////////
//获取当前文件path中重复次数最多数据
//内存不足，一次最大定义长度为10000的数组
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

//内存不足，一次最大定义长度为10000的数组
//原数据的取值范围为0~32767，所有将所有数据散列成4部分
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
	while(fread(&tmp,sizeof(int),1,fr) > 0) // 将原文件中的数据散列到4个不同的文件中
	{
		switch(tmp%4)//哈希，（散列） 
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
	arr[0] = HashTimes(path0);//获取path0文件中重复次数最多的数据
	arr[1] = HashTimes(path1);
	arr[2] = HashTimes(path2);
	arr[3] = HashTimes(path3);

	int max = 0;//保存次数最多的数据的下标
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
	printf("重复次数最多的数字=%d,次数=%d\n",a.num,a.times);
	printf("重复次数最多的数字=%d,次数=%d\n",b.num,b.times);

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

int PopQueue(stack<int> & s1,stack<int> & s2)//s1一定不空
{
	int tmp;
	int val;

	val = s1.top();
	s1.pop();

	while(!s1.empty())//IsEmpty(s1);this指针
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
