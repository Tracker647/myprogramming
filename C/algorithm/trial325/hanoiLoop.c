
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int n;
    char a, b, c;
    int flag;
} ElemTp;

typedef struct
{
    ElemTp *elem;
    int max_size;
    int top;
} SqStack;
void createStack(SqStack *s, int n);
void push(SqStack *s, int n, char a, char b, char c, int flag);
void main()
{

    int n;
    ElemTp x, y;
    printf("input the number of plate:\n");
    scanf("%d", &n);
    SqStack s;
    createStack(&s, n);
    push(&s, n, 'A', 'B', 'C', 0);
    while (s.top >= 0)
    {
        x = s.elem[s.top];
        if (x.n == 0 || x.flag == 2)
        {
            s.top--;
            s.elem[s.top].flag++;
        }
        else if (x.flag == 0)
            push(&s, x.n - 1, x.a, x.c, x.b, 0);
        else
        {
            printf("plate number: %d,%c-->%c\n", x.n, x.a, x.c);
            push(&s, x.n - 1, x.b, x.a, x.c, 0);
        }
    }
}
void createStack(SqStack *s, int n)
{
    s->max_size = n + 1;
    s->top = -1;
    if (!(s->elem = (ElemTp *)malloc(s->max_size)))
        exit(-1);
}

void push(SqStack *s, int n, char a, char b, char c, int flag)
{
    ElemTp x = {n, a, b, c, flag};
    if (s->top >= s->max_size - 1)
        exit(-1);
    s->elem[++s->top] = x;
}
