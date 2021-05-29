#include <stdio.h>
#define N 7
int a[N] = {1, 5, 2, 9, 3, 7, 4};
int divideSum(int low, int high, int *sum);
int main()
{
    int sum = 0;
    divideSum(0, N - 1, &sum);
    printf("%d", sum);
}
int divideSum(int low, int high, int *sum)
{
    int mid;
    if (low == high)
        (*sum) = (*sum) + a[low];
    else if (low == high - 1)
        (*sum) = (*sum) + a[low] + a[high];
    else
    {
        mid = (low + high) / 2;
        divideSum(low, mid, sum);
        divideSum(mid + 1, high, sum);
    }
}