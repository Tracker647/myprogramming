#ifndef _LINKEDLIST_H_
#include <stdbool.h>
#define _LINKEDLIST_H_
#define OK 1
#define ERROR 0

typedef int Elemtype;
typedef struct Node
{
   Elemtype data;
   struct Node *next;
}Node,*LinkList;    //Node是结构体，Linklist则是结构体指针

void Initlist(LinkList *L); //初始化单链表
//注意：*L则是属于Linklist（结构体指针）类型的变量，L是该变量的地址

void CreateFromHead(LinkList L);  //头插法建表

void CreateFromTail(LinkList L); //尾插法建表

Node *Get(LinkList L,int i); //在带头结点的单链表L中查找第i个节点，若找到则返回该节点的存储位置

Node *Locate(LinkList L,Elemtype key); //按key值查找节点

int ListLength(LinkList L); //测量长度

void InsList(LinkList L,int i,Elemtype e);  //在带头节点的单链表L中第i个位置插入值为e的新结点

int DelList(LinkList L,int i,char *e);    //在带头结点的单链表L中删除第i个元素，并将删除的元素保存到变量*e中

LinkList MergeLinkList(LinkList LA,LinkList LB,LinkList LC);  //将递增有序的单链表LA和LB合并成一个递增有序的单链表LC
LinkList Different(LinkList LA, LinkList LB,LinkList LC);  //求单链表LA和LB之差集

int Clearlist(LinkList L);
bool ListEmpty(LinkList L);

#endif