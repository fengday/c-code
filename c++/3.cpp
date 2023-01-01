#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include<fstream>

using namespace std;

#define null 0
#define max_course_num  100  //���γ�����  
class cid{
	char c[3];
};//�γ̺� 

typedef struct Course{
	cid id[3];//�γ̺� 
	char name[20];//�γ��� 
	
}Course; //�γ�

typedef struct PreCourse{
	int a;//�γ��������е��±� 
	struct PreCourse *nextarc;//ָ����һ���޵Ŀγ̽ڵ� 
}PreCourse; //���޿� 

typedef struct{
	Course course; 
	PreCourse *firstarc;// ָ���һ�������ö���Ļ���ָ�� 
}CourseNode;//�γ̽ڵ� 

typedef struct{
	CourseNode courses[max_course_num];//�ڽӱ� 
	int xqs;
	int num;
}AlGraph;//�γ�����ͼ 

typedef struct{
	int data[max_course_num];
	int f,r;
}queue;//���� 

int whethercricle=0;//����
int jxq;
//���� 
class Queue{
	public:
		void queue_init(queue *q);
		void queue_in(queue *q,int x);
		int queue_out(queue *q);
		int queue_empty(queue *q);
}Queue;
void Queue::queue_init(queue *q){//�ӳ�ʼ�� 
	q->f=q->r=0;
}
void Queue::queue_in(queue *q,int x){//��� 
	if((q->r+1)%max_course_num==q->f){
		cout<<"����\t"<<endl;
		exit(0);
	}
	q->r=(q->r+1)%max_course_num;
	q->data[q->r]=x;
} 
int Queue::queue_out(queue *q){//���� 
	if(q->f==q->r){
		cout<<"�ӿ�\t"<<endl;
		exit(0);
	}
	q->f=(q->f+1)%max_course_num;
	return q->data[q->f];
}
int Queue::queue_empty(queue *q){//���п� 
	if(q->f==q->r)return 1;
	else return 0;
}
//ͼ 
class Graph{
	public:
		AlGraph input();
		void output(AlGraph CGraph);
		void creatpre(AlGraph *CGraph);
}Graph;
void Graph::creatpre(AlGraph *CGraph){//���޹�ϵ
    system("cls");
	int choice;
	int i,n;
	int j;
	PreCourse *p,*q;
	cout<<endl<<"����γ̺ŵı�ţ�\t"<<endl;
	for(i=0;i<CGraph->num;i++){
		if(i%4==0)cout<<endl;
		cout<<"("<<i+1<<")";//����γ̵ı�� 
		printf("%s\t",CGraph->courses[i].course.id);	
	} 
	cout<<endl;
	cout<<"\n����ÿ�ſγ����޿γ̺ŵı�ţ�����0��ʾû�л��߽�������\t"<<endl;
	for(i=0;i<CGraph->num;i++){
		printf("%s�����޿γ̣�",CGraph->courses[i].course.id);
		cin>>j;
		n=0;
		while(j){//�ж�����γ̱���Ƿ���ȷ 
		    while(j<1||j>CGraph->num||j==i+1){
		    	if(j==i+1)cout<<"���޿γ̺�����\n";
				else cout<<"��������޿γ̺Ų��ڿγ̼ƻ���"<<endl;
				cout<<"���������룺";
				cin>>j;
		    }
			p=(PreCourse *)malloc(sizeof(PreCourse));//malloc�Ƕ�̬��������ڴ�ռ�ķ�����
                                                    //���Ը�����Ҫ�����ڴ�ռ������ʹ��
                                                   //(char*)malloc(sizeof(char)*20)����˼�ǣ���̬����ռ�Ϊ20��char�����ݴ�С�Ŀռ䡣
                                                  //���ҽ����ص�ָ������ǿ��ת����char��ָ�롣
			p->a=j-1;                                
			p->nextarc=null;                         
			if(n==0){
				CGraph->courses[i].firstarc=p;
				q=CGraph->courses[i].firstarc;
				n++;
			}
			else{
				q->nextarc=p;
				q=p;
				n++;
			}	
	        cin>>j;	
		}
	}
	system("pause");
	cout<<"(1)���½������޹�ϵ\t"<<"(2)ȷ��\n";
	cout<<"��ѡ��";
	cin>>choice;
	if(choice==1)creatpre(CGraph);
	jxq=0; 
}
//���� 
AlGraph Graph::input(){//���벢�����γ�ͼ 
	AlGraph CGraph;
	int xqzs=0,kczs=0;//xqzsΪ��ѧ������kczxΪ�ܿγ��� 
	int i;
	int choice;
	cout<<"��ѧ�ƻ�:\n"<<endl;
	cout<<"(1).ѧ��������\n";
	cin>>xqzs;
	CGraph.xqs=xqzs;
	cout<<"(2).������γ�����\n";
	cin>>kczs;
	CGraph.num=kczs;
	cout<<"(3).ÿ�ſογ̺źͿγ�����\n"<<endl;
	for(i=0;i<kczs;i++){//����γ̺ţ��γ�����ѧ�� 
		cout<<"�γ̺ţ�";
		scanf("%s",CGraph.courses[i].course.id);
		cout<<"�γ�����";
		scanf("%s",CGraph.courses[i].course.name);
		cout<<endl;
		CGraph.courses[i].firstarc=null;
	}
	cout<<"1.��������\t"<<"2.ȷ��"<<endl;
	cout<<"��ѡ��";
	cin>>choice;
	if(choice==1){
		system("cls");
		input();
	}
	else{
		creatpre(&CGraph);//�������޹�ϵ
		return CGraph; 
	}
}
//��� 
void Graph::output(AlGraph CGraph){//������޹�ϵ 
	int i,j,n;
	PreCourse *p;
	cout<<"�γ̱��\t"<<"�γ�����\t"<<"���޿�"<<endl;
	for(i=0;i<CGraph.num;i++){
		printf("%s\t\t%s\t\t",CGraph.courses[i].course.id,CGraph.courses[i].course.name);
		j=0;
		p=CGraph.courses[i].firstarc;
		while(p){
			n=p->a;
			printf(" %s  ",CGraph.courses[n].course.id);
			p=p->nextarc;
			j++;
		}
		if(j==0)cout<<"��";
		cout<<endl;
	} 
	system("pause");
} 
//�ж� 
class Judgement{  //�ж��� 
	public:
		void findindegree(AlGraph *CGraph,int indegree[]);
		void judgingcricle(AlGraph *CGraph,queue *q2);
}Judgement;

//
void Judgement::findindegree(AlGraph *CGraph,int indegree[]){
	int i;
	PreCourse *p;
	for(i=0;i<CGraph->num;i++){
		indegree[i]=0;
		p=CGraph->courses[i].firstarc;
		while(p){
			indegree[i]++;
			p=p->nextarc;
		}
	}
}
void Judgement::judgingcricle(AlGraph *CGraph,queue *q2){//�ж��Ƿ��л��Ϳγ���� 
	int indegree[max_course_num];//���
	int i,m,j,pd=0;
	float xf=0;
	PreCourse *p;
	queue q;
    Queue.queue_init(&q);//�ӳ�ʼ�� 
	findindegree(CGraph,indegree);//�����
	for(i=0;i<CGraph->num;i++){
	    if(indegree[i]==0){
		   Queue.queue_in(&q,i);              //���Ϊ0�ĵ���ջ 
		   indegree[i]--;
	    } 
    }
    m=0;
    Queue.queue_in(&q,-1);//-1����ж�
	jxq++;
	while(1){                                          
		i=Queue.queue_out(&q);             //��ջ�ǿգ�ȡ��ջ������a������ö���ֵ 
		Queue.queue_in(q2,i);
		if(i!=-1){                         //ɾȥ�ö��� 
			m++; 
			for(j=0;j<CGraph->num;j++)     //ɾȥ����a�ĳ���
			if(j!=i){
				if(indegree[j]==0){          
					Queue.queue_in(&q,j);
					indegree[j]--;
				}
				else{                            
					p=CGraph->courses[j].firstarc;
					while(p){
						if(p->a==i){
							indegree[j]--;
							if(indegree[j]==0){         //���ߵ���һ�������Ϊ0������ջ
								Queue.queue_in(&q,j);
								indegree[j]--;
								pd=1;
							}
						}
						p=p->nextarc;
					} 
				}
			}
		}
		else{
			if(pd){
				pd=0;
				Queue.queue_in(&q,-1);
				jxq++;
			}
			else break;
		}
	} 
	if(m<CGraph->num){            //��ͼ�����ж��㣬��ͼ���л� 
		cout<<"�γ����޿��д���ѭ�����γ̰���ʧ�ܣ�"<<endl;
		whethercricle=1;
	}
	Queue.queue_in(q2,-1);
}
//�ſη��� 
class Edit{
	public:
		void layout1(AlGraph *CGraph,queue *q);
}Edit;

//������� 
void Edit::layout(AlGraph*CGraph,queue *q){
	FILE *bp;
	bp=fopen("courseplan.txt","w");
	int i,j,k,xq=1,ck[20];
	float xf;
	float m=CGraph->num/CGraph->xqs*1.0f;
	queue q1=*q;
	int n;
	int x;
	n=0;
	ck[0]=-1;
	for(i=0;i<20;i++){
		j=Queue.queue_out(&q1);
		ck[i]=j;
		if(j==-1)i--;
		if((Queue.queue_empty(&q1)))break;
	}
	cout<<"\n�γ̰���Ϊ��"<<endl;
	fprintf(bp,"%s","\n�γ̰���Ϊ��\n");
	for(x=0;x<CGraph->xqs;x++){
		if(ck[0]!=-1){
			fprintf(bp,"%s","\n��");
	        fprintf(bp,"%d",xq);
	        fprintf(bp,"%s","ѧ�ڿγ̰���Ϊ��\n") ;
			cout<<"\n��"<<xq++<<"ѧ�ڿγ̰���Ϊ��\n";
			for(i=0;i<m;i++){
				k=ck[n];
				printf("%s  ",CGraph->courses[k].course.name);
				fprintf(bp," %s  ",CGraph->courses[k].course.name);
				n++;
			}
		}
	}
}

