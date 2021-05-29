#include <stdio.h>
#define N 7
int a[N] = {1, 5, 2, 9, 3, 7, 4};
int findMin(int n);
int halfIt(int low, int high, int *fmin);
int main()
{
    int min;
    min = findMin(N);
    printf("%d", min);
}
int findMin(int n)
{
    int min;
    halfIt(0, n - 1, &min);
    return min;
}
int halfIt(int low, int high, int *fmin)
{
    int lmin = -1, rmin = -1, mid = -1;
    printf("low=%d  high=%d\n", low, high);
    if (low == high)
        *fmin = a[low];
    else if (low == high - 1)
    {
        if (a[low] < a[high])
            *fmin = a[low];
        else
            *fmin = a[high];
    }
    else
    {
        mid = (low + high) / 2;
        halfIt(low, mid, &lmin);
        printf("left: lmin=%d a[mid]=%d rmin=%d\n", lmin, a[mid], rmin);
        halfIt(mid + 1, high, &rmin);
        printf("right: lmin=%d a[mid]=%d rmin=%d\n", lmin, a[mid], rmin);
        if (lmin < rmin)
        {
            *fmin = lmin;
        }
        else
        {
            *fmin = rmin;
        }
    }
}