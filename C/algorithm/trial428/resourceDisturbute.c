#include <stdio.h>
#define M 3 //项目数
#define N 7 //N万元
double profit[M][N + 1] = {
    {0.00, 0.11, 0.13, 0.15, 0.21, 0.24, 0.30, 0.35},
    {0.00, 0.12, 0.16, 0.21, 0.23, 0.25, 0.21, 0.34},
    {0.00, 0.08, 0.12, 0.20, 0.24, 0.26, 0.30, 0.35}};
double bestgain[M] = {0}; //第M个项目获得最大收益
int invest[M] = {0};      //获得最大收益时每个项目的投资量
double f(int i, int j);
double g(int i, int j); //i = 1,2,...m j = 0,1,2,...n
int main()
{
    f(M, N);
}
double f(int i, int j) //向i个项目投入j万元所获得的最大总收益
{
    int k;
    double maxGain = 0, gain;
    if (i == 1 && j >= 0)
    {
        return g(i, j);
    }
    else if (i > 1 && j >= 0)
    {
        for (k = 0; k <= N; k++)
        {
            if (j - k >= 0)
            {
                gain = g(i, k) + f(i - 1, j - k);
                printf("f(%d,%d) = g(%d, %d) + f(%d, %d) = %lf\n", i, j, i, k, i - 1, j - k, gain);
                if (gain > maxGain)
                {
                    maxGain = gain;
                }
            }
        }
        printf("maxGain in f(%d,%d) is %lf\n", i, j, maxGain);
        return maxGain;
    }
    else
    {
        printf("error\n");
        return;
    }
}
double g(int i, int j)
{
    return profit[i - 1][j];
}