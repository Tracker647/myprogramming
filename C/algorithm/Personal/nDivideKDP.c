#include <stdio.h>
int n, k, d[205][8];
int main()
{
    int n = 7, k = 3; ///把n整数划分成k份
    d[0][0] = 1;      //边界
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i && j <= k; j++)       //划分次数不能超过数本身，也不能超过求的划分次数
            d[i][j] = d[i - 1][j - 1] + d[i - j][j]; //递推计算

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
            printf("%5d ", d[n][k]);
        printf("\n");
    }
    return 0;
}
