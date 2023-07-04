#include <stdio.h>
#include<stdlib.h>
#define  ElemType int
#define  MAXSIZE 50
typedef char CHAR;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
void list_insert(LinkList &L)//头插
{
    L=(LinkList) malloc(sizeof (LNode));
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LNode *p;
    while(x!=9999)
    {
        p=(LinkList) malloc(sizeof (LNode));
        p->data=x;
        p->next=L->next;
        L->next=p;
        scanf("%d",&x);
    }
}
void print_list(LinkList L)//打印
{
    L=L->next;
    while(L!=NULL)
    {
        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
}
void list_end_insert(LinkList &L)//尾插
{
    L=(LinkList) malloc(sizeof (LNode));
    ElemType x;
    L->next=NULL;
    LNode *p,*r=L;
    scanf("%d",&x);
    while(x!=9999)
    {
        p=(LinkList) malloc(sizeof (LNode));
        p->data=x;
        r->next=p;
        r=p;
        scanf("%d",&x);
    }
    p->next=NULL;
}
LinkList GetElem(LinkList L,int i)//按位置查找
{
    int j=0;
    if(i<0)
    {
        return NULL;
    }
    while(L&&j<i)
    {
        L=L->next;
        j++;
    }
    return L;
}
LinkList LocatrElem(LinkList L,ElemType x)//按值查找
{
    while(L)
    {
        if(L->data==x)
        {
            return L;
        }
        L=L->next;
    }
    return NULL;
}
bool ListFrontInsert(LinkList L,int i,ElemType x)//按位置插入
{
    LinkList p;
    p=GetElem(L,i-1);
    if(p==NULL)
    {
        return false;
    }
    LinkList q;
    q=(LinkList)malloc(sizeof (LNode));
    q->data=x;
    q->next=p->next;
    p->next=q;
    return true;
}
bool ListDelete(LinkList L,int x)
{
    LinkList p,q;
    p= GetElem(L,x-1);
    q= p->next;
    if(p->next==NULL)
    {
        return false;
    }

    p->next=q->next;
    free(q);
    return true;
}
int main() {
    LinkList L,search;
    list_insert(L);
    print_list(L);
    list_end_insert(L);
    print_list(L);
    search=GetElem(L,1);
    if(search!=NULL)
    {
        printf("%d\n",search->data);
    }
    search=LocatrElem(L,3);
    if(search!=NULL)
    {
        printf("%d\n",search->data);
    }
    bool fail=ListFrontInsert(L,2,99);
    if(fail)
    {
        print_list(L);
    }
    bool dele=ListDelete(L,3);
    if(dele)
    {
        print_list(L);
    }
    return 0;
}
