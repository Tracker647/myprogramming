#include <stdio.h>
int f(int n, int k);
int main()
{
    int n = 15, k = 3;
    printf("%d", f(n, k));
}
int f(int n, int k)
{
    if (n == 0 || n < k || k == 0)
        return 0;
    else if (n == k || k == 1)
        return 1;
    else
        return f(n - 1, k - 1) + f(n - k, k);
}