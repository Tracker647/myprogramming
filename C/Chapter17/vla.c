#include<stdio.h>

const int n = 3;

void gaussin(double a[n][n], double b[n])
{
    //判断能否用高斯消元法，如果矩阵主对角线上有0元素存在是不能用的
    for (int i = 0; i < n; i++)
        if (a[i][i] == 0)
        {
           printf("can't use gaussin meathod.\n"); 
           return 0;
        }

    int i, j, k;
    double c[n];    //存储初等行变换的系数，用于行的相减
    //消元的整个过程如下，总共n-1次消元过程。
    for (k = 0; k < n - 1; k++)
    {
        //求出第K次初等行变换的系数
        for (i = k + 1; i < n; i++)
            c[i] = a[i][k] / a[k][k];

        //第K次的消元计算
        for (i = k + 1; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                a[i][j] = a[i][j] - c[i] * a[k][j];
            }
            b[i] = b[i] - c[i] * b[k];
        }
    }

//解的存储数组
    double x[n];
    //先计算出最后一个未知数；
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    //求出每个未知数的值
    for (i = n - 2; i >= 0; i--)
    {
        double sum = 0;
        for (j = i + 1; j < n; j++)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }

    printf("the solution of the equations is:");
    printf("\n");
    for (i = 0; i < n; i++)     
        printf("%d", x[i]); 

}