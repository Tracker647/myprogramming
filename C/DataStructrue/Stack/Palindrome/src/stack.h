#ifndef _STACK_H_
#define _STACK_H_
#define Stack_Size 50
#define TRUE 1
#define FALSE 0
typedef char StackElementType;
typedef struct SeqStack
{
    StackElementType elem[Stack_Size];
    int top;
}SeqStack;

void InitStack(SeqStack *S);

void ClearStack(SeqStack *S);

int IsEmpty(SeqStack *S);

int Push(SeqStack **S,StackElementType x);

int Pop(SeqStack **S,StackElementType *x);

int GetTop(SeqStack *S,StackElementType *x);

int IsHuiWen(SeqStack *S);//»ØÎÄ¼ì²é

#endif