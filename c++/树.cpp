#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct tnode
{	ElemType data;					//数据域
	struct tnode *lchild,*rchild;	//指针域
} BTNode;							//二叉链结点类型
void CreateBTree(BTNode * &bt,char *str)	//由括号表示串创建二叉链
{	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;
	char ch;
	bt=NULL;			//建立的二叉树初始时为空
	ch=str[j];
	while (ch!='\0')	//str未扫描完时循环
	{	switch(ch)
		{
		case '(':top++;St[top]=p;k=1; break;	//为左孩子结点
		case ')':top--;break;
		case ',':k=2; break;					//为右孩子结点
		default:p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (bt==NULL)					//*p为二叉树的根结点
					bt=p;
				else							//已建立二叉树根结点
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
void DestroyBTree(BTNode *&bt)		//销毁二叉链
{	if (bt!=NULL)
	{	DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		free(bt);
	}
}
void DispBTree(BTNode *bt)			//输出二叉链的括号表示串
{	if (bt!=NULL)
	{	printf("%c",bt->data);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	printf("(");			//有子树时输入'('
			DispBTree(bt->lchild);	//递归处理左子树
			if (bt->rchild!=NULL)	//有右子树时输入'.'
				printf(",");
			DispBTree(bt->rchild);	//递归处理右子树
			printf(")");			//子树输出完毕，再输入一个')'
		}
	}
}
void PreOrder(BTNode *bt)		//先序遍历算法
{	if(bt!=NULL)
    {
    	printf("%c",bt->rchild);
    	PreOrder(bt->lchild);
    	PreOrder(bt->rchild);
	 } 
}

void InOrder(BTNode *bt)		//中序遍历算法
{	if(bt!=NULL)
    {
    	InOrder(bt->lchild);
    	printf("%c",bt->rchild);
    	InOrder(bt->rchild);
	 } 
}
void PostOrder(BTNode *bt)		//后序遍历算法
 {	if(bt!=NULL)
    {
    	PostOrder(bt->lchild);
    	PostOrder(bt->rchild);
    	printf("%c",bt->rchild);
	 } 
}
int main()                 //主函数
{
	BTNode *bt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(I)))");		//构造二叉链
	printf("二叉树bt:");DispBTree(bt);printf("\n");
	printf("先序遍历序列:");PreOrder(bt);printf("\n");
	printf("中序遍历序列:");InOrder(bt);printf("\n");
	printf("后序遍历序列:");PostOrder(bt);printf("\n");
	DestroyBTree(bt);
}

