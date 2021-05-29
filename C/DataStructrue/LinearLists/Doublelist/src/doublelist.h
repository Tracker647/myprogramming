#ifndef _DOUBLELIST_H_
#define _DOUBLELIST_H_
#define OK 1
#define ERROR 0
typedef int Elemtype;
/* Ë«Á´±í */
typedef struct DNode
{
    Elemtype data;
    struct DNode *prior,*next;
}DNode,*DoubleList;


void InitDList(DoubleList *L);
int DListLength(DoubleList L);
void DListIns(DoubleList L,int i,Elemtype e);
void DListDel(DoubleList L,int i,Elemtype *e);
void Locate(DoubleList L,int i);
void GetElem(DoubleList L,Elemtype key);

#endif