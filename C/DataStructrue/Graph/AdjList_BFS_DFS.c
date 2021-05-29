#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 9 /* 存储空间初始分配量 */
#define MAX_VERTEX_NUM 20
#define INFINITY 32768
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef char VertexType;
typedef char VertexData;    //假设顶点数据为字符型
typedef int adjNode;
typedef int Bool;
Bool visited[9];

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
typedef struct EdgeNode
{
    int adjvex;
    int weight;    //边的权值
    struct EdgeNode * next;

}EdgeNode;

typedef struct VertexNode
{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList adjList;
    int vernum,edgenum;
}*GraphAdjList,graphAdjList;

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
// _______________________________________________________________e



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
            if(G->adj[j][i]>G->adj[i][j])
                G->adj[j][i]=G->adj[i][j]; //无向图中矩阵对称
            else
            {
               G->adj[i][j]= G->adj[j][i]; 
            }
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
void CreateALGraph(AdjMatrix G,GraphAdjList *GL) //利用邻接矩阵制造邻接表
{
    int i,j,c;
    EdgeNode *e;
    EdgeNode *p;

    *GL = (GraphAdjList)malloc(sizeof(graphAdjList));
    (*GL)->vernum = G.vexnum;
    (*GL)->edgenum = G.edgenum;

    // printf("input the number of vertexs and edges:");
    // scanf("%d,%d",&GL->vernum,&GL->edgenum);
    // while(getchar()!='\n')
    //     continue;
  
    for (i = 0; i < (*GL)->vernum; i++)
    {
        // printf("input the data of vertex:");
        // scanf("%c",&G->adjList[i].data);
        // while(getchar()!='\n')
        //     continue;
        (*GL)->adjList[i].data = G.vertex[i];
        (*GL)->adjList[i].firstedge=NULL;
    }

    for(i=0;i<G.vexnum;i++)
    {
        c=0;
        p->next=NULL;//去除野指针
        for(j=0;j<G.vexnum;j++)
        {
           if(G.adj[i][j]==1)
           {
                c++;
                e = (EdgeNode *)malloc(sizeof(EdgeNode));
                e->adjvex = j;
                if(c==1)
                {
                    (*GL)->adjList[i].firstedge = e;            
                }
                else
                {
                    p->next=e;        
                }
                p=e;
              
              
             
           }
       
        }
    }
    p->next=NULL; //去除野指针
    printf("初始化完毕。邻接表为：\n");
    for(i=0;i<G.vexnum;i++)
    {         
        p=(*GL)->adjList[i].firstedge;
        printf("【 %c | 】-->",(*GL)->adjList[p->adjvex].data);
        while(p)
        {            
            printf("[%d |  ]",p->adjvex);
            if(p->next)
                printf("-->");
            p = p->next;
        }
        printf("\n");  
    
    }

}

void DFS(GraphAdjList GL,int i)
{
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c ",GL->adjList[i].data);
    p = GL->adjList[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])
            DFS(GL,p->adjvex);
        p = p->next;
    }


}

void DFSTraverse(GraphAdjList GL)
{
    int i;
    for(i=0;i<GL->vernum;i++)   //初始化所有节点未访问状态
        visited[i] = FALSE;
    for(i=0;i<GL->vernum;i++)
        if(!visited[i])
            DFS(GL,i);
}

/* 邻接表的广度遍历算法 */
void BFSTraverse(GraphAdjList GL)
{
	int i;
    EdgeNode *p;
	Queue Q;
	for(i = 0; i < GL->vernum; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);
   	for(i = 0; i < GL->vernum; i++)
   	{
		if (!visited[i])
		{
			visited[i]=TRUE;
			printf("%c ",GL->adjList[i].data);/* 打印顶点,也可以其它操作 */
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;	/* 找到当前顶点的边表链表头指针 */
				while(p)
				{
					if(!visited[p->adjvex])	/* 若此顶点未被访问 */
 					{
 						visited[p->adjvex]=TRUE;
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);	/* 将此顶点入队列 */
					}
					p = p->next;	/* 指针指向下一个邻接点 */
				}
			}
		}
	}
}
int main()
{
    GraphAdjList GL;
    AdjMatrix G;
    CreateGraph(&G);
    CreateALGraph(G,&GL);
  	printf("\n深度遍历:");
	DFSTraverse(GL);
	printf("\n广度遍历:");
	BFSTraverse(GL);
    return 0;
}

//累计用时上午2节课4h+下午实验课+课外时间 = 8h
//难点：复习链表头插法，野指针消除，原理学习
