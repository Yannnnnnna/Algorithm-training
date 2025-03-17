//
// Created by WYR on 2025/3/17.
//
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int t, n;
int w[1005], v[1005];//采药时间 采药价值
int dp[1005];
int main(){
    cin >> t >> n;
    for (int i = 1; i <= n ; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n ; ++i) {
        for (int j = t ; j >= w[i] ; j--) {
            dp[j] = max(dp[j], dp[j - w[i]]+ v[i]);
        }
    }
    cout << dp[t] <<endl;
    return 0;
}