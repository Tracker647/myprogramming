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
    printf("���������������:\n");
    c = getchar();
    while (c != '$')
    {
        s = (Node *)malloc(sizeof(Node));
        rear->next = s;
        rear = s;
        c = getchar();
    }
    rear->next = CL;
    printf("�����ѽ���");
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
        printf("����λ�ò�����\n");
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
        printf("����λ�ò�����\n");
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
        printf("ɾ��λ��Ϊ�գ�\n");
        return ERROR;
    }
    s = pre->next;
    pre->next = s->next;
    s->next = NULL;
    free(s);
    return OK;
}
Node *FindbyElem(LinkList CL, Elemtype e) //��ֵ���ң����ص�ַ
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
Node* FindbyLoc(LinkList CL, int i,Node* p) //��λ�ò��ң����ر��
{
    Node *pf;
    pf = p;
    int k = 1;
    // if(CL->next!=NULL)
    // {
    //     printf("���ѿգ�\n");
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
        pf = pf->next;//��ֹ�������ִﵽ�ˣ�ָ���һ���ﵽ����ֹѭ��������
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
    Node *t;//����ɾ���ͼ���
    t = CL->next;
    int i = 1, num=1;

    p=FindbyLoc(CL,*m,p);//�ҵ���m����
    while(t!=p)
    {
        t=t->next;
        num++;
    }
  	printf("��ɱ�߱��Ϊ��%d ����Ϊ��%d\n",p->number,p->data);
    *m=p->data;
    p=p->next;
    DelCLinklist(CL,num,p->data);
    return p;
}