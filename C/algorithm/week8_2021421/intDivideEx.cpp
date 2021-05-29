#include<iostream>
using namespace std;
const int MAXN = 55;

int dp1[MAXN][MAXN] = { 0 };
void init1(int maxn)
{
    // DP状态设计，dp[n][k]表示数字n，被划分成k个数的组合情况数,初始化为0
    // 定下了K个数，那么以这K个数中包不包括1分为两个情况，这样都能做状态转移
    for (int n = 1; n <= maxn; n++) {
        for (int k = 1; k <= maxn; k++) {

            // 1. k=1时只有一种,{n}
            // 2. k=n时只有一种,{1,1,1,,,,,,}
            if (k == 1 || k == n) dp1[n][k] = 1;

            // 1. 这k个数字中没有1, dp[n-k][k]为每个数字减1的情况数
            // 2. 这k个数字中有1, dp[n-1][k-1]该情况下加上数字1
            if (n > k) dp1[n][k] = dp1[n - k][k] + dp1[n - 1][k - 1];

            // n < k 为0
        }
    }
}

int init2(int maxn)
{

}

int main()
{
    init1(50);

    int n, k;
    while (cin >> n >> k) {
        cout << dp1[n][k] << endl;
    }
    return 0;
}