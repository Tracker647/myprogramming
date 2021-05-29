#include <stdio.h>
int main()
{
    int s[12] = {1, 2, 0, 5, 3, 5, 6, 8, 8, 2, 12, 15};
    int f[12] = {3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14, 18};
    int a[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i, j, count = 1;
    for (i = 0; i < 11;)
    {
        for (j = i; j < 12; j++)
        {
            if (f[i] < s[j])
            {
                printf("f[%d]=%d,s[%d]=%d\n", i, f[i], j, s[j]);
                a[i] = 1;
                a[j] = 1;
                count++;
                i = j;
                break;
            }
        }
    }
    printf("maxium amount of event: %d\n", count);
    for (i = 0; i < 12; i++)
    {
        if (a[i] != 0)
            printf("%d ", i + 1);
    }
    printf("\n");

    return 0;
}