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
	while(i<s1.length && j<s2.length)//��������δ�Ƚϵ���β 
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
	printf("������Ҫ�������ļ���");
	scanf("%s",fname);
	fp=fopen(fname,"w");
	yn='n';
	while(yn=='n'  || yn=='N'){
		printf("����һ���ı���");
		getchar();
		gets(S.ch);
		S.length=strlen(S.ch);
		fwrite(&S,sizeof(S),1,fp);
		printf("����������y or n:");
		yn=getchar();
	}
	fclose(fp);
	printf("�����ļ�������\n"); 
}

void SubStrCount()
{
	FILE *fp;
	SeqString S,T;
	char fname[10] ;
	int i=0,j,k;
	printf("�����ı��ļ���");
	scanf("%s",fname);
	fp=fopen(fname,"r"); 
	printf("����Ҫͳ�Ƽ����ĵ���");
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
	printf("\n����%s���ı��ļ�%s�й�����%d��\n",T.ch,fname,i);
}

void SubStrInd()
{
	FILE *fp;
	SeqString S,T;
	char fname[10];
	int i,j,k,l,m;
	int wz[20];
	printf("�����ı��ļ�����");
	scanf("%s",fname);
	fp=fopen(fname,"r");
	printf("������Ҫ�����ĵ��ʣ�");
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
			printf("�кţ�%d,������%d,λ�÷ֱ�Ϊ��",l,i);
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
		printf("*      1.�����ı��ļ�             *\n");
		printf("*      2.�����Ӵ��ļ���           *\n");
		printf("*      3.�����Ӵ��Ķ�λ           *\n");
		printf("*      4.�˳���������             *\n");
		printf("*       ��ѡ��[1-4]             *\n");
		scanf("%d",&xz);
		switch(xz){
			case 1:CreatTextFile();break;
			case 2:SubStrCount();break;
			case 3:SubStrInd();break;
			case 4:return 0;
			default: printf("ѡ�����������ѡ��\n");
		}
	}while(1);
}

