#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 3
#define K 3
#define N 2
int main()
{
    int a[M][K] = {
        0},
        b[K][N] = {0}, c[M][N] = {0};
    int i, j, k;

    srand(time(NULL));

    //随机生成矩阵A
    printf("Matrix A:\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < K; j++)
        {
            a[i][j] = rand() % 10;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    //随机生成矩阵B
    printf("Matrix B:\n");
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            b[i][j] = rand() % 10;
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    //矩阵乘法
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {

            for (k = 0; k < K; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
                printf("%d * %d", a[i][k], b[k][j]);
                if (k != K - 1)
                    printf(" + ");
            }
            printf(" = %d ", c[i][j]);
            printf("\n");
        }
    }

    printf("Matrix C:\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}