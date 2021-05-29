#include <stdio.h>
void try();
void print(int *choose);
int fra[9] = {60, 40, 30, 24, 20, 15, 12, 10, 8};
int realFra[9];
int answer[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int count = 0;
int main()
{
    int sum = 0, k = 0;
    int choose[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) //计算用的是分数乘120做整数运算
    {
        realFra[i] = 120 / fra[i];
    }
    try(k, sum, choose);
    printf("total %d ways.", count);
}
void try(int k, int sum, int *choose)
{
    if (sum > 120)
        return;

    if (sum == 120)
    {
        print(choose);
        return;
    }

    for (int i = 0; i < 9; i++)
    {
        if (choose[i] == 0)
        {
            answer[k] = fra[i];
            choose[i] = 1;
            try(k + 1, sum + fra[i], choose);
            choose[i] = 0;
            answer[k] = 0;
        }
    }
}
void print(int *choose)
{
    int isrep = 0;   //排除重复解
    int isfirst = 1; //第一个分数前面不带+号
    int i;
    for (i = 0; answer[i] != 0; i++)
    {
        if (answer[i] < answer[i + 1])
            isrep = 1;
    }
    if (isrep == 0)
    {
        count++;
        for (i = 0; i < 9; i++)
        {
            if (choose[i] == 1)
            {
                if (isfirst == 0)
                    printf(" + ");
                printf("1/%d", realFra[i]);
                isfirst = 0;
            }
        }
        printf(" = 1");
        printf("\n");
    }
}