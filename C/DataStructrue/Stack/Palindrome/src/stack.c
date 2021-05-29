#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void InitStack(SeqStack* S)
{
    S->top = -1;
}

void ClearStack(SeqStack* S)
{
    S->top = -1;
 
}
int IsEmpty(SeqStack* S)
{
    if (S->top == -1)
        return TRUE;
    else
        return FALSE;
}
int Push(SeqStack** S, StackElementType x)
{
    if ((*S)->top == Stack_Size - 1)
        return(FALSE);
    (*S)->top++;
    (*S)->elem[(*S)->top] = x;
    return(TRUE);
}

int Pop(SeqStack** S, StackElementType* x)
{
    if ((*S)->top == -1)
        return(FALSE);
    else
    {
        *x = (*S)->elem[(*S)->top];
        (*S)->top--;
        return(TRUE);

    }
}

int GetTop(SeqStack* S, StackElementType* x)
{
    if (S->top == -1)
        return FALSE;
    else
    {
        *x = S->elem[S->top];
        return(TRUE);
    }

}


int IsHuiWen(SeqStack* S)
{
    char ch, temp;
    printf("\n请输入字符序列(输一次字符按一次回车): ");

    ch = getchar();
    while (getchar() != '\n')
        continue;
    printf("目前栈数:%d\n", S->top + 2);
    while (ch != '&')
    {
        Push(&S, ch);
        printf("\n请输入字符序列(输一次字符按一次回车): ");
        ch = getchar();
        while (getchar() != '\n')
            continue;
        printf("目前栈数:%d\n", S->top + 2);
    }
    printf("你输入了&,开始输入序列2:\n");
    printf("\n请输入字符序列(输一次字符按一次回车): ");
    ch = getchar();
    while (getchar() != '\n')
        continue;
    while (ch != '@')
    {
        if (!(IsEmpty(S)))
        {
            Pop(&S, &temp);
            printf("目前栈数:%d", S->top + 2);
        }

        else
        {
            printf("栈已空\n");
            return FALSE;
        }

        printf("出栈元素:%c,对比元素:%c", temp, ch);
        if (ch != temp)
        {
            printf("NO.\n");
            return FALSE;
        }
        printf("\n请输入字符序列(输一次字符按一次回车): ");
        ch = getchar();
        while (getchar() != '\n')
            continue;
    }
    printf("OK.\n");


    return TRUE;

}
