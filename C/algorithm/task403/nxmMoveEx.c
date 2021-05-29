#include <stdio.h>
int main(void)
{
    int array1[6][7] = {
        {16, 4, 3, 12, 6, 0, 3},
        {4, -5, 6, 7, 0, 0, 2},
        {6, 0, -1, -2, 3, 6, 8},
        {5, 3, 4, 0, 0, -2, 7},
        {-1, 7, 4, 0, 7, -5, 6},
        {0, -1, 3, 4, 12, 4, 2}};
    int b[6][7], c[6][7];
    int i, j, k;
    int max;
    int flag;

    for (i = 0; i < 6; i++)
        for (j = 0; j < 7; j++)
        {
            b[i][j] = array1[i][j];
            c[i][j] = -1;
        }
    for (i = 1; i < 5; i++)
    {
        for (j = 0; j < 7; j++)
        {
            max = 0;
            for (k = j - 2; k <= j + 2; k++)
            {
                if (k < 0)
                    continue;
                else if (k > 6)
                    break;
                else
                {
                    if (b[i][j] + b[i - 1][k] > max)
                    {
                        max = b[i][j] + b[i - 1][k];
                        flag = k;
                    }
                }
            }
            b[i][j] = max;
            c[i][j] = flag;
        }
    }

    for (j = 1; j <= 5; j++) //i=5
    {
        max = 0;
        for (k = j - 2; k <= j + 2; k++)
        {
            if (k < 0)
                continue;
            else if (k > 6)
                break;
            else
            {
                if (b[i][j] + b[i - 1][k] > max)
                {
                    max = b[i][j] + b[i - 1][k];
                    flag = k;
                }
            }
        }
        b[i][j] = max;
        c[i][j] = flag;
    }

    max = 0;
    for (j = 1; j <= 5; j++) //找出
    {
        if (b[i][j] > max)
        {
            max = b[i][j];
            flag = j;
        }
    }
    printf("the maxium sum from bottom to top: %d\n\n", max);
    printf("pick number from bottom to top:");
    printf("%d", array1[i][flag]);
    for (j = i; j > 0; j--)
    {
        flag = c[j][flag];
        printf("%5d", array1[j - 1][flag]);
    }
    printf("\n");
    return 0;
}
