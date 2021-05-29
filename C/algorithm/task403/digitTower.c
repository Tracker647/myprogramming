#include <stdio.h>
int max(int a, int b);
int main()
{
    int i, j;
    int data[5][5] = {
        {9},
        {12, 15},
        {10, 6, 8},
        {2, 18, 9, 5},
        {19, 7, 10, 4, 16}};
    int result[5][5];
    //数塔用data存储,result存放各阶段决策结果的分析
    for (i = 0; i <= 4; i++)
    {
        for (j = 0; j <= i; j++)
        {
            result[i][j] = data[i][j];
            printf("%5d ", result[i][j]);
        }
        printf("\n");
    }
    //找出各阶段的决策结果，记录到result上
    for (i = 3; i >= 0; i--)
    {
        printf("row %d:\n", i);
        for (j = 0; j <= i; j++)
        {

            result[i][j] = max(result[i + 1][j], result[i + 1][j + 1]) + data[i][j];
            printf("%d + %d = %d\n", max(result[i + 1][j], result[i + 1][j + 1]), data[i][j], result[i][j]);
        }
    }

    for (i = 0; i <= 4; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%5d ", result[i][j]);
        }
        printf("\n");
    }
    printf("maxium value:%d\n", result[0][0]);
    j = 0;
    int res; //从终点回溯找出每一步最优解
    printf("track:");
    printf("%d", data[0][0]);
    for (i = 0; i < 4; i++)
    {
        res = result[i][j] - data[i][j];
        // printf("%d - %d = %d\n", result[i][j], data[i][j], res);
        if (res == result[i + 1][j])
        {
            printf("-->%d", data[i + 1][j]);
        }
        else if (res == result[i + 1][j + 1])
        {
            printf("-->%d", data[i + 1][j + 1]);
            j = j + 1;
        }
    }
    printf("\n");
    return 0;
}
int max(int a, int b)
{
    return a > b ? a : b;
}