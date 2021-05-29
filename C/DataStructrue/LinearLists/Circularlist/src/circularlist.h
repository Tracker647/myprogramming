#ifndef _CIRCULARLIST_H_
#define _CIRCULARLIST_H_
#define OK 1
#define ERROR 0
typedef int Elemtype;
typedef struct Node
{
   Elemtype data;
   int number;
   struct Node *next;
}Node,*LinkList;    //Node�ǽṹ�壬Linklist���ǽṹ��ָ��

void InitCLinkList(LinkList *CL); 

void CreateCLinklist(LinkList CL);  //����β�巨L

void InsCLinklist(LinkList CL, int i, Elemtype e);

int ListLength(LinkList CL); //��������

void ListTraverse(LinkList CL);

void DelCLinklist(LinkList CL, int i, Elemtype e);

Node* FindbyElem(LinkList CL,Elemtype e);

Node*  FindbyLoc(LinkList CL, int i,Node* p);
Node* Joseph(LinkList CL, int *m,int *n,Node* p);

LinkList merge_1(LinkList LA,LinkList LB);

LinkList merge_2 (LinkList LA,LinkList LB);

#endif