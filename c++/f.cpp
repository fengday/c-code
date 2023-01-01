#define MaxStrSize 999

typedef struct{
	char ch[MaxStrSize];//ch����999���ַ� 
	int length;
}SeqString;//�����ַ��� 

int Index_KMP(SeqString s1,SeqString s2,int k)
{
	int i,j;
	i=k-1;
	j=0;
	while(i<s1.length && j<s2.length)//��������Ϊ�Ƚϵ���δ 
		if(s1.ch[i]==s1.ch[j])//�����ȽϺ���ַ� 
		{
			i++;
			j++;
		}
		else           //ģʽ�������ƶ� 
		{
			i=i-j+1;
		}
		if(j>=s2.length)	//ƥ��ɹ� 
return i+1-s2.length;
		else return -1;//ƥ��ʧ�� 
}

void CreatTextFile()
{
	SeqString S;
	char fname[10],yn;
	FILE *fp;
	printf("���뽨���ļ���");
	scanf("%s",fname);
	fp=fopen(fname,"w");
	yn='n';  //���������׼��ֵ 
	while(yn=='n'  || yn=='N'){
		printf("����һ���ı���");
		getchar();
		gets(S.ch);
		S.length=strlen(S.ch);
		fwrite(&S,sizeof(S),1,fp);
		printf("y����n����:");
		yn=getchar();
	}
	fclose(fp);//�ر��ļ� 
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
	while(!feof(fp)){ //ɨ���ļ��� 
		fread(&S,sizeof(S),1,fp);//�����ı� 
		k=1;   
		while(k<S.length)//��������S 
		{
			j=Index_KMP(S,T,k);//���ô�ƥ�亯�� 
			if(j<0) break;
			else{
				i++; //����+1 
				k=j+T.length;//�������� 
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
	int wz[20];//���һ�����Ӵ�ƥ��Ķ��λ�� 
	printf("�����ı��ļ�����");
	scanf("%s",fname);
	fp=fopen(fname,"r");
	printf("������Ҫ�����ĵ��ʣ�");
	scanf("%s",T.ch);
	T.length=strlen(T.ch);
	l=0;   //��������0 
	while(!feof(fp)){
		fread(&S,sizeof(S),l,fp);//�����ı� 
		l++;
		k=1;//��ʼ����ʼ����λ�� 
		i=0;//��ʼ�����ʼ����� 
		while(k<S.length)//������������ 
		{
			j=Index_KMP(S,T,k);//���ô��������� 
			if(j<0)break;
			else{
				i++;//������+1 
				wz[i]=j;//��¼����λ�� 
				k=j+T.length;//������һ�������� 
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
		printf("***********************************\n");
		printf("*�ı��ļ��ļ������Ӵ���ͳ�Ƽ���λ*\n");
		printf("***********************************\n");
		printf("*      1.�����ı��ļ�             *\n");
		printf("*      2.�����Ӵ��ļ���           *\n");
		printf("*      3.�����Ӵ��Ķ�λ           *\n");
		printf("*      4.�˳���������             *\n");
		printf("***********************************\n");
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

