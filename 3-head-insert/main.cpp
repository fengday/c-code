#include <stdio.h>
#include <stdlib.h>
typedef int EleType;
typedef struct LNode{
    EleType data;//指针域
    struct LNode *next;
}LNode,*LinkList;
//LNode*是结构体指针和LinkList完全等价
void list_head_insert(LinkList &L)
{
    L=(LNode*)malloc(sizeof(LNode));
    EleType x;
    LinkList s;
    scanf("%3d",&x);

    L->next=NULL;//等价
//    s=(LNode*)malloc(sizeof(LNode));
//    s->data=x;
//    s->next=NULL;
//    L->next=s;

    while (x!=999)
    {

        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%3d",&x);
    }
}
void print_list(LNode* L)
{
    L=L->next;
    while (L!=NULL)
    {
        printf("%3d",L->data);
        L=L->next;
    }
}
int main() {
    LinkList L;//  LNode *L; L是表头指针
    list_head_insert(L);
    print_list(L);
    return 0;
}