#include<stdio.h>
#include <stdlib.h>
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

void InitList(LNode L,int L1)
{
    int* p1; //在函数中，可以用整数型的指针指向整数型变量
    p1 = L1;
  
    LNode *p;   
    // p = L;  //依次类推为什么不能用结构体型的指针指向结构体型的变量,难道结构体型指针指向的不是其地址？
    printf("%p",p);
    printf("%p",&p);
   
}
int main()
{
    LNode L;
    int L1;
     
    InitList(L,L1);


}