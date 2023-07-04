#include <stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct node{
    int data;
    struct node *next;
}NODE;
void list_end(NODE *&L)
{
    L=(NODE*)malloc(sizeof (NODE));

    NODE *p,*r=L;
    L->next=NULL;
    int x;
    scanf("%d",&x);
    while(x!=999)
    {
        p=(NODE*) malloc(sizeof (NODE));
        p->data=x;
        r->next=p;
        r=p;
        scanf("%d",&x);
    }
    p->next=NULL;
}
void both(NODE *L,NODE* L2)
{
    NODE *p=L,*q=L;

    while(p->next)
    {
        q=q->next;
        p=p->next;
        if(p->next==NULL)
        {
            break;
        }
        p=p->next;
    }
    L2->next=q->next;
    q->next=NULL;
}
void print(NODE* L)
{
    L=L->next;
    while(L)
    {
        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
}
void nizhuan(NODE* L2)
{
    NODE *p,*q,*r;
    p=L2->next;
    q=L2->next->next;
    r=L2->next->next->next;
    L2->next->next=NULL;
    while(r)
    {
        q->next=p;
        p=q;
        q=r;
        r=r->next;
    }
    q->next=p;
    L2->next=q;
}
void add(NODE *L,NODE *L2)
{
    NODE *p,*q,*r;
    p=L->next;
    q=L->next;
    r=L2->next;
    while (r->next)
    {
        p=p->next;
        q->next=r;
        q=r;
        r=r->next;
        q->next=p;
        q=p;
    }
    if(r!=NULL)
    {
        p=p->next;
        q->next=r;
        r->next=p;
    }
}
int main() {
    NODE *L,*L2;
    L2=(NODE*) malloc(sizeof (NODE));
    list_end(L);
    print(L);
    both(L,L2);
    print(L);
    print(L2);
    nizhuan(L2);
    print(L2);
    add(L,L2);
    print(L);
    return 0;
}
