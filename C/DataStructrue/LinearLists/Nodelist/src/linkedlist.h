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
}Node,*LinkList;    //Node�ǽṹ�壬Linklist���ǽṹ��ָ��

void Initlist(LinkList *L); //��ʼ��������
//ע�⣺*L��������Linklist���ṹ��ָ�룩���͵ı�����L�Ǹñ����ĵ�ַ

void CreateFromHead(LinkList L);  //ͷ�巨����

void CreateFromTail(LinkList L); //β�巨����

Node *Get(LinkList L,int i); //�ڴ�ͷ���ĵ�����L�в��ҵ�i���ڵ㣬���ҵ��򷵻ظýڵ�Ĵ洢λ��

Node *Locate(LinkList L,Elemtype key); //��keyֵ���ҽڵ�

int ListLength(LinkList L); //��������

void InsList(LinkList L,int i,Elemtype e);  //�ڴ�ͷ�ڵ�ĵ�����L�е�i��λ�ò���ֵΪe���½��

int DelList(LinkList L,int i,char *e);    //�ڴ�ͷ���ĵ�����L��ɾ����i��Ԫ�أ�����ɾ����Ԫ�ر��浽����*e��

LinkList MergeLinkList(LinkList LA,LinkList LB,LinkList LC);  //����������ĵ�����LA��LB�ϲ���һ����������ĵ�����LC
LinkList Different(LinkList LA, LinkList LB,LinkList LC);  //������LA��LB֮�

int Clearlist(LinkList L);
bool ListEmpty(LinkList L);

#endif