#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

int index=1;
typedef char DataType;
typedef char String[MAXSIZE];

typedef int SElemType;
typedef int Status;

String str;

typedef struct Node //树
{
    DataType data;
    struct  Node* LChild;
    struct  Node* RChild;
    
}BiNode,*BiTree;

typedef struct
{
        BiTree p;
        int top; /* 用于栈顶指针 */
}SqStack;



void CreateTree(BiTree *bt)
{
    char ch;
    ch = str[index++];
    if(ch=='#'||ch=='\000')
        *bt = NULL;   
    else
    {
        *bt = (BiTree)malloc(sizeof(BiNode));
        (*bt)->data = ch;
        CreateTree(&((*bt)->LChild));
        CreateTree(&((*bt)->RChild));
    }
    
}

int StrAssign(String str,char *text)
{
    int i;
    if(strlen(text)>MAXSIZE)
    {
        return ERROR;
    }
    else
    {
        str[0]=strlen(text);
        for(i=1;i<str[0];i++)
        {
            str[i]=*(text+i-1);
        }
    }
    
    
}

void PreOrder(BiTree root)
{
    BiNode *p = root;
    BiNode *S[MAXSIZE];
    int top = -1;
    while(p||top!= -1)
    {
        while(p){
            printf("%c",p->data);
            S[++top] = p;
            p = p->LChild;
        }
        if(top!=-1)
        {
            p=S[top--];
            p = p->RChild;
        }
    }
}

void InOrder(BiTree root)
{
    BiNode* p = root;
    BiNode *S[MAXSIZE];
    int top = -1; 
    while(p!=NULL||top!=-1)
    {
        if(p!=NULL)
        {
            S[++top]=p;
            p=p->LChild;
        }
        else
        {
            p=S[top--];
            printf("%c",p->data);
            p=p->RChild;
        }
        
    }

    
}

void PostOrder(BiTree root)
{
    BiNode *p=root;
    BiNode *S[MAXSIZE];
    BiNode *r = NULL;
    int top = -1;
    while(p!=NULL||top!=-1)
    {
        if(p!=NULL)
        {
            S[++top] = p;
            p=p->LChild;
        }
        else
        {
            p = S[top];
            if((p->RChild!=NULL)&&(p->RChild!=r))
            {
                p=p->RChild;
                S[++top]=p;
                p = p->LChild;
            }
            else
            {
                p=S[top--];
                printf("%c",p->data);
                r = p;
                p = NULL;
            }
            
        }
        
    }
}

int main()
{
    int i;
    char *text = "ABC##DE#G##F###";
    StrAssign(str,text);
    for(i=1;i<=str[0];i++)
    {
    printf("%c",str[i]);
    }
    printf("\n");
    BiTree T;
    SqStack S;
    CreateTree(&T);
    printf("建立成功\n");
    printf("先序遍历:\n");
    PreOrder(T);
    printf("\n");
    printf("中序遍历:\n");
    InOrder(T);
    printf("\n");
    printf("后序遍历:\n");
    PostOrder(T);
    printf("\n");

    

}

