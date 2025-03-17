//
// Created by WYR on 2025/3/17.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int t, n;
int w[10005], v[10005];//采药时间 采药价值
int dp[10000005];
signed main(){
    cin >> t >> n;
    for (int i = 1; i <= n ; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n ; ++i) {
        for (int j = w[i] ; j <= t; j++) {
            dp[j] = max(dp[j], dp[j - w[i]]+ v[i]);
        }
    }
    cout << dp[t] <<endl;
    return 0;
}