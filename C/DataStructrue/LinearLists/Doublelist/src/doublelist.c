#include <stdio.h>
#include <stdlib.h>
#include "doublelist.h"

void InitDList(DoubleList *L)
{
    L=(DoubleList)malloc(sizeof(DNode));
}
int DListLength(DoubleList L)
{
    DNode *p=L->next;
    int j=0;
    while(p!=NULL)
    {
        p=p->next;
        j++;
    }
    return j;
}
void DListIns(DoubleList L,int i,Elemtype e)
{
    DNode *s,*pre;
    pre=L;
    int k=0;
    while((k<=i-1)&&(s!=NULL))
    {
        pre=pre->next;
        k++;
    }
    if(pre==NULL || i<0)
    {
        printf("插入位置不合理！");
        return ERROR;
    }
    else
    {
        s = (DNode *)malloc(sizeof(DNode));
        s->data = e;
        s->next=pre->next;
        pre->next=s;
    }
    return OK;
}