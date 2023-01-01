#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct tnode
{	ElemType data;					//������
	struct tnode *lchild,*rchild;	//ָ����
} BTNode;							//�������������
void CreateBTree(BTNode * &bt,char *str)	//�����ű�ʾ������������
{	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;
	char ch;
	bt=NULL;			//�����Ķ�������ʼʱΪ��
	ch=str[j];
	while (ch!='\0')	//strδɨ����ʱѭ��
	{	switch(ch)
		{
		case '(':top++;St[top]=p;k=1; break;	//Ϊ���ӽ��
		case ')':top--;break;
		case ',':k=2; break;					//Ϊ�Һ��ӽ��
		default:p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (bt==NULL)					//*pΪ�������ĸ����
					bt=p;
				else							//�ѽ��������������
				{	switch(k) 
					{
					case 1:St[top]->lchild=p;break;
					case 2:St[top]->rchild=p;break;
					}
				}
		}
		j++;
		ch=str[j];
	}
}
void DestroyBTree(BTNode *&bt)		//���ٶ�����
{	if (bt!=NULL)
	{	DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		free(bt);
	}
}
void DispBTree(BTNode *bt)			//��������������ű�ʾ��
{	if (bt!=NULL)
	{	printf("%c",bt->data);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	printf("(");			//������ʱ����'('
			DispBTree(bt->lchild);	//�ݹ鴦��������
			if (bt->rchild!=NULL)	//��������ʱ����'.'
				printf(",");
			DispBTree(bt->rchild);	//�ݹ鴦��������
			printf(")");			//���������ϣ�������һ��')'
		}
	}
}
void PreOrder(BTNode *bt)		//��������㷨
{	if(bt!=NULL)
    {
    	printf("%c",bt->rchild);
    	PreOrder(bt->lchild);
    	PreOrder(bt->rchild);
	 } 
}

void InOrder(BTNode *bt)		//��������㷨
{	if(bt!=NULL)
    {
    	InOrder(bt->lchild);
    	printf("%c",bt->rchild);
    	InOrder(bt->rchild);
	 } 
}
void PostOrder(BTNode *bt)		//��������㷨
 {	if(bt!=NULL)
    {
    	PostOrder(bt->lchild);
    	PostOrder(bt->rchild);
    	printf("%c",bt->rchild);
	 } 
}
int main()                 //������
{
	BTNode *bt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(I)))");		//���������
	printf("������bt:");DispBTree(bt);printf("\n");
	printf("�����������:");PreOrder(bt);printf("\n");
	printf("�����������:");InOrder(bt);printf("\n");
	printf("�����������:");PostOrder(bt);printf("\n");
	DestroyBTree(bt);
}

