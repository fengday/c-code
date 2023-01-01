#include <stdio.h>
#include <String.h>
#include <stdlib.h>

typedef int KeyType;       // 关键字的类型
const int MAXSIZE=100;     // 数组的容量
typedef struct ElemType            //学生的记录信息
   { 
	 KeyType  key ;        //学号
     char name[8];         //姓名
     int english;          //成绩
     int math;             //成绩
     int dataStructure;      //成绩
   } ElemType;
typedef struct SqHash
  { 

      struct ElemType *ht;     // 哈希表数组
      int length;       // 哈希表容量
      KeyType   p;      // 除留余数法的大质数
 
}SqHash;
//-------------------------------------------------------------
void sqHash(SqHash *hash,int n1,int p1)
 { int i;

   hash->length=n1;  hash->p=p1;
   hash->ht= ( ElemType*)malloc(sizeof(ElemType)*hash->length); 
   for(i=0;i<hash->length;i++)
	   hash->ht[i].key=0;
  }

  int  finds(SqHash *hash,KeyType K )
 { 
//将此成员函数补充完整，使得程序能够正确运行
}
void  creat_hash(SqHash *hash)
 { 
	int i,K,en,ma,da;char na[8];
	printf("\n  请逐一输入各个学号（关键字值）（-1结束）：");
    scanf(" %d",&K);
  
    while(K!=-1)
    { 
	   i=finds(hash,K);//函数未写 返回0
   	   if(i==-32767)  {
		   printf("\n   成功查找到,不再插入！");
		   printf("\n  请逐一输入各个学号（关键字值）（-1结束）：");
           scanf(" %d",&K);
	
	   }
       else  if(i!=32767){
		          printf("\n  请输入学生的姓名，英语成绩、高数成绩和数据结构成绩：");
				  scanf(" %s",na);
				  scanf(" %d",&en);
				  scanf(" %d",&ma);
				  scanf(" %d",&da);

                  hash->ht[i].key=K;
                  strcpy(hash->ht[i].name,na);     //用串拷贝赋值
                  hash->ht[i].english=en;
                  hash->ht[i].math=ma; 
				  hash->ht[i].dataStructure =da;            
					 //　插入学生记录K
				  printf("\n   插入成功！" );
				  printf("\n  请逐一输入各个学号（关键字值）（-1结束）：" );
				  scanf(" %d",&K);
        
	   }
	   else{
		   //当i==32767时，代表哈希表已满
		   printf("哈希表已满\n");
		   break;
	   }
	}
 }

void  PrintOut( SqHash hash)
{ int i;
  for (i=0;i<hash.length; i++)
	  if(hash.ht[i].key!=0){
		  printf("\n i=%d  学号:%d   姓名:%s   英语成绩:%d   高数成绩:%d     数据结构成绩:%d",i,hash.ht[i].key,hash.ht[i].name,hash.ht[i].english,hash.ht[i].math,hash.ht[i].dataStructure);
        
	  }
}
int main()
{  int p0,n0;
   int k; 
   int i;
   SqHash  ha; 
   ElemType a;
 
   printf("\n  请输入n值（n值应是记录总数的1.3-1.5倍)");
                          
   scanf(" %d",&n0);     
   printf("\n  请输入P值（应是不大于n 的大质数）：");
                
   scanf(" %d",&p0);    
   sqHash(&ha,n0,p0);//初始化哈希表
   
   do {
	   printf("\n\n\n");
	   printf("\n       1. 建立哈希表（开放地址法）  ");
       printf("\n       2. 在哈希表中查找某位学生 ");
	   printf("\n       3. 输出哈希表");
	   printf("\n       4. 结束");
	   printf("\n=======================================");
	   printf("\n       输入您的选择(1,2,3,4):");
	   scanf(" %d",&k);
   
       switch(k){
	       case 1: {
		          creat_hash(&ha);
                 }
			   break; 
	        case 2:
				{  
					printf("\n  请输入待查找的学生学号：");
					scanf(" %d",&a.key);
				
                   i=finds(&ha,a.key);
                    if(i!=-32767) 
						printf("\n  此学生%d 不存在！",a.key);
                    } 				    					
				    break;
	         case 3:{ 
				       PrintOut(ha); 
					}  
				 break;
	         }
     }while(k>=1&&k<=3);
  // _getch();       
 return 0;
}

