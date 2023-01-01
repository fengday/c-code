#include <stdio.h>
#define MaxSize 5
typedef int ElemType;				//����˳���Ԫ��Ϊint����
typedef struct
{	ElemType data[MaxSize];			//���˳����Ԫ��
	int length;						//˳����ʵ�ʳ���
} SqList;							//˳�����������
void InitList(SqList &L)			//��ʼ��˳���L
{
	L.length=0;
}
void DestroyList(SqList L)			//����˳���L
{
}
int GetLength(SqList L)				//�󳤶�
{
	return L.length;
}
int GetElem(SqList L,int i,ElemType &e)	//���i��Ԫ��
{	if (i<1 || i>L.length)			//��Ч��iֵ
		return 0;
	else
	{	e=L.data[i-1];
		return 1;
	}
}
int Locate(SqList L,ElemType x)		//���ҵ�һ��xԪ�ص�λ��
{	int i=0;
	while (i<L.length && L.data[i]!=x)
		i++; 						//���ҵ�1��ֵΪx��Ԫ��
	if (i>=L.length) 
return(0);		//δ�ҵ�����0
	else
  return(i+1);				//�ҵ��󷵻����߼����
}
int InsElem(SqList &L,ElemType x,int i)	//����x��Ϊ��i��Ԫ��
{	int j;
	if (i<1 || i>L.length+1)		//��Ч�Ĳ���i
		return 0;
	for (j=L.length;j>=i;j--)		//��λ��Ϊi��Ԫ�ؼ�֮���Ԫ�غ���
		L.data[j]=L.data[j-1];
	L.data[i-1]=x;					//��λ��i������x
	L.length++;						//˳�������1
	return 1;
}
int DelElem(SqList &L,int i)		//ɾ����i��Ԫ��
{	int j;
	if (i<1 || i>L.length)			//��Ч�Ĳ���i
		return 0;
	for (j=i;j<L.length;j++)		//��λ��Ϊi��Ԫ��֮���Ԫ��ǰ��
		L.data[j-1]=L.data[j];
	L.length--;						//˳����ȼ�1
	return 1;
}
  int DelElem_iToj��SqList &L,int i,int j��
{
	int m,n;
	if(i<1||i>L.length+1)//�ж�ɾ��λ���Ƿ������+1
	{
       printf("ɾ��λ�ò�����\n");
       return(0);
    }
   n=i+j-1;
   if(n<=L.length)//�ж�ɾ��λ���Ƿ���� 
       {
          for(m=i+j-1;m<=L.length;m++)
          {
              L.data[m-j]=L.data[m];//����k��Ԫ������L.length��Ԫ����ǰ�ƶ� 
            }
         L.length=L.length-j;//˳����ȼ�j 
           return(1);
        }
      else
     {
         L.length=i-2;
         return(1);
      }
    }

void DispList(SqList L)				//���˳���
{	int i;
	if(L.length>0)
	{
		printf("��ǰ˳����е�Ԫ��Ϊ��");
		for (i=0;i<L.length;i++)
			printf("%d ",L.data[i]);
	}
	else
		printf("˳����ѿ�");
	printf("\n");
}
void CreateList(SqList &L,ElemType a[],int n)	//���崴��˳���L
{
	int i,k=0;						//k�ۼ�˳���L�е�Ԫ�ظ���
	for (i=0;i<n;i++)
	{
		L.data[k]=a[i];				//��L�����һ��Ԫ��
		k++;						//L��Ԫ�ظ�����1
	}
	L.length=k;						//����L�ĳ���
}



int menu(){
      int i=0;
      printf("1.�������Ԫ�ش�������\n");
      printf("2.���崴��˳���\n");
	  printf("3.�˳�\n");
      scanf(" %d",&i);
      return i;
}

int menu1(){
     int i=0;
	 printf("1.����Ԫ��\n");
	 printf("2.���˳���\n");
	 printf("3.��ȡ��i��Ԫ��\n");
	 printf("4.���ҵ�һ��ֵΪxԪ�ص�λ��\n");
	 printf("5.ɾ����iԪ��\n");
	 printf("6.�˳�\n");
	 scanf(" %d",&i);
     return i;
}


void menu2(SqList &L){

	int i=0,x=0,chack=0,result=0;
	ElemType e;

   	    while(chack!=6){
              chack=menu1();//ѡ����
			  result=0;
	     	switch(chack){
	    	    case 1:
				    printf("��������Ҫ�����Ԫ��");                 
				    scanf(" %d",&x);
                    printf("��������Ҫ�����λ��");
			        scanf(" %d",&i);
					if(L.length>=MaxSize){
                        printf("˳�������\n");
						break;
					}
				    InsElem(L,x,i);			//������ĩβ����Ԫ��i
			        break;
				case 2:
                    DispList(L);//1.�������
			        break;
				case 3:	
					printf("��������Ҫ��ȡ�ĵ�i��Ԫ��:\n");
					scanf(" %d",&i);
                    result=GetElem(L,i,e);//2.��ȡ��i��Ԫ��
					if(result==1){
                    printf("  ��%d��Ԫ��:%d\n",i,e);
					}else
                       printf("  ��%d��Ԫ�ز�����\n",i);   
			        break;
				case 4:  
					printf("������Ҫ���ҵ�xԪ��:\n");
					scanf("  %d",&e);
					result=Locate(L,e);
					if(result!=0){
                    	printf("  Ԫ��%d�ǵ�%d��Ԫ��\n",e,Locate(L,e),result);	//3.���ҵ�һ��xԪ�ص�λ��
					}else
                        	printf("  Ԫ��%d������\n",e);	//3.���ҵ�һ��xԪ�ص�λ��
			        break;
				case 5: 
                    printf("��������Ҫ ɾ����i��Ԫ��:\n");
				    scanf(" %d",&i);
					result=DelElem(L,i);
					if(result==1){
					printf("  ɾ����%d��Ԫ��\n",i);//4.ɾ����i��Ԫ��
					}else
                            printf("  ��%d��Ԫ�ز�����\n",i);   
			        break;
				case 6: 
					printf("����L\n");
					DestroyList(L);
					return;
				default:printf("�޸�ѡ��\n");
			   }
			 }
}
int main()                       //������
{	int i=0;
    int chack=0;
	int x=0;
	ElemType e;
   
	SqList L;
	int a[]={2,5,4,1,9};
    int n=sizeof(a)/sizeof(a[0]);
     
	while(chack!=3){
		chack=menu();//ѡ�񴴽�˳���ķ�ʽ
		switch(chack){
        case 1:
			   InitList(L);			//��ʼ��˳���L
               printf("������Ҫ������ٸ���Ԫ��:\n");
			   scanf(" %d",&x);   
			   if(x>MaxSize){
				   printf("����˳�����%d\n",MaxSize);
				  break;
			   }
			   else{
				   printf("������Ҫ�����Ԫ��:\n");
			  
			       for(i=1;i<=x;i++){
				
					scanf(" %d",&e);
                    InsElem(L,e,i);			//����Ԫ��1
				  }
			      menu2(L);
			      return(0);//ֱ���˳�
			   }
		       break;
		case 2:
               printf("  ���崴��L\n");
               CreateList(L,a,n);
			   menu2(L);
               return(0);//ֱ���˳�
		default:printf("�޸�ѡ\n");
		}
   	}
}

