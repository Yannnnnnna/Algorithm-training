//
// Created by WYR on 2025/4/10.
//
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6+7;
int n,m,a[105];
int dp[105][105];
int main(){
    cin >>n >> m;
    for (int i = 1; i <=n ; ++i) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    /*对于第 i 种花，我们可以选择摆放 k 盆（0 ≤ k ≤ min(a_i, j)），此时：
        剩余盆数 ：j - k 盆需要由前 i-1 种花摆放。
        方案数叠加 ：所有可能的 k 值对应的前 i-1 种花的方案数之和，即为当前状态的值。*/
    for (int i = 1; i <= n ; ++i) {
        for (int j = 0; j <=m ; ++j) {
            for (int k = 0; k <= min(a[i], j); ++k) {
                dp[i][j] = (dp[i - 1][j - k]  + dp[i][j])% mod;
            }
        }
    }
    cout << dp[n][m];
    return 0;
}