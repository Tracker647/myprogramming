#include <stdio.h>
#include "circularlist.h"
#include <stdlib.h>
#include <stdbool.h>

void InitCLinkList(LinkList *CL)
{
    *CL = (Node *)malloc(sizeof(Node));
    (*CL)->next = *CL;
}

void CreateCLinkList(LinkList CL)
{
    Node *s, *rear;
    char c;
    rear = CL;
    printf("输入新链表的数据:\n");
    c = getchar();
    while (c != '$')
    {
        s = (Node *)malloc(sizeof(Node));
        rear->next = s;
        rear = s;
        c = getchar();
    }
    rear->next = CL;
    printf("链表已建立");
}

void InsCLinklist(LinkList CL, int i, Elemtype e)
{
    Node *s, *pre = CL;
    int k = 0;
    if (i < 0)
        return ERROR;

    while ((pre != NULL) && (k < i - 1))
    {
        pre = pre->next;
        k++;
    }
    if (pre == NULL)
    {
        printf("插入位置不合理！\n");
        return ERROR;
    }
    s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = pre->next;
    pre->next = s;
    return OK;
}

void EnNumber(LinkList CL, int i, Elemtype e)
{
    Node *s, *pre = CL;
    int k = 0;
    if (i < 0)
        return ERROR;

    while ((pre != NULL) && (k < i - 1))
    {
        pre = pre->next;
        k++;
    }
    if (pre == NULL)
    {
        printf("插入位置不合理！\n");
        return ERROR;
    }
    pre->number = e;
    return OK;
}

bool ListEmpty(LinkList CL)
{
    return CL->next==NULL;
}

int ListLength(LinkList CL)
{
    int l=0;
    Node *p;
    p=CL->next;
    while(p!=CL)
    {
        p=p->next;
        l++;
    }
    printf("\n");
    return l;
}
void ListTraverse(LinkList CL)
{
    Node *p;
    
    if(ListEmpty(CL))
    {
         return ERROR;
    }
    p=CL->next;  
    printf("CL.data:");
    while(p!=CL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
        

}
void DelCLinklist(LinkList CL, int i, Elemtype e)
{
    Node *s, *pre = CL;
    int k = 0;
    if (i < 0)
        return ERROR;

    while ((pre != NULL) && (k < i - 1))
    {
        pre = pre->next;
        k++;
    }
    if (pre->next == NULL)
    {
        printf("删除位置为空！\n");
        return ERROR;
    }
    s = pre->next;
    pre->next = s->next;
    s->next = NULL;
    free(s);
    return OK;
}
Node *FindbyElem(LinkList CL, Elemtype e) //按值查找，返回地址
{
    Node *p;
    p = CL->next;
    while ((p != CL) && (p->data != e))
        p = p->next;
    if (p->data == e)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}
Node* FindbyLoc(LinkList CL, int i,Node* p) //按位置查找，返回编号
{
    Node *pf;
    pf = p;
    int k = 1;
    // if(CL->next!=NULL)
    // {
    //     printf("表已空！\n");
    //     return 0;
    // }
    if (i <= 0)
    {
        return ERROR;
    }
    while (k < i)
    {
       if (pf != CL)
        {         
            k++;
        }
        pf = pf->next;
    }
    if(pf==CL)
        pf = pf->next;//防止出现数字达到了，指针差一步达到就终止循环的现象
    if (k == i)
    {
        return pf;
    }
    else
    {
        return NULL;
    }
}
Node* Joseph(LinkList CL, int *m,int *n,Node* p)
{
    Node *t;//用于删除和计数
    t = CL->next;
    int i = 1, num=1;

    p=FindbyLoc(CL,*m,p);//找到第m个人
    while(t!=p)
    {
        t=t->next;
        num++;
    }
  	printf("被杀者编号为：%d 密码为：%d\n",p->number,p->data);
    *m=p->data;
    p=p->next;
    DelCLinklist(CL,num,p->data);
    return p;
}