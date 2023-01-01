#include <stdio.h>
#define MaxSize 5
typedef int ElemType;				//设置顺序表元素为int类型
typedef struct
{	ElemType data[MaxSize];			//存放顺序表的元素
	int length;						//顺序表的实际长度
} SqList;							//顺序表类型声明
void InitList(SqList &L)			//初始化顺序表L
{
	L.length=0;
}
void DestroyList(SqList L)			//销毁顺序表L
{
}
int GetLength(SqList L)				//求长度
{
	return L.length;
}
int GetElem(SqList L,int i,ElemType &e)	//求第i个元素
{	if (i<1 || i>L.length)			//无效的i值
		return 0;
	else
	{	e=L.data[i-1];
		return 1;
	}
}
int Locate(SqList L,ElemType x)		//查找第一个x元素的位置
{	int i=0;
	while (i<L.length && L.data[i]!=x)
		i++; 						//查找第1个值为x的元素
	if (i>=L.length) 
return(0);		//未找到返回0
	else
  return(i+1);				//找到后返回其逻辑序号
}
int InsElem(SqList &L,ElemType x,int i)	//插入x作为第i个元素
{	int j;
	if (i<1 || i>L.length+1)		//无效的参数i
		return 0;
	for (j=L.length;j>=i;j--)		//将位置为i的元素及之后的元素后移
		L.data[j]=L.data[j-1];
	L.data[i-1]=x;					//在位置i处放入x
	L.length++;						//顺序表长度增1
	return 1;
}
int DelElem(SqList &L,int i)		//删除第i个元素
{	int j;
	if (i<1 || i>L.length)			//无效的参数i
		return 0;
	for (j=i;j<L.length;j++)		//将位置为i的元素之后的元素前移
		L.data[j-1]=L.data[j];
	L.length--;						//顺序表长度减1
	return 1;
}
  int DelElem_iToj（SqList &L,int i,int j）
{
	int m,n;
	if(i<1||i>L.length+1)//判断删除位置是否合理，表长+1
	{
       printf("删除位置不合理\n");
       return(0);
    }
   n=i+j-1;
   if(n<=L.length)//判断删除位置是否合理 
       {
          for(m=i+j-1;m<=L.length;m++)
          {
              L.data[m-j]=L.data[m];//将第k个元素至第L.length个元素向前移动 
            }
         L.length=L.length-j;//顺序表长度减j 
           return(1);
        }
      else
     {
         L.length=i-2;
         return(1);
      }
    }

void DispList(SqList L)				//输出顺序表
{	int i;
	if(L.length>0)
	{
		printf("当前顺序表中的元素为：");
		for (i=0;i<L.length;i++)
			printf("%d ",L.data[i]);
	}
	else
		printf("顺序表已空");
	printf("\n");
}
void CreateList(SqList &L,ElemType a[],int n)	//整体创建顺序表L
{
	int i,k=0;						//k累计顺序表L中的元素个数
	for (i=0;i<n;i++)
	{
		L.data[k]=a[i];				//向L中添加一个元素
		k++;						//L中元素个数增1
	}
	L.length=k;						//设置L的长度
}



int menu(){
      int i=0;
      printf("1.逐个插入元素创建链表\n");
      printf("2.整体创建顺序表\n");
	  printf("3.退出\n");
      scanf(" %d",&i);
      return i;
}

int menu1(){
     int i=0;
	 printf("1.插入元素\n");
	 printf("2.输出顺序表\n");
	 printf("3.获取第i个元素\n");
	 printf("4.查找第一个值为x元素的位置\n");
	 printf("5.删除第i元素\n");
	 printf("6.退出\n");
	 scanf(" %d",&i);
     return i;
}


void menu2(SqList &L){

	int i=0,x=0,chack=0,result=0;
	ElemType e;

   	    while(chack!=6){
              chack=menu1();//选择功能
			  result=0;
	     	switch(chack){
	    	    case 1:
				    printf("输入你需要插入的元素");                 
				    scanf(" %d",&x);
                    printf("输入你需要插入的位置");
			        scanf(" %d",&i);
					if(L.length>=MaxSize){
                        printf("顺序表已满\n");
						break;
					}
				    InsElem(L,x,i);			//在数组末尾插入元素i
			        break;
				case 2:
                    DispList(L);//1.输出链表
			        break;
				case 3:	
					printf("输入你需要获取的第i个元素:\n");
					scanf(" %d",&i);
                    result=GetElem(L,i,e);//2.获取第i个元素
					if(result==1){
                    printf("  第%d个元素:%d\n",i,e);
					}else
                       printf("  第%d个元素不存在\n",i);   
			        break;
				case 4:  
					printf("输入你要查找的x元素:\n");
					scanf("  %d",&e);
					result=Locate(L,e);
					if(result!=0){
                    	printf("  元素%d是第%d个元素\n",e,Locate(L,e),result);	//3.查找第一个x元素的位置
					}else
                        	printf("  元素%d不存在\n",e);	//3.查找第一个x元素的位置
			        break;
				case 5: 
                    printf("输入你需要 删除第i个元素:\n");
				    scanf(" %d",&i);
					result=DelElem(L,i);
					if(result==1){
					printf("  删除第%d个元素\n",i);//4.删除第i个元素
					}else
                            printf("  第%d个元素不存在\n",i);   
			        break;
				case 6: 
					printf("销毁L\n");
					DestroyList(L);
					return;
				default:printf("无该选项\n");
			   }
			 }
}
int main()                       //主函数
{	int i=0;
    int chack=0;
	int x=0;
	ElemType e;
   
	SqList L;
	int a[]={2,5,4,1,9};
    int n=sizeof(a)/sizeof(a[0]);
     
	while(chack!=3){
		chack=menu();//选择创建顺序表的方式
		switch(chack){
        case 1:
			   InitList(L);			//初始化顺序表L
               printf("输入需要插入多少个的元素:\n");
			   scanf(" %d",&x);   
			   if(x>MaxSize){
				   printf("超出顺序表长度%d\n",MaxSize);
				  break;
			   }
			   else{
				   printf("输入需要插入的元素:\n");
			  
			       for(i=1;i<=x;i++){
				
					scanf(" %d",&e);
                    InsElem(L,e,i);			//插入元素1
				  }
			      menu2(L);
			      return(0);//直接退出
			   }
		       break;
		case 2:
               printf("  整体创建L\n");
               CreateList(L,a,n);
			   menu2(L);
               return(0);//直接退出
		default:printf("无该选\n");
		}
   	}
}

