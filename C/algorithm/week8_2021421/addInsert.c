#include <stdio.h>
#define N 5 
#define M 2 
char buf[N];
int a[N];
char b[M + 1][N];
int c[M + 1];
int try(int t);
void swap(int t1, int t2);
int add();
void output();
int min = 99999;
int main()
{
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%c", &buf[i]);
    }
    a[0] = 0;
    for (i = 1; i <= M; i++)
    {
        a[i] = 1;
    }
    for (; i < N; i++)
    {
        a[i] = 0;
    }
    try(1);
    output();
    printf("%d\n", min);
    return 0;
}
int try(int t)
{
    int j;
    int i;
    int sum;
    if (t >= N)
    {
        sum = add();
        if (sum < min)
        {
            min = sum;
            for (i = 0; i < M + 1; i++)
            {
                c[i] = atoi(b[i]);
            }
        }
    }
    else
    {
        for (j = t; j < N; j++)
        {

            swap(t, j);
            try(t + 1);
            swap(t, j);
        }
    }
}
void swap(int t1, int t2)
{
    int t;
    t = a[t1];
    a[t1] = a[t2];
    a[t2] = t;
}
int add()
{
    int sum = 0;
    int i = 0;
    int j;
    int k = 0;
    int h = 0;
    for (i = 0; i < M + 1; i++)
        for (j = 0; j < N; j++)
            b[i][j] = 'Q';
    i = 0;
    j = 0;
    h = 0;
    k = 0;
    for (j = 0; j < N; j++)
    {
        if (a[j] == 1)
        {
            h = 0;
            i++;
            b[i][h] = buf[j];

            h++;
        }
        else
        {
            b[i][h] = buf[j];

            h++;
        }
    }

    for (i = 0; i < M + 1; i++)
    {
        sum += atoi(b[i]);
    }
    return sum;
}
void output()
{
    int i;
    for (i = 0; i < M + 1; i++)
    {
        printf("%d", atoi(b[i]));
        if (i != M)
            printf("+");
    }
    printf("=");
}