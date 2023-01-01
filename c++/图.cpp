#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 10 //ͼ����󶥵����
#define INF 32767 //��ʾ��
typedef char VertexType[10]; //����VertexTypeΪ�ַ�������
typedef struct vertex
{ int adjvex; //������
VertexType data; //�������Ϣ
} VType; //��������
typedef struct graph
{ int n,e; //nΪʵ�ʶ�����,eΪʵ�ʱ���
VType vexs[MAXVEX]; //���㼯��
int edges[MAXVEX][MAXVEX]; //�ߵļ���
} MatGraph; //ͼ���ڽӾ�������
void CreateGraph(MatGraph &g,int A[][MAXVEX],int n,int e)
//���ڽӾ�������A��������n�ͱ���e����ͼG���ڽӾ���洢�ṹ
{
int i,j;
char * str; 
str=(char*)malloc(10*sizeof(char)); 
g.n=n; g.e=e;
printf("\n ���붥�����Ϣ�����ͣ���");
for (i=0; i<n; i++ )
{ 
printf("\n��%d�����㣺 ",(i+1) );
scanf("%s",str);
g.vexs[i].adjvex=i+1;
strcpy(g.vexs[i].data,str);
}
for (i=0;i<n;i++)
for (j=0;j<n;j++)
g.edges[i][j]=A[i][j];
}
void DestroyGraph(MatGraph g) //����ͼ
{
}
void DispGraph(MatGraph g) //��ʾͼG�Ľṹ
{
int i,j;
for (i=0;i<g.n;i++)
{
for (j=0;j<g.n;j++)
if (g.edges[i][j]<INF)
printf("%4d",g.edges[i][j]);
else
printf("%4s","��");
printf("\n");
}
}
int Degree(MatGraph g,int i) //������ͼG�е�i������Ķ�
{
int j,d=0,v=i-1;
if (v<0 || v>=g.n)
return -1; //�����Ŵ��󷵻�-1
for (j=0;j<g.n;j++)
if (g.edges[v][j]>0 && g.edges[v][j]<INF)
d++; //ͳ�Ƶ�v�мȲ�Ϊ0Ҳ��Ϊ�޵ı�������
return d;
}
int SearchVexs(MatGraph &g,char *v){ //��ѯ����v�Ƿ���ͼg�д��ڣ�������ڣ����ظö����ڶ��������е��±꣬��������ڷ���-1
int i;
for (i=0; i<g.n; i++ )
{ if(strcmp(g.vexs [i].data,v)==0)
break;
}
if(i==g.n)
return -1;
else 
return i;
}
void InserdEdge(MatGraph &g,char *v1,char *v2,int w){ //������v1,v2���ڣ�������Զ���֮�����һ��ȨֵΪw�������
//���ú����еĴ��벹��
int i,j;
i=SearchVexs(g,v1);
j=SearchVexs(g,v2);
if(i==-1||j==-1)
{
printf("error.\n");
return;
}
g.edges[i][j]=g.edges[j][i]=w;
g.e++;
}
void DeletedEdge(MatGraph &g,char *v1,char *v2){ //������v1,v2���ڲ��Ҵ���һ������ߣ���ɾ����Զ���֮��������
//���ú����еĴ��벹��
int i,j;
i=SearchVexs(g,v1);
j=SearchVexs(g,v2);
if(i==-1||j==-1)
{
printf("error.\n");
return ;
}
if(g.edges[i][j]==INF)
g.e--;
}
void InserdVexs (MatGraph &g,char *v){ //������ͼg�в���һ���¶���v
//���ú����еĴ��벹��
int i,n;
g.n=g.n+1;
n=g.n;
g.vexs[n-1].adjvex=n;
strcpy(g.vexs[n-1].data,v);
for(i=0;i<n;i++)
g.edges[n-1][i]=g.edges[i][n-1]=INF;
}
int main() //������
{
MatGraph g;
int A[][MAXVEX]={
{INF, 2, 5, 3, INF,INF,INF},
{2, INF, 2, INF,INF, 8, INF},
{5,2,INF, 1, 3, 5, INF},
{3,INF,1,INF, 5, INF,INF},
{INF,INF,3,5, INF, 3, 9},
{INF,8,5,INF,3,INF, 5},
{INF,INF,INF,INF,9,5,INF}}; 
int n=7,e=12;
CreateGraph(g,A,n,e); //����ͼ���ڽӾ���
printf("ͼG�Ĵ洢�ṹ:\n"); DispGraph(g);
printf("ͼG�����ж���Ķ�:\n"); 
printf(" ����\t��\n");
for (int i=0;i<g.n;i++)
printf(" %s\t%d\n",g.vexs[i].data,Degree(g,i+1));
printf("��a���e��֮���һ������Ϊ5�ıߣ�\n");
InserdEdge(g,"a","e",5);
DispGraph(g);
printf("������ı�ɾ��");
DeletedEdge(g,"a","e");
DispGraph(g);
printf("������ͼ�в���һ���¶���h:\n");
InserdVexs(g,"h");
DispGraph(g);
printf("����ͼ\n");
DestroyGraph(g);
return 0;
}


