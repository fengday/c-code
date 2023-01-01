 #include<stdio.h> 
#include<string.h> 
 
#define MaxStrSize 256         
typedef struct 
{ 
    char ch[MaxStrSize];        //ch是一个可容纳256个字符的字符数组 
    int length;  
} SString;                        //定义顺序串类型  
 
 

int PartPosition(SString s1,SString s2,int k) 
{ 
    int i,j; 
    i=k-1;                //扫描s1的下标，因为c中数组下标是从0开始，串中序号相差1  
    j=0;                //扫描s2的开始下标 
    while(i<s1.length && j<s2.length) 
        if(s1.ch[i]==s2.ch[j]) 
        { 
            i++; 
            j++;        //继续使下标移向下一个字符位置  
        } 
        else 
        { 
            i=i-j+1;    //使i下标回溯到原位置的下一个位置  
            j=0;        //使j指向s2的第一个字符，再重新比较  
        } 
        if(j>=s2.length) 
            return i-s2.length;    //表示s1中存在s2，返回其起始位置 
        else 
            return -1;            //表示s1中不存在s2,返回-1  
}  
 

void CreateTextFile() 
{ 
    SString S; 
    char fname[10],yn; 
    FILE *fp; 
    printf("输入要建立的文件名："); 
    scanf(" %s",fname); 
    fp=fopen(fname,"w"); 
    yn='n';                            //输入结束标志初值 
    while(yn=='n'||yn=='N') 
    { 
        printf("输入一行文本："); 
        gets(S.ch); 
        S.length=strlen(S.ch); 
        fwrite(&S,sizeof(SString),1,fp);  
        printf("结束输入吗? y or n:"); 
        yn=getchar();  
    }  
    fclose(fp);                        //关闭文件; 
    printf("建立文件结束！\n");  
}  
 
void SubStrCount() 
{ 
    FILE *fp; 
    SString S,T;                    //定义两个变量 
    char fname[10]; 
    int i=0,j,k; 
    printf("输入文本文件名："); 
    scanf(" %s",fname); 
    fp=fopen(fname,"r"); 
    printf("输入要统计计数的单词："); 
    scanf(" %s",T.ch); 
    T.length=strlen(T.ch); 
    while(!feof(fp))                //扫描整个文本文件  
    { 
        fread(&S,sizeof(SString),1,fp);    //读入一行文本 
        //printf("读取的内容为：%s",S.ch); 
        k=1;                        //初始化开始检索位置 
        while(k<S.length-1)            //检索整个主串S 
        { 
            j=PartPosition(S,T,k);    //调用串匹配函数 
            if(j<0) 
                break; 
            else 
            { 
                i++;                //单词计数器加1 
                k=j+T.length;        //继续下一个子串的检索  
            } 
        }  
    }  
    printf("\n单词%s在文本文件%s中共出现%d次\n",T.ch,fname,i);  
} 
 
 
void SubStrInd() 
{ 
    FILE *fp; 
    SString S,T;                    //定义两个变量 
    char fname[10]; 
    int i,j,k,l,m; 
    int wz[20];                        //存放一行中子串匹配的多个位置 
    printf("输入文本文件名："); 
    scanf(" %s",fname); 
    fp=fopen(fname,"r"); 
    printf("输入需要检索的单词："); 
    scanf(" %s",T.ch); 
    T.length=strlen(T.ch); 
    l=0;                            //行计数器置0 
    while(!feof(fp))                //扫描整个文本文件  
    { 
        fread(&S,sizeof(S),1,fp);    //读入一行文本 
        l++;                        //行计数器自增1 
        k=1;                        //初始化开始检索位置 
        i=0;                        //初始化单词记数器 
        while(k<S.length-1)            //检索整个主串S  
        { 
            j=PartPosition(S,T,k);    //调用串匹配函数 
            if(j<0) break; 
            else 
            { 
                i++;                //单词计数器加1 
                wz[i]=j;            //记录匹配单词位置 
                k=j+T.length;        //继续下一个子串的检索  
            }     
        } 
        if(i>0) 
            printf("行号：%d，次数：%d，位置分别为：",l,i);  
        for(m=1;m<=i;m++) 
            printf("%4d",wz[m]); 
        printf("\n"); 
    }  
}  
 
int main() 
{ 
    void CreateTextFile(),SubStrCount(),SubStrInd(); //函数声明  
    int xz; 
    do 
    { 
        printf("*************************************\n"); 
        printf("* 文本文件的检索、子串的统计及定位  *\n"); 
        printf("*************************************\n"); 
        printf("*          1.建立文本文件           *\n"); 
        printf("*          2.单词子串的计数         *\n"); 
        printf("*      4.退出整个程序             *\n");
		printf("***********************************\n");
		printf("*       请选择：[1-4]             *\n");
		scanf("%d",&xz);
		switch(xz){
			case 1:CreateTextFile();break;
			case 2:SubStrCount();break;
			case 3:SubStrInd();break;
			case 4:return 0;
			default: printf("选择错误！请重新选择！\n");
		}
	}while(1);
}

