#include <stdio.h>
#define N 5
#define M 4
int fx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, fy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int a[N][M];
int dep, x, y, count;
void find(int x, int y, int dep);
void output();
int check(int x, int y);
int main()
{
    int i, j;
    int count = 0;
    int dep = 2;
    printf("input the coordination of the horse:\n");
    scanf("%d %d", &x, &y);
    if (x > N - 1 || y > M - 1 || x < 0 || y < 0)
    {
        printf("x,y error!");
        return 0;
    }
    for (i = 1; i <= N; i++)
        for (j = 1; j <= M; j++)
            a[i][j] = 0;
    a[x][y] = 1;
    find(x, y, dep);
    if (count == 0)
        printf("Non solution!");
    else
        printf("Total %d ways", count);
}
void find(int x, int y, int dep)
{
    int i, nextX, nextY;
    for (i = 0; i < 8; i++)
    {
        nextX = x + fx[i];
        nextY = y + fy[i];
        if (check(nextX, nextY) == 1)
        {
            a[nextX][nextY] = dep;

            int i1 = 0, j1 = 0;
            // printf("next move:\n");
            // for (i1 = 0; i1 < N; i1++)
            // {
            //     for (j1 = 0; j1 < M; j1++)
            //     {
            //         printf("%5d ", a[i1][j1]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");

            if (dep == N * M)
                output();
            else
                find(nextX, nextY, dep + 1);
            a[nextX][nextY] = 0;
        }
    }
}
void output()
{
    count++;
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int check(int x, int y)
{
    if (x > N - 1 || y > M - 1 || x < 0 || y < 0 || a[x][y] != 0)
    {
        return 0;
    }
    return 1;
}