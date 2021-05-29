#include <stdio.h>
#define MAXSIZE 9 /* 存储空间初始分配量 */
#define MAX_VERTEX_NUM 20
#define INFINITY 32768
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef char VertexData;    //假设顶点数据为字符型
typedef int adjNode;
typedef int Bool;
Bool visited[MAX_VERTEX_NUM];

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Elemtype;

typedef struct 
{
    VertexData vertex[MAX_VERTEX_NUM];
    adjNode adj[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum,edgenum;
}AdjMatrix; //存储方式为邻接矩阵

typedef struct{
    Elemtype data[MAXSIZE];
    int front;
    int rear;
}Queue;

Status InitQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

Status QueueEmpty(Queue Q)
{
    if(Q.front == Q.rear)
        return TRUE;
    else
    {
        return FALSE;
    }  
}

Status EnQueue(Queue *Q,Elemtype e)
{
    if((Q->rear+1)%MAXSIZE == Q->front)
        return ERROR;
    Q->data[Q->rear]=e;
    Q->rear = (Q->rear+1)%MAXSIZE;
    return OK;
}

Status DeQueue(Queue *Q,int *e)
{
    if(Q->front == Q->rear)
        return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;

    return OK;
}

void CreateGraph(AdjMatrix *G)
{
    int i,j,k;
//——————————————————————————输入确定值——————————————————————————————
    // printf("输入顶点数和边数:\n");
    // scanf("%d,%d",&G->edgenum,&G->vexnum); 

    // printf("输入顶点:\n");
    // for(i=0;i<G->vexnum;i++)
    // {
    //     scanf("%c",&G->vertex[i]);  //初始化顶点
    //     while (getchar()!='\n')
    //     {
    //         continue;
    //     }
        
    // }

//_________________________________________________________________


//————————————————————————————测试数据1 p1——————————————————————————
    G->vexnum=9;
    G->edgenum=15;
    char vi = 'A';
    for(i=0;i<G->vexnum;i++)
    {
        G->vertex[i]=(vi++);
    }
//_______________________________________________________________e



//————————————————————————————测试数据2 p1——————————————————————————
    // G->vexnum=4;
    // G->edgenum=5;
    // char vi = '0';
    // for(i=0;i<G->vexnum;i++)
    // {
    //     G->vertex[i]=(vi++);
    // }
//_______________________________________________________________e
    for(i=0;i<G->vexnum;i++)        //初始化邻接矩阵
     {   for(j=0;j<G->edgenum;j++)
        {
            G->adj[i][j] = INFINITY;
        }
    }

//____________________________测试数据1 p2_____________________________________

   	G->adj[0][1]=1;
	G->adj[0][5]=1;

	G->adj[1][2]=1; 
	G->adj[1][8]=1; 
	G->adj[1][6]=1; 
	
	G->adj[2][3]=1; 
	G->adj[2][8]=1; 
	
	G->adj[3][4]=1;
	G->adj[3][7]=1;
	G->adj[3][6]=1;
	G->adj[3][8]=1;

	G->adj[4][5]=1;
	G->adj[4][7]=1;

	G->adj[5][6]=1; 
	
	G->adj[6][7]=1; 

//_____________________________________________________________________________e


//————————————————————————————测试数据2 p2——————————————————————————
    // G->adj[0][1]=1;
    // G->adj[0][2]=1;
    // G->adj[0][3]=1;

    // G->adj[1][2]=1;

    // G->adj[3][2]=1;

//_______________________________________________________________e

    for(i=0;i<G->vexnum;i++) //确定边的两个结点及权值，领接矩阵内有几个边就有几个值
    {
        // printf("输入vi与vj的下标i,j");
        // scanf("%d %d",&i,&j);
        for(j=0;j<G->vexnum;j++)
        {
           G->adj[j][i]=G->adj[i][j]; //无向图中矩阵对称
        }
  
    }

    printf("初始化完毕。矩阵为：\n");
    //打印行属性
    printf("%c",' ');
    for(i=0;i<G->vexnum;i++)
    {
        printf("%10c", G->vertex[i]);
    }
    printf("\n");

    for(i=0;i<G->vexnum;i++)
    {
        printf("%c ", G->vertex[i]);    //打印列属性
        for(j=0;j<G->vexnum;j++)
        {
            printf("%10d",G->adj[i][j]);
        }
        printf("\n");
    }

}
void DFS(AdjMatrix G,int i)
{
    int j;
    visited[i]=TRUE;
    printf("%c ",G.vertex[i]);
    for(j=0;j<G.vexnum;j++)
    {
        if(G.adj[i][j]==1 && !visited[j])
        {
            DFS(G,j);
        }
    }

}
void DFSTraverse(AdjMatrix G)
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        visited[i]=FALSE;
    }
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
            DFS(G,i);
    }
}




void BFSTraverse(AdjMatrix G)
{
    int i,j;
    Queue Q;
    for(i=0;i<G.vexnum;i++)
    {
        visited[i]=FALSE;
    }
    InitQueue(&Q);
    
   for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            visited[i]=TRUE;
            printf("%c ",G.vertex[i]);
            EnQueue(&Q,i);
            while(!QueueEmpty(Q))    
            {
                DeQueue(&Q,&i);   
                /*上一个节点附近的节点都遍历完后，取上一次遍历的节点中最先遍历的节点开始新的遍历 
                (如大话p242，A周边遍历完，BF入栈，先取B遍历使CIG入栈，后取F遍历使E入栈)*/
                for(j=0;j<G.vexnum;j++)
                {
                    if(G.adj[i][j]==1 && !visited[j])
                    {
                        visited[j]=TRUE;
                        printf("%c ",G.vertex[j]);
                        EnQueue(&Q,j);    //将遍历的节点入栈，供之后遍历使用
                    }
                }

            }
           
        }
    }

}

int main()
{
    AdjMatrix G;
    CreateGraph(&G);
    printf("深度搜索:\n");
    DFSTraverse(G);
    printf("\n");
    printf("广度搜索:\n");
    BFSTraverse(G);
    return 0;
}


