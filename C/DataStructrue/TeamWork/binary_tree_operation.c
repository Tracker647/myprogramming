#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXSIZE 50 /* �洢�ռ��ʼ������ */
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

typedef char String[MAXSIZE];

int index = 1; //������Ľ����Ϣ������ַ�����
int a=0; //�˵����

String str;
int StrAssign(String str, char *text) //�������ܣ��ַ�����ֵ����
{
	int i;						//α���㷨������ַ�ָ���ֵ��Ϊ�գ�
	if (strlen(text) > MAXSIZE) //ȡ�ַ�ָ���׵�ַ�ĳ��ȣ���0�������ó��ȸ��ַ�����ֵ
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
	int depth, width; //��Ⱥ���ȣ��൱�ڽ�������

} BiTNode, *BiTree;

typedef struct TreeInfo //��Ź��ڶ�������������Ϣ�����ڼ�������
{
	int maxdepth; //�����ȣ�һ����Ҫ�Ĳ���
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

Status InitQueue(Queue *Q) //��������:��ʼ�����к���
{
	int i;
	int QueueLength(Queue Q); /* α���㷨����������ֵȫ����գ�������ͷβλ��*/

	for (i = 0; i < Q->rear; i++)
	{
		Q->data[i] = NULL;
	}

	Q->front = 0;
	Q->rear = 0;

	return OK;
}

Status QueueEmpty(Queue *Q) //��������:���ӿպ���
{
	if (Q->front == Q->rear) /* α���㷨�������ֶ���ͷβ������Ϊ�ӿ�*/
		return TRUE;
	else
	{
		return FALSE;
	}
}

/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */
Status EnQueue(Queue *Q, Elemtype e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
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

void InitStack(Stack *S) /* ��ʼ��ջ */
{
	S->top = -1;
}

void Push(Stack *S, BiTree temp) /* ��ջ  */
{
	S->elements[++S->top] = temp;
}

BiTree Pop(Stack *S) /*��ջ */
{
	return S->elements[S->top--];
}

Status Gettop(Stack *S, BiTree *temp) /*��ȡջ��Ԫ��*/
{
	if (S->top == -1)
		return ERROR;
	else
	{
		(*temp) = S->elements[S->top];
		return OK;
	}
}

int CreateBiTree(BiTree *bt, int depth, int *p_maxdepth) /*�����������洢�ṹ���������ṹ�������� */
{
	char ch;
	ch = str[index++]; //Ԥ�����ò�������
	// printf("�������Ľ��ֵ:\n");	//�ֶ�����							//�������ܣ���������������
	// ch = getchar();
	// while (getchar() != '\n')									  //α���㷨�����������������룬������bt��Ϊ�վ͸�bt�����ַ
	// 	continue;
	if (*p_maxdepth < depth)
	{
		*p_maxdepth = depth;
	}
	if (ch == '#')
		*bt = NULL;
	else
	{
		*bt = (BiTree)malloc(sizeof(BiTNode)); //��������ݹ�  168ҳ
		(*bt)->data = ch;
		(*bt)->depth = depth;
		CreateBiTree(&((*bt)->Lchild), depth + 1, p_maxdepth);
		CreateBiTree(&((*bt)->Rchild), depth + 1, p_maxdepth);
	}
	return *p_maxdepth - 1;
}

void surewidth(BiTree *bt, TreeInfo btinfo, int width, int isrec) //��ͷ�������(0, maxwidth/2)��ʼ����ÿ��������width,���֮��ļ��Ϊgap,ͷ���gap��Ϊ0
{
	if (*bt != NULL) //�������ܣ�ȷ���������꺯��
	{				 //α���㷨���ݹ����������������㸳ֵ
		int gap = pow(2, (btinfo.maxdepth - (*bt)->depth)) - 1;

		if (isrec == 0) /* //��һ��width�ĸ�ֵ(��ͷ���width)��maxwidth/2,֮���width�ĸ�ֵ���ϸ������ĵݹ������ǾͲ�Ӧ�������ٱ��������ֵ��
		����isrec�ж��Ƿ��ѵݹ�����ظ�����һ��ֵ */
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
void PreOrder_Rec(BiTree bt) /*����ݹ� */
{
	if (bt != NULL)
	{
		printf("%c", bt->data);
		PreOrder_Rec(bt->Lchild);
		PreOrder_Rec(bt->Rchild);
	}
}

void InOrder_Rec(BiTree bt) /*����ݹ� */
{
	if (bt != NULL)
	{
		InOrder_Rec(bt->Lchild);
		printf("%c", bt->data);
		InOrder_Rec(bt->Rchild);
	}
}

void PostOrder_Rec(BiTree bt) /*����ݹ� */
{
	if (bt != NULL)
	{
		PostOrder_Rec(bt->Lchild);
		PostOrder_Rec(bt->Rchild);
		printf("%c", bt->data);
	}
}

void PreOrder_Unrec(BiTree t) /*����ǵݹ� */
{
	BiTree temp = t;
	Stack S;
	InitStack(&S);
	while (temp != NULL || S.top != -1) //���ǿջ�ջ�ǿ�
	{
		while (temp != NULL)
		{
			printf("%c", temp->data);
			Push(&S, temp); /*���������� */
			temp = temp->Lchild;
		}
		if (S.top != -1) //ջ�ǿ�
		{
			temp = Pop(&S); //˼·   �ȷ�������������������Ϊ�գ��˻أ���ջ ,�ٷ���������������whileѭ����������Ϊ�գ�����������
			if (temp != NULL)
				temp = temp->Rchild;
		}
	}
}

void InOrder_Unrec(BiTree t) /*����ǵݹ� */
{
	BiTree temp = t;
	Stack S;
	InitStack(&S);
	while (temp != NULL || S.top != -1)
	{
		while (temp != NULL)
		{
			Push(&S, temp); /*���������� */
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

void PostOrder_Unrec(BiTree t) /*����ǵݹ� */
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
			Push(&S, temp); /*���������� */
			temp = temp->Lchild;
		}

		else
		{
			Gettop(&S, &temp);
			if (temp->Rchild == NULL || temp->Rchild == q) /*�������������Һ����Ѿ������� */
			{
				printf("%c", temp->data); //174ҳ
				q = temp;
				temp = Pop(&S);
				temp = NULL;
			}
			else
				temp = temp->Rchild;
		}
	}
}

void ShowTree(BiTree bt, TreeInfo btinfo) //��ӡ�����������ṹ
{
	Queue TreeArray;		 //�ö��д�����ĸ�����ַ
	InitQueue(&TreeArray);	 //�������ö��в���ʼ��
	EnQueue(&TreeArray, bt); //����q��Ŷ����������ĵ�ַ���ȰѸ��ڵ����
	BiTNode *p;				 //��ų��ӽ���ָ��

	void Printlimb(Queue * motherList);
	//����ͷ�Ͷ�β���ʱ����ʾ����Ϊ��
	while (TreeArray.front < TreeArray.rear)
	{

		p = DeQueue(&TreeArray); //��ͷ������
		if (p->Lchild != NULL)	 //����ͷ�������Һ����������
		{
			EnQueue(&TreeArray, p->Lchild);
		}

		if (p->Rchild != NULL)
		{
			EnQueue(&TreeArray, p->Rchild);
		}
	}

	//��������ͨ���������������������������У��������ͷ�Ա��������
	TreeArray.front = 0;

	int nowdepth = TreeArray.front; //��ӡ��ǰ�ڵ�����
	int i, j = -1;					//���ڱ���TreeArray��׷�ٽ��ĺ�����
	int last_width;					//�����ӡ�������������趨λ
	Queue motherList;				//���ڴ�Ŵ��к��ӵĽ��
	InitQueue(&motherList);			//��һ�γ�ʼ����������ڵ�Ұָ��
	for (i = 0, p = TreeArray.data[i]; i < TreeArray.rear; p = TreeArray.data[++i])
	{
		if (p->depth != nowdepth) //�����´�ӡ�Ľڵ����ȷ���Ƿ�Ҫ���д�ӡ
		{
			nowdepth = p->depth;
			last_width = -1;
			printf("\n");
			Printlimb(&motherList);
			InitQueue(&motherList); //���������ӽ���֦�����������ոö��У�׼�������һ������ӽ��
		}

		else //���û�䣬˵����һ�㲻ֹһ���ڵ㣬��ʼ��¼��һ���ڵ�Ĵ�ӡλ��
		{
			last_width = j;
		}

		for (j = last_width + 1; j < p->width; j++) //��λ����ǰ�ڵ�λ�ô�ӡ
		{
			printf(" ");
		}
		printf("%c", p->data);

		if (p->Lchild || p->Rchild) //���p����������������Ӷ���
		{
			EnQueue(&motherList, p);
		}
	}
}

void Printlimb(Queue *motherList)
{
	void printstem(Queue * motherList);	  //��ӡĸ����µľ�
	void printbranch(Queue * motherList); //��ӡ��֧

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
		for (i = last_width; i < p->width; i++) //���ϸ����ӽ�㣨���û��λ�þ���0����λ�����ڵ����ӽ��p��λ��
		{
			printf(" ");
		}
		printf("|");
		i++;

		p = DeQueue(motherList);
		last_width = i; //�����ֹһ�����ӽ�㣬��ʼ��¼��һ�����ӽ���λ��
		j++;			//j���ڱ������У�׷�ٵ�ǰ�Ķ���λ��
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
		if (p->Lchild) //���p���ڵ���������
		{
			for (i = last_width + 1; i < p->width; i++) //��λ��p��������λ��,Ȼ���p��������p����ӡ��֦
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

			if (p->Rchild) //���p��������������������������
			{
				while (i < p->Rchild->width)
				{
					printf("=");
					i++;
				}
				printf("|");
			}
		}

		if (p->Rchild && !(p->Lchild)) //���pֻ��������
		{
			for (i = last_width + 1; i < p->Rchild->width; i++) //��p�����p��������ӡ��֦
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
		j++; //j���ڱ������У�׷�ٵ�ǰ�Ķ���λ��
	} while (j < motherList->rear);
}

void menu(){
	system("color 71");
	system("cls");
	printf("\n\n");
	printf("\t|-------------------����������-----------------|\n");
	printf("\t|                                              |\n");
	printf("\t|----------------1.�ݹ鷨����------------------|\n");
	printf("\t|                                              |\n");
	printf("\t|----------------2.�ǵݹ鷨����----------------|\n");
	printf("\t|                                              |\n");
	printf("\t|----------------3.��ӡ������------------------|\n");
	printf("\t|                                              |\n");
	printf("\t|----------------4.��ʾ��Ա��Ϣ----------------|\n");
	printf("\t|                                              |\n");
	printf("\t|----------------0.�˳�ϵͳ--------------------|\n");
	printf("\t|                                              |\n");
	printf("\t|----------------------------------------------|\n");
	printf("\t������0-4������ѡ��Ҫ���еĲ���<...>\n");
}

int main()
{
	int num = 0;
	int i;
	int length = 0;

	BiTree bt;
	TreeInfo btinfo;

	int isrec = 0;		//�Ƿ�ʼ�˵ݹ飨�����һ�ε��ü���ݹ飩����δ�ݹ���Ϊ0
	int root_depth = 0; //���ڵ�ĸ߶�Ϊ0

	printf("�������Ľ��ֵ(����һ�δλس���һ��������):\n"); //�ֶ����� 	//�������ݣ�"LE3T##A##1K###5M##T##"  "ABC##DE#G##F###" 
	char testdata[40];
	scanf("%s", testdata); 
	while (getchar() != '\n')
	{
		continue;
	}

	StrAssign(str, testdata); //Ԥ��������ݣ��������Ϣ�����ַ���str��

	btinfo.maxdepth = CreateBiTree(&bt, root_depth, &(btinfo.maxdepth)); /*�����������洢�ṹ���������ṹ�������� */
	btinfo.maxwidth = pow(2, btinfo.maxdepth + 1) - 1;
	btinfo.maxgap = pow(2, btinfo.maxdepth) - 1;

	surewidth(&bt, btinfo, btinfo.maxdepth / 2, isrec); //��ͷ�������(0, maxwidth/2)��ʼ����ÿ��������width

	menu();
	scanf("%d", &num);
	while (num)
	{
		switch (num)
		{
		case 1:
		{

			printf("�ݹ��������\n");
			for (i = 0; i < a; i++)
			{
				printf("%d ", i);
			}
			printf("����: ");
			PreOrder_Rec(bt);
			printf("\n����: ");
			InOrder_Rec(bt);
			printf("\n����: ");
			PostOrder_Rec(bt);
			break;
		}

		case 2:
		{
			printf("\n�ǵݹ��������\n");
			for (i = 0; i < a; i++)
			{
				printf("%d ", i);
			}
			printf("����: ");
			PreOrder_Unrec(bt);
			printf("\n����: ");
			InOrder_Unrec(bt);
			printf("\n����: ");
			PostOrder_Unrec(bt);
			break;
		}

		case 3:
		{
			printf("\n���ĽṹΪ:\n");
			ShowTree(bt, btinfo);
			break;
		}

		case 4:
		{
			printf("\n\n\tС���Ա����\n");
			printf("\t�Ŵ���  ����ǿ\n");
			printf("\t�쵤��  ³�ܳ�\n");
			printf("\t��Т��\n");
			break;
		}
		default:
			fflush(stdin); //���������
			printf("��������ȷ�����֣�\n");
			system("pause");
		}
	
		scanf("%d", &num);
		menu();
		printf("��ѡ����:%d\n2", num);
	}
	return 0;
}
