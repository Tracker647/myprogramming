#include <stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20
#define INFINITY 32767
#define TRUE 1
#define FALSE 0
typedef char VertexData;
typedef int EdgeNode;

typedef struct{
    VertexData vertex[MAX_VERTEX_NUM];      //点的集合
    EdgeNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //边的集合
    int vexnum,edgenum;
}AdjMatrix;

void CreateGraph(AdjMatrix *G)  //由领接矩阵构建图
{
    int i,j,k,w;
    G->vexnum = 9;
    G->edgenum = 15;

    for(i=0;i<G->vexnum;i++)        //初始化邻接矩阵
    {   
        for(j=0;j<G->vexnum;j++)
        {
            G->arcs[i][j] = INFINITY;
        }
    }
    G->arcs[0][0]=0;
	G->arcs[0][1]=10;
	G->arcs[0][5]=11; 

    G->arcs[1][0]=10; 
    G->arcs[1][1]=0;
	G->arcs[1][2]=18; 
    G->arcs[1][6]=16; 
	G->arcs[1][8]=12; 

	G->arcs[2][2]=0;
    G->arcs[2][3]=22;
    G->arcs[2][8]=8; 

    G->arcs[3][2]=22;
    G->arcs[3][3]=0; 
    G->arcs[3][4]=20; 
	G->arcs[3][7]=16; 
	G->arcs[3][8]=21; 


	G->arcs[4][3]=20;
    G->arcs[4][4]=0; 
    G->arcs[4][5]=26;
    G->arcs[4][7]=7;  

	G->arcs[5][0]=11; 
    G->arcs[5][4]=26;
    G->arcs[5][5]=0;
    G->arcs[5][6]=17;

	G->arcs[6][1]=16;
    G->arcs[6][5]=17;
    G->arcs[6][6]=0; 
    G->arcs[6][7]=19; 

    G->arcs[7][3]=16; 
    G->arcs[7][4]=7; 
    G->arcs[7][6]=19; 
    G->arcs[7][7]=0;

    G->arcs[8][1]=12; 
    G->arcs[8][2]=8; 
    G->arcs[8][3]=21; 
    G->arcs[8][8]=0;

    // printf("input the number of vertex and edgenum:");
    // scanf("%d,%d",&G->vexnum,&G->edgenum);
    // for(i=0;i<G->vexnum;i++)
    // {
    //     scanf("%c",&G->vertex[i]);  //初始化顶点
    //     while (getchar()!='\n')
    //     {
    //         continue;
    //     }
        
    // }
 

    for(k=0;k<G->vexnum;k++)
    {
        // printf("input the order of vi,vj and weight:");
        // scanf("%d %d %d",&i,&j,&w);
        // G->arcss[i][j] = w;
        G->arcs[i][j]=G->arcs[j][i]; //无向图时，使矩阵对称
    }

    for(i=0;i<G->vexnum;i++)        //初始化邻接矩阵
    {   
        for(j=0;j<G->vexnum;j++)
        {
            printf("%10d",G->arcs[i][j]);
        }
        printf("\n");
    }
}

void MiniSpanTree_Prim(AdjMatrix G)
{
    int min,i,j,k;//最小权值，搜索次数，，
    int adjvex[MAX_VERTEX_NUM];
    int lowcost[MAX_VERTEX_NUM];
    lowcost[0] = 0 ;    
    adjvex[0] = 0;

 /*    int vex[MAX_VERTEX_NUM];
    int t; */

  

    for(i=1;i<G.vexnum;i++)
    {
        lowcost[i] = G.arcs[0][i];//初始化：lowcost数组导入v0通向其他顶点的所有权值
        adjvex[i]=0;        //初始化所有顶点都为0(从v0开始)
    }

/* 
    for(i=0;i<G.vexnum;i++)
    {
        vex[i]=i;
    }
    printf("开始于v%d\n",adjvex[0]);
    vex[0]=0;

    printf("候选路径:\n");
    for(i=1;i<G.vexnum;i++)
    {
        if(lowcost[i]!=0 && lowcost[i]!=INFINITY)
            printf("(%d,%d)\n",adjvex[0],i);
    } */

    for(i=1;i<G.vexnum;i++)
    {
        min = INFINITY;
        j=1; k=0;
        for(j=1;j<G.vexnum;j++) //遍历vi通向的所有节点，寻找最小权值
        {
            if(lowcost[j]!=0 && lowcost[j]<min)
            {
                min = lowcost[j];  //找到带最小权值的vj
                k=j;//vk=vj, min,k分别用于保存最小权值和最小权值的下标
            }      
        }
        printf("开路:(%d,%d)\n",adjvex[k],k); //打印最小权值

     /*    //扩展：下次可以用栈来存放不用的候选路径？
        vex[k]=0;

        printf("\n");
        printf("现已占领：\n");
        for(t=0;t<G.vexnum;t++)
        {
            if(vex[t]==0)
            {
                  printf("v%d ",t);
            }      
        }
         printf("\n");
        printf("候选路径:\n");
 */

        lowcost[k]=0; //打印最小权值后将权值设为0，不再采用，防止回溯
        //***对于循环，除了截图对比前后数据，还要时刻结合图形思考
        
        for(j=1;j< G.vexnum;j++)
        {
            /* 遍历vi和vk周边节点，判定条件：vi周边的权值不设0(即不被搜索过)且vk的周边的节点不是vi能够到的
            （即vk周边的节点对于vi则是无限远） */
            if(lowcost[j]!=0 && G.arcs[k][j] < lowcost[j]) 
            {
                lowcost[j] = G.arcs[k][j];  //则开始导入上次最小权值Vk通向的新节点的附近权值
                adjvex[j]=k;    //保存符合条件的(vj,vk）
               /*  printf("(%d,%d)\n",k,j); */
            }
        }


    }
}

int main()
{
    AdjMatrix G;
    int n;
    CreateGraph(&G);
    MiniSpanTree_Prim(G);
}