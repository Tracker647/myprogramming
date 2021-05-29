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
    printf("\n�������ַ�����(��һ���ַ���һ�λس�): ");

    ch = getchar();
    while (getchar() != '\n')
        continue;
    printf("Ŀǰջ��:%d\n", S->top + 2);
    while (ch != '&')
    {
        Push(&S, ch);
        printf("\n�������ַ�����(��һ���ַ���һ�λس�): ");
        ch = getchar();
        while (getchar() != '\n')
            continue;
        printf("Ŀǰջ��:%d\n", S->top + 2);
    }
    printf("��������&,��ʼ��������2:\n");
    printf("\n�������ַ�����(��һ���ַ���һ�λس�): ");
    ch = getchar();
    while (getchar() != '\n')
        continue;
    while (ch != '@')
    {
        if (!(IsEmpty(S)))
        {
            Pop(&S, &temp);
            printf("Ŀǰջ��:%d", S->top + 2);
        }

        else
        {
            printf("ջ�ѿ�\n");
            return FALSE;
        }

        printf("��ջԪ��:%c,�Ա�Ԫ��:%c", temp, ch);
        if (ch != temp)
        {
            printf("NO.\n");
            return FALSE;
        }
        printf("\n�������ַ�����(��һ���ַ���һ�λس�): ");
        ch = getchar();
        while (getchar() != '\n')
            continue;
    }
    printf("OK.\n");


    return TRUE;

}
