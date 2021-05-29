#include <stdio.h>
#define N 7
int a[N] = {1, 5, 6, 9, 3, 7, 4};
int recCount = 0;
int findSecond(int n);
int halfIt(int i, int j, int *fmin2, int *fmin1);
int main()
{
    int min2;
    min2 = findSecond(N);
    printf("%d", min2);
}
int findSecond(int n)
{
    int min2, min1;
    halfIt(0, n - 1, &min2, &min1);
    printf("min1=%d min2=%d\n", min1, min2);
    return min2;
}
int halfIt(int i, int j, int *fmin2, int *fmin1)
{
    int lmin2, lmin1, rmin2, rmin1;
    int mid;
    recCount++;
    printf("function started,current recursion in: %d\n",recCount);
    for (int k = i; k < j + 1; k++)
    {
        printf("%d ", a[k]);
    }
    printf("\n");
    if (i == j)
        *fmin2 = *fmin1 = a[i];
    else if (i == j - 1)
    {
        if (a[i] < a[j])
        {
            *fmin2 = a[j];
            *fmin1 = a[i];
        }
        else
        {
            *fmin2 = a[i];
            *fmin1 = a[j];
        }
    }
    else
    {
        mid = (i + j) / 2;
        halfIt(i, mid, &lmin2, &lmin1);
        printf("left: lmin1=%d lmin2=%d rmin1=%d rmin2=%d\n", lmin1, lmin2, rmin1, rmin2);
        halfIt(mid + 1, j, &rmin2, &rmin1);
        printf("right: lmin1=%d lmin2=%d rmin1=%d rmin2=%d\n", lmin1, lmin2, rmin1, rmin2);
        if (lmin1 < rmin1)
        {
            if (lmin2 < rmin1)
            {
                *fmin1 = lmin1;
                *fmin2 = lmin2;
            }
            else
            {
                *fmin1 = lmin1;
                *fmin2 = rmin1;
            }
        }
        else
        {
            if (rmin2 < lmin1)
            {
                *fmin1 = rmin1;
                *fmin2 = rmin2;
            }
            else
            {
                *fmin1 = rmin1;
                *fmin2 = lmin1;
            }
        }
        printf("fmin1=%d fmin2=%d\n", *fmin1, *fmin2);
    }
    recCount--;
}