#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 10 //图中最大顶点个数
#define INF 32767 //表示∞
typedef char VertexType[10]; //定义VertexType为字符串类型
typedef struct vertex
{ int adjvex; //顶点编号
VertexType data; //顶点的信息
} VType; //顶点类型
typedef struct graph
{ int n,e; //n为实际顶点数,e为实际边数
VType vexs[MAXVEX]; //顶点集合
int edges[MAXVEX][MAXVEX]; //边的集合
} MatGraph; //图的邻接矩阵类型
void CreateGraph(MatGraph &g,int A[][MAXVEX],int n,int e)
//由邻接矩阵数组A、顶点数n和边数e建立图G的邻接矩阵存储结构
{
int i,j;
char * str; 
str=(char*)malloc(10*sizeof(char)); 
g.n=n; g.e=e;
printf("\n 输入顶点的信息（整型）：");
for (i=0; i<n; i++ )
{ 
printf("\n第%d个顶点： ",(i+1) );
scanf("%s",str);
g.vexs[i].adjvex=i+1;
strcpy(g.vexs[i].data,str);
}
for (i=0;i<n;i++)
for (j=0;j<n;j++)
g.edges[i][j]=A[i][j];
}
void DestroyGraph(MatGraph g) //销毁图
{
}
void DispGraph(MatGraph g) //显示图G的结构
{
int i,j;
for (i=0;i<g.n;i++)
{
for (j=0;j<g.n;j++)
if (g.edges[i][j]<INF)
printf("%4d",g.edges[i][j]);
else
printf("%4s","∞");
printf("\n");
}
}
int Degree(MatGraph g,int i) //求无向图G中第i个顶点的度
{
int j,d=0,v=i-1;
if (v<0 || v>=g.n)
return -1; //顶点编号错误返回-1
for (j=0;j<g.n;j++)
if (g.edges[v][j]>0 && g.edges[v][j]<INF)
d++; //统计第v行既不为0也不为∞的边数即度
return d;
}
int SearchVexs(MatGraph &g,char *v){ //查询顶点v是否在图g中存在，如果存在，返回该顶点在顶点数组中的下标，如果不存在返回-1
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
void InserdEdge(MatGraph &g,char *v1,char *v2,int w){ //若顶点v1,v2存在，则在这对顶点之间插入一条权值为w的无向边
//将该函数中的代码补齐
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
void DeletedEdge(MatGraph &g,char *v1,char *v2){ //若顶点v1,v2存在并且存在一条无向边，则删除这对顶点之间的无向边
//将该函数中的代码补齐
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
void InserdVexs (MatGraph &g,char *v){ //在无向图g中插入一个新顶点v
//将该函数中的代码补齐
int i,n;
g.n=g.n+1;
n=g.n;
g.vexs[n-1].adjvex=n;
strcpy(g.vexs[n-1].data,v);
for(i=0;i<n;i++)
g.edges[n-1][i]=g.edges[i][n-1]=INF;
}
int main() //主函数
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
CreateGraph(g,A,n,e); //建立图的邻接矩阵
printf("图G的存储结构:\n"); DispGraph(g);
printf("图G中所有顶点的度:\n"); 
printf(" 顶点\t度\n");
for (int i=0;i<g.n;i++)
printf(" %s\t%d\n",g.vexs[i].data,Degree(g,i+1));
printf("在a点和e点之间加一条长度为5的边：\n");
InserdEdge(g,"a","e",5);
DispGraph(g);
printf("将加入的边删除");
DeletedEdge(g,"a","e");
DispGraph(g);
printf("在无向图中插入一个新顶点h:\n");
InserdVexs(g,"h");
DispGraph(g);
printf("销毁图\n");
DestroyGraph(g);
return 0;
}


