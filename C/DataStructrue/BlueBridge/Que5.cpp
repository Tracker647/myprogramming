#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef char Elemtype;
struct Node
{
	Elemtype data;
    struct Node *next;
};
typedef struct Node *LinkList; 


void InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
}

void InsList(LinkList *L,int i,Elemtype *str)
{
	int k;
	LinkList pre,s;
	pre = *L;
	s=(LinkList)malloc(sizeof(Node));
	s->next=NULL;
	s->data = *str;
	for(k=0;k<i-1;k++)	//寻找第k个节点
	{
		pre = pre->next;
	}	
	pre->next = s;		//新表s的插入过程
	s = pre->next;
	
	
}

LinkList DelList(LinkList *L,int i,Node *p)
{
	LinkList pre=*L,del=p;
	int k;
	for(k=0;k<i-1;k++)	/* 遍历寻找第k个元素 */
	{
		pre = pre->next;
	}
	p = del->next;
	pre->next = p;
	del->next = NULL;
	free(del);
	return p;
}

int main() {
	char *str[]={"123-45-678"};
	int i;
	char ch = '-';
	LinkList L;
	Node *p;
	InitList(&L);
	for(p=L,i=0;i<strlen(str[0]);i++,p=p->next)
	{
		InsList(&L,i+1,*str+i);
	}

	printf("Index:\n");
	for(p=L;p!=NULL;p=p->next)
	{
		printf("%c",p->data);
	}
	printf("\n");


	for(p=L,i=0;i<strlen(str[0])&&(p!=NULL);i++,p=p->next)
	{
	
		if(p->data==ch)
		{
			p=DelList(&L,i,p);
		}
		
		
	}

	printf("Changed:\n");
	for(p=L;p!=NULL;p=p->next)
	{
		printf("%c",p->data);
	}
	printf("\n");
	return 0;
}
