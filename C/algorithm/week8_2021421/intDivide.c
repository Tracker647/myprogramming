#include <stdio.h>
#define N 128
int dp[N][N] = {0};
int DP(int n, int m)
{
    // 不合法情况
    if (n <= 0 || m <= 0)
        return 0;

    // 记忆化
    if (dp[n][m] > 0)
        return dp[n][m];

    // 1. n=1只有一种{1};
    // 2. m=1只有一种{1,1,1,,,,,,}
    if (n == 1 || m == 1)
        return dp[n][m] = 1;

    // 1. 包含m只有一种{m}
    // 2. 不包含m, dp[n][m-1]
    // n==m,这两种情况为所有情况
    if (n == m)
        return dp[n][m] = 1 + DP(n, m - 1);

    // m最大也只能是n
    if (n < m)
        return dp[n][m] = DP(n, n);

    // 1. 包含m, 将最后一个数定为m, dp[n-m][m]
    // 2. 不包含m, 最大的数为m-1, do[n][m-1]
    // n>m,这两种情况为所有情况
    if (n > m)
        return dp[n][m] = DP(n - m, m) + DP(n, m - 1);

    // 不合法情况
    return dp[n][m] = 0;
}
int main()
{
    int n;
    printf("input n:\n");
    scanf("%d", &n);
    DP(n, n);
    printf("total is %d", dp[n][n]);
    return 0;
}