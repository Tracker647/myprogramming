#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXSIZE 50 /* 存储空间初始分配量 */
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef char String[MAXSIZE];

int index = 1; //将输入的结点信息存放在字符串中
int a=0; //菜单组件

String str;
int StrAssign(String str, char *text) //函数介绍：字符串赋值函数
{
	int i;						//伪码算法：如果字符指针的值不为空，
	if (strlen(text) > MAXSIZE) //取字符指针首地址的长度，由0遍历至该长度给字符串赋值
		return ERROR;
	else
	{
		str[0] = strlen(text);
		for (i = 1; i <= str[0]; i++)
		{
			str[i] = *(text + i - 1);
		}
	}
}

typedef struct Node
{
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
	int depth, width; //宽度和深度，相当于结点的坐标

} BiTNode, *BiTree;

typedef struct TreeInfo //存放关于二叉树的其他信息，用于计算坐标
{
	int maxdepth; //最大深度，一个重要的参数
	int maxwidth;
	int maxgap;
} TreeInfo;

typedef struct
{
	BiTree elements[MAXSIZE];
	int top;
} Stack;

typedef BiTNode *Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE];
	int front;
	int rear;
} Queue;

Status InitQueue(Queue *Q) //函数介绍:初始化队列函数
{
	int i;
	int QueueLength(Queue Q); /* 伪码算法：将队列内值全部清空，并重置头尾位置*/

	for (i = 0; i < Q->rear; i++)
	{
		Q->data[i] = NULL;
	}

	Q->front = 0;
	Q->rear = 0;

	return OK;
}

Status QueueEmpty(Queue *Q) //函数介绍:检测队空函数
{
	if (Q->front == Q->rear) /* 伪码算法：若发现队列头尾相连就为队空*/
		return TRUE;
	else
	{
		return FALSE;
	}
}

/* 若队列未满，则插入元素e为Q新的队尾元素 */
Status EnQueue(Queue *Q, Elemtype e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

/* 若队列不空，则删除Q中队头元素，用e返回其值 */
BiTNode *DeQueue(Queue *Q)
{
	int tag = QueueEmpty(Q);
	BiTNode *e;
	if (Q->rear == Q->front && tag == 1)
		return NULL;
	e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return e;
}

void InitStack(Stack *S) /* 初始化栈 */
{
	S->top = -1;
}

void Push(Stack *S, BiTree temp) /* 入栈  */
{
	S->elements[++S->top] = temp;
}

BiTree Pop(Stack *S) /*出栈 */
{
	return S->elements[S->top--];
}

Status Gettop(Stack *S, BiTree *temp) /*读取栈顶元素*/
{
	if (S->top == -1)
		return ERROR;
	else
	{
		(*temp) = S->elements[S->top];
		return OK;
	}
}

int CreateBiTree(BiTree *bt, int depth, int *p_maxdepth) /*创建二叉树存储结构并返回树结构的最大深度 */
{
	char ch;
	ch = str[index++]; //预先设置测试数据
	// printf("输入树的结点值:\n");	//手动输入							//函数介绍：建立二叉树函数
	// ch = getchar();
	// while (getchar() != '\n')									  //伪码算法：接受先序序列输入，如果结点bt不为空就给bt分配地址
	// 	continue;
	if (*p_maxdepth < depth)
	{
		*p_maxdepth = depth;
	}
	if (ch == '#')
		*bt = NULL;
	else
	{
		*bt = (BiTree)malloc(sizeof(BiTNode)); //先序遍历递归  168页
		(*bt)->data = ch;
		(*bt)->depth = depth;
		CreateBiTree(&((*bt)->Lchild), depth + 1, p_maxdepth);
		CreateBiTree(&((*bt)->Rchild), depth + 1, p_maxdepth);
	}
	return *p_maxdepth - 1;
}

void surewidth(BiTree *bt, TreeInfo btinfo, int width, int isrec) //从头结点坐标(0, maxwidth/2)开始，给每个结点标上width,结点之间的间距为gap,头结点gap设为0
{
	if (*bt != NULL) //函数介绍：确定结点横坐标函数
	{				 //伪码算法：递归先序遍历结点给各结点赋值
		int gap = pow(2, (btinfo.maxdepth - (*bt)->depth)) - 1;

		if (isrec == 0) /* //第一次width的赋值(即头结点width)是maxwidth/2,之后的width的赋值是上个函数的递归结果，那就不应该让其再被赋这个初值，
		故用isrec判定是否已递归避免重复赋第一次值 */
		{
			(*bt)->width = (btinfo.maxwidth) / 2;
			isrec = 1;
		}
		else
		{
			(*bt)->width = width;
		}

		surewidth(&((*bt)->Lchild), btinfo, (*bt)->width - (gap / 2) - 1, isrec);
		surewidth(&((*bt)->Rchild), btinfo, (*bt)->width + (gap / 2) + 1, isrec);
	}
}
void PreOrder_Rec(BiTree bt) /*先序递归 */
{
	if (bt != NULL)
	{
		printf("%c", bt->data);
		PreOrder_Rec(bt->Lchild);
		PreOrder_Rec(bt->Rchild);
	}
}

void InOrder_Rec(BiTree bt) /*中序递归 */
{
	if (bt != NULL)
	{
		InOrder_Rec(bt->Lchild);
		printf("%c", bt->data);
		InOrder_Rec(bt->Rchild);
	}
}

void PostOrder_Rec(BiTree bt) /*后序递归 */
{
	if (bt != NULL)
	{
		PostOrder_Rec(bt->Lchild);
		PostOrder_Rec(bt->Rchild);
		printf("%c", bt->data);
	}
}

void PreOrder_Unrec(BiTree t) /*先序非递归 */
{
	BiTree temp = t;
	Stack S;
	InitStack(&S);
	while (temp != NULL || S.top != -1) //树非空或栈非空
	{
		while (temp != NULL)
		{
			printf("%c", temp->data);
			Push(&S, temp); /*遍历左子树 */
			temp = temp->Lchild;
		}
		if (S.top != -1) //栈非空
		{
			temp = Pop(&S); //思路   先访问左子树，当左子树为空，退回，出栈 ,再访问右子树，进入while循环，左子树为空，右子树访问
			if (temp != NULL)
				temp = temp->Rchild;
		}
	}
}

void InOrder_Unrec(BiTree t) /*中序非递归 */
{
	BiTree temp = t;
	Stack S;
	InitStack(&S);
	while (temp != NULL || S.top != -1)
	{
		while (temp != NULL)
		{
			Push(&S, temp); /*遍历左子树 */
			temp = temp->Lchild;
		}
		if (S.top != -1)
		{
			temp = Pop(&S);
			printf("%c", temp->data);
			temp = temp->Rchild;
		}
	}
}

void PostOrder_Unrec(BiTree t) /*后序非递归 */
{
	Stack S;
	BiTNode *temp, *q;
	InitStack(&S);
	q = NULL;
	temp = t;
	while (temp != NULL || S.top != -1)
	{
		if (temp != NULL)
		{
			Push(&S, temp); /*遍历左子树 */
			temp = temp->Lchild;
		}

		else
		{
			Gettop(&S, &temp);
			if (temp->Rchild == NULL || temp->Rchild == q) /*无右子树，或右孩子已经遍历过 */
			{
				printf("%c", temp->data); //174页
				q = temp;
				temp = Pop(&S);
				temp = NULL;
			}
			else
				temp = temp->Rchild;
		}
	}
}

void ShowTree(BiTree bt, TreeInfo btinfo) //打印整个二叉树结构
{
	Queue TreeArray;		 //用队列存放树的各结点地址
	InitQueue(&TreeArray);	 //函数调用队列并初始化
	EnQueue(&TreeArray, bt); //队列q存放二叉树各结点的地址，先把根节点入队
	BiTNode *p;				 //存放出队结点的指针

	void Printlimb(Queue * motherList);
	//当队头和队尾相等时，表示队列为空
	while (TreeArray.front < TreeArray.rear)
	{

		p = DeQueue(&TreeArray); //队头结点出队
		if (p->Lchild != NULL)	 //将队头结点的左右孩子依次入队
		{
			EnQueue(&TreeArray, p->Lchild);
		}

		if (p->Rchild != NULL)
		{
			EnQueue(&TreeArray, p->Rchild);
		}
	}

	//上述代码通过层序遍历将所有树结点放入队列中，现重设队头以便遍历队列
	TreeArray.front = 0;

	int nowdepth = TreeArray.front; //打印当前节点的深度
	int i, j = -1;					//用于遍历TreeArray和追踪结点的横坐标
	int last_width;					//如果打印的是右子树，需定位
	Queue motherList;				//用于存放带有孩子的结点
	InitQueue(&motherList);			//第一次初始化清除队列内的野指针
	for (i = 0, p = TreeArray.data[i]; i < TreeArray.rear; p = TreeArray.data[++i])
	{
		if (p->depth != nowdepth) //根据新打印的节点深度确定是否要换行打印
		{
			nowdepth = p->depth;
			last_width = -1;
			printf("\n");
			Printlimb(&motherList);
			InitQueue(&motherList); //把所有有子结点的枝条打出来后清空该队列，准备存放下一层的有子结点
		}

		else //深度没变，说明这一层不止一个节点，开始记录上一个节点的打印位置
		{
			last_width = j;
		}

		for (j = last_width + 1; j < p->width; j++) //定位到当前节点位置打印
		{
			printf(" ");
		}
		printf("%c", p->data);

		if (p->Lchild || p->Rchild) //如果p有子树，将其加入子队列
		{
			EnQueue(&motherList, p);
		}
	}
}

void Printlimb(Queue *motherList)
{
	void printstem(Queue * motherList);	  //打印母结点下的茎
	void printbranch(Queue * motherList); //打印分支

	printstem(motherList);
	motherList->front = 0;
	printf("\n");
	printbranch(motherList);
	printf("\n");
}

void printstem(Queue *motherList)
{
	BiTNode *p;
	int i, j = 0, last_width = 0;
	p = DeQueue(motherList);
	do
	{
		for (i = last_width; i < p->width; i++) //从上个有子结点（如果没有位置就是0）定位到现在的有子结点p的位置
		{
			printf(" ");
		}
		printf("|");
		i++;

		p = DeQueue(motherList);
		last_width = i; //如果不止一个有子结点，则开始记录上一个有子结点的位置
		j++;			//j用于遍历队列，追踪当前的队列位置
	} while (j < motherList->rear);
}

void printbranch(Queue *motherList)
{
	BiTNode *p;
	int i, j = 0;
	int last_width = -1;
	p = DeQueue(motherList);
	do
	{
		if (p->Lchild) //如果p存在的是左子树
		{
			for (i = last_width + 1; i < p->width; i++) //定位到p左子树的位置,然后从p左子树向p结点打印树枝
			{
				if (i == p->Lchild->width)
				{
					printf("|");
				}
				else if (i > p->Lchild->width)
				{
					printf("=");
				}
				else
				{
					printf(" ");
				}
			}
			printf("o");
			i++;

			if (p->Rchild) //如果p还存在右子树，即两颗树都有
			{
				while (i < p->Rchild->width)
				{
					printf("=");
					i++;
				}
				printf("|");
			}
		}

		if (p->Rchild && !(p->Lchild)) //如果p只有右子树
		{
			for (i = last_width + 1; i < p->Rchild->width; i++) //从p结点向p右子树打印树枝
			{
				if (i >= p->width)
				{
					if (i == p->width)
					{
						printf("o");
					}
					else
					{
						printf("=");
					}
				}
				else
				{
					printf(" ");
				}
			}
			printf("|");
		}

		p = DeQueue(motherList);
		last_width = i;
		j++; //j用于遍历队列，追踪当前的队列位置
	} while (j < motherList->rear);
}

void menu(){
	system("color 71");
	system("cls");
	printf("\n\n");
	printf("\t|-------------------二叉树操作-----------------|\n");
	printf("\t|                                              |\n");
	printf("\t|----------------1.递归法遍历------------------|\n");
	printf("\t|                                              |\n");
	printf("\t|----------------2.非递归法遍历----------------|\n");
	printf("\t|                                              |\n");
	printf("\t|----------------3.打印二叉树------------------|\n");
	printf("\t|                                              |\n");
	printf("\t|----------------4.显示成员信息----------------|\n");
	printf("\t|                                              |\n");
	printf("\t|----------------0.退出系统--------------------|\n");
	printf("\t|                                              |\n");
	printf("\t|----------------------------------------------|\n");
	printf("\t请输入0-4的数字选择要进行的操作<...>\n");
}

int main()
{
	int num = 0;
	int i;
	int length = 0;

	BiTree bt;
	TreeInfo btinfo;

	int isrec = 0;		//是否开始了递归（进入第一次调用即算递归），尚未递归设为0
	int root_depth = 0; //根节点的高度为0

	printf("输入树的结点值(不用一次次回车，一次性输入):\n"); //手动输入 	//测试数据："LE3T##A##1K###5M##T##"  "ABC##DE#G##F###" 
	char testdata[40];
	scanf("%s", testdata); 
	while (getchar() != '\n')
	{
		continue;
	}

	StrAssign(str, testdata); //预设测试数据：输入的信息导入字符串str中

	btinfo.maxdepth = CreateBiTree(&bt, root_depth, &(btinfo.maxdepth)); /*创建二叉树存储结构并返回树结构的最大深度 */
	btinfo.maxwidth = pow(2, btinfo.maxdepth + 1) - 1;
	btinfo.maxgap = pow(2, btinfo.maxdepth) - 1;

	surewidth(&bt, btinfo, btinfo.maxdepth / 2, isrec); //从头结点坐标(0, maxwidth/2)开始，给每个结点标上width

	menu();
	scanf("%d", &num);
	while (num)
	{
		switch (num)
		{
		case 1:
		{

			printf("递归遍历法：\n");
			for (i = 0; i < a; i++)
			{
				printf("%d ", i);
			}
			printf("先序: ");
			PreOrder_Rec(bt);
			printf("\n中序: ");
			InOrder_Rec(bt);
			printf("\n后序: ");
			PostOrder_Rec(bt);
			break;
		}

		case 2:
		{
			printf("\n非递归遍历法：\n");
			for (i = 0; i < a; i++)
			{
				printf("%d ", i);
			}
			printf("先序: ");
			PreOrder_Unrec(bt);
			printf("\n中序: ");
			InOrder_Unrec(bt);
			printf("\n后序: ");
			PostOrder_Unrec(bt);
			break;
		}

		case 3:
		{
			printf("\n树的结构为:\n");
			ShowTree(bt, btinfo);
			break;
		}

		case 4:
		{
			printf("\n\n\t小组成员名单\n");
			printf("\t张达麟  何文强\n");
			printf("\t徐丹丹  鲁奋潮\n");
			printf("\t潘孝晨\n");
			break;
		}
		default:
			fflush(stdin); //清空输入流
			printf("请输入正确的数字！\n");
			system("pause");
		}
	
		scanf("%d", &num);
		menu();
		printf("你选择了:%d\n2", num);
	}
	return 0;
}
