 #include<stdio.h> 
#include<string.h> 
 
#define MaxStrSize 256         
typedef struct 
{ 
    char ch[MaxStrSize];        //ch��һ��������256���ַ����ַ����� 
    int length;  
} SString;                        //����˳������  
 
 

int PartPosition(SString s1,SString s2,int k) 
{ 
    int i,j; 
    i=k-1;                //ɨ��s1���±꣬��Ϊc�������±��Ǵ�0��ʼ������������1  
    j=0;                //ɨ��s2�Ŀ�ʼ�±� 
    while(i<s1.length && j<s2.length) 
        if(s1.ch[i]==s2.ch[j]) 
        { 
            i++; 
            j++;        //����ʹ�±�������һ���ַ�λ��  
        } 
        else 
        { 
            i=i-j+1;    //ʹi�±���ݵ�ԭλ�õ���һ��λ��  
            j=0;        //ʹjָ��s2�ĵ�һ���ַ��������±Ƚ�  
        } 
        if(j>=s2.length) 
            return i-s2.length;    //��ʾs1�д���s2����������ʼλ�� 
        else 
            return -1;            //��ʾs1�в�����s2,����-1  
}  
 

void CreateTextFile() 
{ 
    SString S; 
    char fname[10],yn; 
    FILE *fp; 
    printf("����Ҫ�������ļ�����"); 
    scanf(" %s",fname); 
    fp=fopen(fname,"w"); 
    yn='n';                            //���������־��ֵ 
    while(yn=='n'||yn=='N') 
    { 
        printf("����һ���ı���"); 
        gets(S.ch); 
        S.length=strlen(S.ch); 
        fwrite(&S,sizeof(SString),1,fp);  
        printf("����������? y or n:"); 
        yn=getchar();  
    }  
    fclose(fp);                        //�ر��ļ�; 
    printf("�����ļ�������\n");  
}  
 
void SubStrCount() 
{ 
    FILE *fp; 
    SString S,T;                    //������������ 
    char fname[10]; 
    int i=0,j,k; 
    printf("�����ı��ļ�����"); 
    scanf(" %s",fname); 
    fp=fopen(fname,"r"); 
    printf("����Ҫͳ�Ƽ����ĵ��ʣ�"); 
    scanf(" %s",T.ch); 
    T.length=strlen(T.ch); 
    while(!feof(fp))                //ɨ�������ı��ļ�  
    { 
        fread(&S,sizeof(SString),1,fp);    //����һ���ı� 
        //printf("��ȡ������Ϊ��%s",S.ch); 
        k=1;                        //��ʼ����ʼ����λ�� 
        while(k<S.length-1)            //������������S 
        { 
            j=PartPosition(S,T,k);    //���ô�ƥ�亯�� 
            if(j<0) 
                break; 
            else 
            { 
                i++;                //���ʼ�������1 
                k=j+T.length;        //������һ���Ӵ��ļ���  
            } 
        }  
    }  
    printf("\n����%s���ı��ļ�%s�й�����%d��\n",T.ch,fname,i);  
} 
 
 
void SubStrInd() 
{ 
    FILE *fp; 
    SString S,T;                    //������������ 
    char fname[10]; 
    int i,j,k,l,m; 
    int wz[20];                        //���һ�����Ӵ�ƥ��Ķ��λ�� 
    printf("�����ı��ļ�����"); 
    scanf(" %s",fname); 
    fp=fopen(fname,"r"); 
    printf("������Ҫ�����ĵ��ʣ�"); 
    scanf(" %s",T.ch); 
    T.length=strlen(T.ch); 
    l=0;                            //�м�������0 
    while(!feof(fp))                //ɨ�������ı��ļ�  
    { 
        fread(&S,sizeof(S),1,fp);    //����һ���ı� 
        l++;                        //�м���������1 
        k=1;                        //��ʼ����ʼ����λ�� 
        i=0;                        //��ʼ�����ʼ����� 
        while(k<S.length-1)            //������������S  
        { 
            j=PartPosition(S,T,k);    //���ô�ƥ�亯�� 
            if(j<0) break; 
            else 
            { 
                i++;                //���ʼ�������1 
                wz[i]=j;            //��¼ƥ�䵥��λ�� 
                k=j+T.length;        //������һ���Ӵ��ļ���  
            }     
        } 
        if(i>0) 
            printf("�кţ�%d��������%d��λ�÷ֱ�Ϊ��",l,i);  
        for(m=1;m<=i;m++) 
            printf("%4d",wz[m]); 
        printf("\n"); 
    }  
}  
 
int main() 
{ 
    void CreateTextFile(),SubStrCount(),SubStrInd(); //��������  
    int xz; 
    do 
    { 
        printf("*************************************\n"); 
        printf("* �ı��ļ��ļ������Ӵ���ͳ�Ƽ���λ  *\n"); 
        printf("*************************************\n"); 
        printf("*          1.�����ı��ļ�           *\n"); 
        printf("*          2.�����Ӵ��ļ���         *\n"); 
        printf("*      4.�˳���������             *\n");
		printf("***********************************\n");
		printf("*       ��ѡ��[1-4]             *\n");
		scanf("%d",&xz);
		switch(xz){
			case 1:CreateTextFile();break;
			case 2:SubStrCount();break;
			case 3:SubStrInd();break;
			case 4:return 0;
			default: printf("ѡ�����������ѡ��\n");
		}
	}while(1);
}

