#include<stdio.h>
#include<string.h> 

#define MaxStrSize 256

typedef struct{
	char ch[MaxStrSize]; 
	int length;
}SeqString;

int PartPosition(SeqString s1,SeqString s2,int k)
{
	int i,j;
	i=k-1;
	j=0;
	while(i<s1.length && j<s2.length)//两个串均未比较到串尾 
		if(s1.ch[i]==s1.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
		}
		if(j>=s2.length)	
		return i+1-s2.length;
		else 
		return -1;
}

void CreatTextFile()
{
	SeqString S;
	char fname[10],yn;
	FILE *fp;
	printf("请输入要建立的文件名");
	scanf("%s",fname);
	fp=fopen(fname,"w");
	yn='n';
	while(yn=='n'  || yn=='N'){
		printf("输入一行文本：");
		getchar();
		gets(S.ch);
		S.length=strlen(S.ch);
		fwrite(&S,sizeof(S),1,fp);
		printf("结束输入吗？y or n:");
		yn=getchar();
	}
	fclose(fp);
	printf("建立文件结束！\n"); 
}

void SubStrCount()
{
	FILE *fp;
	SeqString S,T;
	char fname[10] ;
	int i=0,j,k;
	printf("输入文本文件名");
	scanf("%s",fname);
	fp=fopen(fname,"r"); 
	printf("输入要统计计数的单词");
	scanf("%s",T.ch);
	T.length=strlen(T.ch);
	while(!feof(fp)){
		fread(&S,sizeof(S),1,fp);
		if(feof(fp)) break;
		k=1;
		while(k<S.length)
		{
			j=PartPosition(S,T,k);
			if(j<0) break;
			else
			{
				i++;
				k=j+T.length;
		    }
		}
	}
	printf("\n单词%s在文本文件%s中共出现%d次\n",T.ch,fname,i);
}

void SubStrInd()
{
	FILE *fp;
	SeqString S,T;
	char fname[10];
	int i,j,k,l,m;
	int wz[20];
	printf("输入文本文件名：");
	scanf("%s",fname);
	fp=fopen(fname,"r");
	printf("输入需要检索的单词：");
	scanf("%s",T.ch);
	T.length=strlen(T.ch);
	l=0;
	while(!feof(fp)){
		fread(&S,sizeof(S),l,fp);
		if(feof(fp))break;
		l++;
		k=1;
		i=0;
		while(k<S.length)
		{
			j=PartPosition(S,T,k);
			if(j<0)break;
			else
			{
				i++;
				wz[i]=j;
				k=j+T.length;
			}
		}
		if(i>0){
			printf("行号：%d,次数：%d,位置分别为：",l,i);
			for(m=1;m<=i;m++) printf("%4d",wz[m]);
			printf("\n");
		}
	}
	
}

int main(void)
{
	void CreatTextFile(),SubStrCount(),SubStrInd();
	int xz;
	do{
		printf("*      1.建立文本文件             *\n");
		printf("*      2.单词子串的计数           *\n");
		printf("*      3.单词子串的定位           *\n");
		printf("*      4.退出整个程序             *\n");
		printf("*       请选择：[1-4]             *\n");
		scanf("%d",&xz);
		switch(xz){
			case 1:CreatTextFile();break;
			case 2:SubStrCount();break;
			case 3:SubStrInd();break;
			case 4:return 0;
			default: printf("选择错误！请重新选择！\n");
		}
	}while(1);
}

