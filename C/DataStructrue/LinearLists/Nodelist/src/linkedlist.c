#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
void Initlist(LinkList *L) //��ʼ��������
{
    printf("�ѳ�ʼ��������\n");
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    return OK;
}

void CreateFromHead(LinkList L)
{
    Node *s;
    char c;
    int flag = 1;
    while (flag)
    {
        c = getchar();
        if (c != "$")
        {
            s = (Node *)malloc(sizeof(Node));
            s->data = c;
            s->next = L->next;
            L->next = s;
        }
        else
            flag = 0;
    }
}

void CreateFromTail(LinkList L) //β�巨����
{
    int flag;
    Node *r, *s;
    char c;
    r = L;
    while (flag = 1)
    {
        c = getchar();
        if (c != '$')
        {
            s = (Node *)malloc(sizeof(Node));
            s->data = c;
            r->next = s;
            r = s;
        }
        else
        {
            flag = 0;
            r->next = NULL;
        }
    }
}
Node *Get(LinkList L, int i) //�ڴ�ͷ���ĵ�����L�в��ҵ�i���ڵ㣬���ҵ��򷵻ظýڵ�Ĵ洢λ��
{
    int j = 0;
    Node *p;
    if (i <= 0)
    {
        return NULL;
    }
    p = L;
    while ((p->next != NULL) && (j < i))
    {
        p = p->next;
        j++;
    }

    if (j == i)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}
Node *Locate(LinkList L, Elemtype key) //��keyֵ���ҽڵ�
{
    Node *p;
    p = L->next;
    while (p != NULL)
        if (p->data != key)
            p = p->next;
        else
        {
            break;
        }

    return p;
}
int ListLength(LinkList L) //��������
{
    Node *p;
    int j = 0;
    p = L->next;
    while (p != NULL)
    {
        p = p->next;
        j++;
    }
    return j;
}
void InsList(LinkList L, int i, Elemtype e) //�ڴ�ͷ�ڵ�ĵ�����L�е�i��λ�ò���ֵΪe���½��
{
    Node *pre, *s;
    int k = 0;
    if (i <= 0)
        return ERROR;
    pre = L;
    while ((pre != NULL) && (k < i - 1))
    {
        pre = pre->next;
        k = k + 1;
    }
    if (pre == NULL)
    {
        printf("����λ�ò�����");
        return ERROR;
    }
    s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = pre->next;
    pre->next = s;
    return OK;
}

int DelList(LinkList L, int i, char *e) //�ڴ�ͷ���ĵ�����L��ɾ����i��Ԫ�أ�����ɾ����Ԫ�ر��浽����*e��
{
    Node *pre, *r;
    int k;
    pre = L;
    k = 0;
    while (pre->next != NULL && k < i - 1)
    {
        pre = pre->next;
        k++;
    }
    if (pre->next == NULL)
    {
        return ERROR;
    }
    r = pre->next;
    pre->next = r->next;
    *e = r->data;
    free(r);
    return OK;
}


LinkList MergeLinkList(LinkList LA, LinkList LB, LinkList LC) //����������ĵ�����LA��LB�ϲ���һ����������ĵ�����LC
{
    Clearlist(LC);
    Initlist(LC);
    Node *pa, *pb;
    pa = LA->next;
    pb = LB->next;
    int k = 0;
    while (pa != NULL && pb != NULL)
    {
        if (pa->data < pb->data)
        {
            InsList(LC, k + 1, pa->data);
            pa = pa->next;
            k++;
        }
        else if (pa->data == pb->data)
        {
            InsList(LC, k + 1, pa->data);
            pa = pa->next;
            pb = pb->next;
            k++;
        }
        else
        {
            InsList(LC, k + 1, pb->data);
            pb = pb->next;
            k++;
        }
    }
    return (LC);
}

void ListTraverse(LinkList L)
{
    Node *p;
    if(ListEmpty(L))
    {
        return ERROR;
    }
    p = L->next;
    printf("L.data=");
    for(p=L->next;p!=NULL;p=p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
    return 0;
}

LinkList Different(LinkList LA, LinkList LB, LinkList LC) //������LA��LB֮�
{
    Clearlist(LC);
    Initlist(LC);
    Node *pa = LA->next;
    int i = 0;
    while (pa != NULL)
    {
        if (!Locate(LB, pa->data))
        {
            InsList(LC, i, pa->data);
            i++;
        }

        pa = pa->next;
    }
    return (LC);
}

int Clearlist(LinkList L)
{
    Node *p , *q;
    p=L;
    /*  pָ���һ����� */
    if (p->next == NULL)
    {
        printf("������Ѿ�����!\n");
        return OK;
    }

    else
    {
        q = p->next;
    }

    while (q != NULL) /*  û����β */
    {
        free(p);
        p = q;
        q = p->next;
    }
    /* ͷ���ָ����Ϊ�� */
    printf("������ñ�\n");
    return OK;
}



bool ListEmpty(LinkList L)
{
    return L->next==NULL;
}
















