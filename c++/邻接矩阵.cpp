#define MaxInt 32767                    	//��ʾ����ֵ������
#define MVNum 100                       	//��󶥵��� 
typedef char VerTexType;              	//���趥�����������Ϊ�ַ��� 
typedef int ArcType;                  	//����ߵ�Ȩֵ����Ϊ���� 
typedef struct{ 
  VerTexType vexs[MVNum];            		//����� 
  ArcType arcs[MVNum][MVNum];      		//�ڽӾ��� 
  int vexnum,arcnum;                		//ͼ�ĵ�ǰ�����ͱ��� 
}AMGraph; 

    int CreateUDN(AMGraph &G){ 
    int i,j,k,v1,v2,w;char cin;
    //�����ڽӾ����ʾ��������������G 
    cin>>G.vexnum>>G.arcnum; 	//�����ܶ��������ܱ��� 
    for(i = 0; i<G.vexnum; ++i)    
      cin>>G.vexs[i];                        	//������������Ϣ 
    for(i = 0; i<G.vexnum;++i) 	//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵ
       for(j = 0; j<G.vexnum;++j)   
         G.arcs[i][j] = MaxInt;   
    for(k = 0; k<G.arcnum;++k){                     //�����ڽӾ��� 
      cin>>v1>>v2>>w;                                 //����һ���������Ķ��㼰Ȩֵ 
      i = LocateVex(G, v1);  j = LocateVex(G, v2);  //ȷ��v1��v2��G�е�λ��
      G.arcs[i][j] = w; //��<v1, v2>��Ȩֵ��Ϊw 
      G.arcs[j][i] = G.arcs[i][j];              //��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw 
   }//for 
   return OK; 
}//CreateUDN 
