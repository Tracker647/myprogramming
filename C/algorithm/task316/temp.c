#include <stdio.h>
int main()
{
    int a[4] = {7, 2, 2, -1};
    int b[3] = {2, 2, -1};
    int c[5] = {6, 4, 4, 4, -1};
    int d[5] = {4, 4, 4, 0, -1};
    int s[6] = {0, 4, 8, 8, 4, -1};
    int *p[5] = {a, b, c, d, s};
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; p[i][j] != -1; j++)
        {
            printf("%d", p[i][j]);
        }
        printf("\n");
    }
}