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
}Node,*LinkList;    //Node是结构体，Linklist则是结构体指针

void InitCLinkList(LinkList *CL); 

void CreateCLinklist(LinkList CL);  //采用尾插法L

void InsCLinklist(LinkList CL, int i, Elemtype e);

int ListLength(LinkList CL); //测量长度

void ListTraverse(LinkList CL);

void DelCLinklist(LinkList CL, int i, Elemtype e);

Node* FindbyElem(LinkList CL,Elemtype e);

Node*  FindbyLoc(LinkList CL, int i,Node* p);
Node* Joseph(LinkList CL, int *m,int *n,Node* p);

LinkList merge_1(LinkList LA,LinkList LB);

LinkList merge_2 (LinkList LA,LinkList LB);

#endif