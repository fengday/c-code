#define MaxInt 32767                    	//表示极大值，即∞
#define MVNum 100                       	//最大顶点数 
typedef char VerTexType;              	//假设顶点的数据类型为字符型 
typedef int ArcType;                  	//假设边的权值类型为整型 
typedef struct{ 
  VerTexType vexs[MVNum];            		//顶点表 
  ArcType arcs[MVNum][MVNum];      		//邻接矩阵 
  int vexnum,arcnum;                		//图的当前点数和边数 
}AMGraph; 

    int CreateUDN(AMGraph &G){ 
    int i,j,k,v1,v2,w;char cin;
    //采用邻接矩阵表示法，创建无向网G 
    cin>>G.vexnum>>G.arcnum; 	//输入总顶点数，总边数 
    for(i = 0; i<G.vexnum; ++i)    
      cin>>G.vexs[i];                        	//依次输入点的信息 
    for(i = 0; i<G.vexnum;++i) 	//初始化邻接矩阵，边的权值均置为极大值
       for(j = 0; j<G.vexnum;++j)   
         G.arcs[i][j] = MaxInt;   
    for(k = 0; k<G.arcnum;++k){                     //构造邻接矩阵 
      cin>>v1>>v2>>w;                                 //输入一条边依附的顶点及权值 
      i = LocateVex(G, v1);  j = LocateVex(G, v2);  //确定v1和v2在G中的位置
      G.arcs[i][j] = w; //边<v1, v2>的权值置为w 
      G.arcs[j][i] = G.arcs[i][j];              //置<v1, v2>的对称边<v2, v1>的权值为w 
   }//for 
   return OK; 
}//CreateUDN 
