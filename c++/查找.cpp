#include <stdio.h>
#include <String.h>
#include <stdlib.h>

typedef int KeyType;       // �ؼ��ֵ�����
const int MAXSIZE=100;     // ���������
typedef struct ElemType            //ѧ���ļ�¼��Ϣ
   { 
	 KeyType  key ;        //ѧ��
     char name[8];         //����
     int english;          //�ɼ�
     int math;             //�ɼ�
     int dataStructure;      //�ɼ�
   } ElemType;
typedef struct SqHash
  { 

      struct ElemType *ht;     // ��ϣ������
      int length;       // ��ϣ������
      KeyType   p;      // �����������Ĵ�����
 
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
//���˳�Ա��������������ʹ�ó����ܹ���ȷ����
}
void  creat_hash(SqHash *hash)
 { 
	int i,K,en,ma,da;char na[8];
	printf("\n  ����һ�������ѧ�ţ��ؼ���ֵ����-1��������");
    scanf(" %d",&K);
  
    while(K!=-1)
    { 
	   i=finds(hash,K);//����δд ����0
   	   if(i==-32767)  {
		   printf("\n   �ɹ����ҵ�,���ٲ��룡");
		   printf("\n  ����һ�������ѧ�ţ��ؼ���ֵ����-1��������");
           scanf(" %d",&K);
	
	   }
       else  if(i!=32767){
		          printf("\n  ������ѧ����������Ӣ��ɼ��������ɼ������ݽṹ�ɼ���");
				  scanf(" %s",na);
				  scanf(" %d",&en);
				  scanf(" %d",&ma);
				  scanf(" %d",&da);

                  hash->ht[i].key=K;
                  strcpy(hash->ht[i].name,na);     //�ô�������ֵ
                  hash->ht[i].english=en;
                  hash->ht[i].math=ma; 
				  hash->ht[i].dataStructure =da;            
					 //������ѧ����¼K
				  printf("\n   ����ɹ���" );
				  printf("\n  ����һ�������ѧ�ţ��ؼ���ֵ����-1��������" );
				  scanf(" %d",&K);
        
	   }
	   else{
		   //��i==32767ʱ�������ϣ������
		   printf("��ϣ������\n");
		   break;
	   }
	}
 }

void  PrintOut( SqHash hash)
{ int i;
  for (i=0;i<hash.length; i++)
	  if(hash.ht[i].key!=0){
		  printf("\n i=%d  ѧ��:%d   ����:%s   Ӣ��ɼ�:%d   �����ɼ�:%d     ���ݽṹ�ɼ�:%d",i,hash.ht[i].key,hash.ht[i].name,hash.ht[i].english,hash.ht[i].math,hash.ht[i].dataStructure);
        
	  }
}
int main()
{  int p0,n0;
   int k; 
   int i;
   SqHash  ha; 
   ElemType a;
 
   printf("\n  ������nֵ��nֵӦ�Ǽ�¼������1.3-1.5��)");
                          
   scanf(" %d",&n0);     
   printf("\n  ������Pֵ��Ӧ�ǲ�����n �Ĵ���������");
                
   scanf(" %d",&p0);    
   sqHash(&ha,n0,p0);//��ʼ����ϣ��
   
   do {
	   printf("\n\n\n");
	   printf("\n       1. ������ϣ�����ŵ�ַ����  ");
       printf("\n       2. �ڹ�ϣ���в���ĳλѧ�� ");
	   printf("\n       3. �����ϣ��");
	   printf("\n       4. ����");
	   printf("\n=======================================");
	   printf("\n       ��������ѡ��(1,2,3,4):");
	   scanf(" %d",&k);
   
       switch(k){
	       case 1: {
		          creat_hash(&ha);
                 }
			   break; 
	        case 2:
				{  
					printf("\n  ����������ҵ�ѧ��ѧ�ţ�");
					scanf(" %d",&a.key);
				
                   i=finds(&ha,a.key);
                    if(i!=-32767) 
						printf("\n  ��ѧ��%d �����ڣ�",a.key);
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

