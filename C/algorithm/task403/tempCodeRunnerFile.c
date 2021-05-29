#include <stdio.h>
int maxfun(int a, int b);
int main()
{

    int i, j, k, max = 0, maxCd;
    int data[6][7] = {
        {16, 4, 3, 12, 6, 0, 3},
        {4, -5, 6, 7, 0, 0, 2},
        {6, 0, -1, -2, 3, 6, 8},
        {5, 3, 4, 0, 0, -2, 7},
        {-1, 7, 4, 0, 7, -5, 6},
        {0, -1, 3, 4, 12, 4, 2}};
    int result[6][7];
    int trait[6] = {0};
    //数塔用data存储,result存放各阶段决策结果的分析,trait记录走过的每个最优路径点位置
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 7; j++)
        {
            result[i][j] = data[i][j];
            printf("%5d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i = 4; i >= 0; i--)
    {
        for (j = 0; j < 7; j++)
        {
            max = data[i + 1][j];
            for (k = -2; k < 2; k++)
            {
                if (j + k >= 0)
                {
                    maxCd = maxfun(result[i + 1][j + k], result[i + 1][j + 2]);
                    if (maxCd > max)
                        max = maxCd;
                }
            }
            result[i][j] = max + data[i][j];
        }
        printf("\n");
    }

    int p_max = result[0][0], max_letter = 0, res;

    for (i = 0; i < 6; i++)
    {
        if (result[0][i] > p_max)
        {
            p_max = result[0][i];
            max_letter = i;
        }
    }
    j = max_letter;

    printf("track:%d", data[0][max_letter]);
    for (i = 0; i < 6; i++)
    {
        res = result[i][j] - data[i][j];
        trait[i] = j;
        for (k = -2; k <= 2; k++)
        {
            if (j + k >= 0 && res == result[i + 1][j + k])
            {
                printf("<--%d", data[i + 1][j + k]);
                j = j + k;
                break;
            }
        }
    }

    printf("\n");
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (j == trait[i])
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
}
int maxfun(int a, int b)
{
    return a > b ? a : b;
}