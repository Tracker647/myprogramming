#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 7
int maxMin2(int *a, int i, int j, int *max1, int *max2, int *min1, int *min2);
int max(int a, int b);
int min(int a, int b);
int main()
{
    // int *a;
    int i, n;
    int max1, max2, min1, min2;

    // scanf("%d",&n);
    // a=(int *)malloc(sizeof(int)*n);
    // srand((unsigned int)time(0));
    // for(i=0;i<n;i++) a[i]=rand()%91+10;
    int a[N] = {2, 5, 1, 9, 7, 3, 4};
    for (i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
        if ((i + 1) % 5 == 0)
            printf("\n");
    }
    printf("\n\n");
    maxMin2(a, 0, N - 1, &max1, &max2, &min1, &min2);
    printf("%d %d\n%d %d\n", max1, max2, min1, min2); /**/
    return 0;
}
int maxMin2(int *a, int i, int j, int *max1, int *max2, int *min1, int *min2)
{
    int mid, t;
    int lmax1, lmax2, lmin1, lmin2, rmax1, rmax2, rmin1, rmin2;
    if (j - i == 2)
    {
        *max1 = max(a[j], max(a[i], a[i + 1]));
        *min1 = min(a[j], min(a[i], a[i + 1]));
        t = a[i] + a[j] + a[i + 1];
        *max2 = t - *max1 - *min1;
        *min2 = *max2;
        return 0;
    }
    else if (j - i == 1)
    {
        if (a[i] > a[j])
        {
            *max1 = a[i];
            *max2 = a[j];
            *min1 = a[j];
            *min2 = a[i];
            return 0;
        }
        else
        {
            *max1 = a[j];
            *max2 = a[i];
            *min1 = a[i];
            *min2 = a[j];
            return 0;
        }
    }
    else
    {
        mid = i + (j - i) / 2;
        maxMin2(a, i, mid, &lmax1, &lmax2, &lmin1, &lmin2);
        maxMin2(a, mid + 1, j, &rmax1, &rmax2, &rmin1, &rmin2);
        if (lmax1 > rmax1)
        {
            *max1 = lmax1;
            if (lmax2 > rmax1)
                *max2 = lmax2;
            else
                *max2 = rmax1;
        }
        else
        {
            *max1 = rmax1;
            if (lmax1 > rmax2)
                *max2 = lmax1;
            else
                *max2 = rmax2;
        }
        if (lmin1 < rmin1)
        {
            *min1 = lmin1;
            if (lmin2 < rmin1)
                *min2 = lmin2;
            else
                *min2 = rmin1;
        }
        else
        {
            *min1 = rmin1;
            if (lmin1 < rmin2)
                *min2 = lmin1;
            else
                *min2 = rmin2;
        }
    }
    return 0;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}