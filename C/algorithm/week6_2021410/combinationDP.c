#include <stdio.h>
int main()
{
    int m, n, i, j, dp[205][8] = {0};
    printf("input m,n(m<=n):\n");
    scanf("%d %d", &m, &n);
    for (i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m && j <= i; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

    printf("%5d ", dp[n][m]);
}