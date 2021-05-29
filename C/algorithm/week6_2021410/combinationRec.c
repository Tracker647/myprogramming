#include <stdio.h>
int A(int m, int n);
int C(int m, int c);
int main()
{
    int m = 4, n = 7;
    printf("C(%d,%d) = %d", m, n, C(m, n));
}
int A(int m, int n)
{
    int res = 1;
    int k = n;
    for (int i = 0; i < m; i++)
    {
        res = res * k;
        k--;
    }
    return res;
}
int C(int m, int n)
{
    if (m > n)
        return;
    else if (m == 1)
        return n;
    else
        return C(1, n) * C(m - 1, n - 1) / m;
}