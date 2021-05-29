#include <stdio.h>
#define N 7
int a[N] = {1, 5, 2, 9, 3, 7, 4};
int recCount = 0;
int halfIt(int i, int j, int *fmin2, int *fmin1, int *fmax2, int *fmax1);
int minSecond(int lmin1, int lmin2, int rmin1, int rmin2, int *fmin1, int *fmin2);
int maxSecond(int lmax1, int lmax2, int rmax1, int rmax2, int *fmax1, int *fmax2);
int main()
{
    int min2, min1, max2, max1;
    halfIt(0, N - 1, &min2, &min1, &max2, &max1);
    printf("max1=%d max2=%d\n", max1, max2);
    printf("min1=%d min2=%d\n", min1, min2);
}
int halfIt(int i, int j, int *fmin2, int *fmin1, int *fmax2, int *fmax1)
{
    int lmin2, lmin1, rmin2, rmin1;
    int lmax2, lmax1, rmax2, rmax1;
    int mid;
    recCount++;
    printf("function started,current recursion in: %d\n", recCount);
    for (int k = i; k < j + 1; k++)
    {
        printf("%d ", a[k]);
    }
    printf("\n");
    if (i == j)
    {
        *fmin2 = *fmin1 = a[i];
        *fmax2 = *fmax1 = a[i];
    }
    else if (i == j - 1)
    {
        if (a[i] < a[j])
        {
            *fmin2 = a[j];
            *fmin1 = a[i];

            *fmax2 = a[i];
            *fmax1 = a[j];
        }
        else
        {
            *fmin2 = a[i];
            *fmin1 = a[j];

            *fmax2 = a[j];
            *fmax1 = a[i];
        }
    }
    else
    {
        mid = (i + j) / 2;

        halfIt(i, mid, &lmin2, &lmin1, &lmax2, &lmax1);
        printf("leftMin: lmin1=%d lmin2=%d rmin1=%d rmin2=%d\n", lmin1, lmin2, rmin1, rmin2);
        printf("leftMax: lmax1=%d lmax2=%d rmax1=%d rmax2=%d\n", lmax1, lmax2, rmax1, rmax2);

        halfIt(mid + 1, j, &rmin2, &rmin1, &rmax2, &rmax1);
        printf("right: lmin1=%d lmin2=%d rmin1=%d rmin2=%d\n", lmin1, lmin2, rmin1, rmin2);
        printf("rightMax: lmax1=%d lmax2=%d rmax1=%d rmax2=%d\n", lmax1, lmax2, rmax1, rmax2);

        minSecond(lmin1, lmin2, rmin1, rmin2, fmin1, fmin2);
        maxSecond(lmax1, lmax2, rmax1, rmax2, fmax1, fmax2);
        printf("fmin1=%d fmin2=%d\n", *fmin1, *fmin2);
        printf("fmax1=%d fmax2=%d\n", *fmax1, *fmax2);
    }
    recCount--;
}
int minSecond(int lmin1, int lmin2, int rmin1, int rmin2, int *fmin1, int *fmin2)
{
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
            *fmin1 = lmin1;
            *fmin2 = rmin1;
        }
    }
}
int maxSecond(int lmax1, int lmax2, int rmax1, int rmax2, int *fmax1, int *fmax2)
{
    if (lmax1 < rmax1)
    {
        if (rmax1 > lmax2)
        {
            *fmax1 = rmax1;
            *fmax2 = lmax1;
        }
        else
        {
            *fmax1 = rmax1;
            *fmax2 = lmax2;
        }
    }
    else
    {
        if (lmax2 > rmax1)
        {
            *fmax1 = lmax1;
            *fmax2 = lmax2;
        }
        else
        {
            *fmax1 = lmax1;
            *fmax2 = rmax1;
        }
    }
}