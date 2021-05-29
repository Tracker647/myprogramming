#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
struct comment
{
    char text[MAX_SIZE];
};
typedef struct LNode
{
    struct comment comment;
    struct LNode *prev;
    struct LNode *next;
}LNode;
LNode *head;
LNode *tail;

void InitList(LNode *L)
{  
    LNode *p;   
    p = L;
    p->prev = NULL;
    p->next = NULL; 
    strcpy(p->comment.text,"Head");   
}
void InsList_FromHead(LNode *L) //头插法
{
    LNode *head,*newNode;
    head = L;
    newNode = (LNode*)malloc(sizeof(LNode));
    if(head->next != NULL)
    {
        newNode->next = head->next;
        (head->next)->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }
   else
   {
        newNode->prev = head;
        head->next = newNode;
        newNode->next = NULL;     
   }

}

void InsList_FromTail(LNode *L) //尾插法
{
    LNode *p,*newNode;
    newNode = (LNode*)malloc(sizeof(LNode));
    for(p = L;(p->next)!=NULL;p=p->next)
    {     
    }
    p->next = newNode;
    newNode->prev = p;
    newNode->next = NULL;
}

void ListLength(LNode head)
{
    LNode *p;
    int len = 0;
    for(p = head.next;p!=NULL;p=p->next)
    {
        len++;
    }
    printf("当前表长:%d\n",len);
}
void DelList(int index,LNode* L)
{
    int i = 0;
    LNode* p;
    for(p = L;i < index; i++,p = p->next)
    {
    }
    (p->prev)->next = p->next;
    (p->next)->prev = p->prev;
    free(p);

}
int main()
{
    LNode L;
    InitList(&L);

    InsList_FromHead(&L);
    ListLength(L);
    InsList_FromHead(&L);
    ListLength(L);
    InsList_FromHead(&L);
    ListLength(L);
    DelList(2,&L);
    ListLength(L);
 

}