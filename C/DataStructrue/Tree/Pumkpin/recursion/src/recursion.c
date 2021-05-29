#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0


int index=1;
typedef char String[MAXSIZE];
String str;
typedef char DataType;

typedef struct Node
{
    DataType data;
    struct  Node* LChild;
    struct  Node* RChild;  
}BiNode,*BiTree;

int StrAssign(String str,char *text)
{
    int i;
    if(strlen(text)>MAXSIZE)
        return ERROR;
    else 
    {
        str[0]=strlen(text);
        for(i=1;i<=str[0];i++)
        {
            str[i]=*(text+i-1);
        }
    }

}

void CreateBiTree(BiTree *bt)
{ 
    char ch;   
    int i;
    ch=str[index++];   

        if(ch=='#')
            *bt = NULL;
        else{
            *bt = (BiTree)malloc(sizeof(BiNode));
            (*bt)->data = ch;         
            CreateBiTree(&((*bt)->LChild));
            CreateBiTree(&((*bt)->RChild));
        }
   
}



void PreOrder(BiTree root)
{
    
    if(root!=NULL)
    {
        printf("%c",root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
    
}

void InOrder(BiTree root)
{
   
    if(root!=NULL)
    {    
       InOrder(root->LChild);
       printf("%c",root->data);
       InOrder(root->RChild);
    }
    
}

void PostOrder(BiTree root)
{
    
    if(root!=NULL)
    {      
        PostOrder(root->LChild);      
        PostOrder(root->RChild);
        printf("%c",root->data);
    }
   
}

int main()
{
    BiTree T;
    int i;
    StrAssign(str,"ABC##DE#G##F###");
    printf("测试数据：\n");
    for(i=0;i<=str[0];i++)   //串的0号存放长度
    {
        printf("%c",str[i]);
    }
    printf("\n");
    CreateBiTree(&T);
    printf("树已生成.\n");

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
