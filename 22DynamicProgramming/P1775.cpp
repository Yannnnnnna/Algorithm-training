//
// Created by WYR on 2025/3/17.
//
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int a[305];  //石子数量
int dp[305][305];
int sum[305]; //前缀和
int main(){
    int n;
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n ; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        dp[i][i] = 0;  //长度为1合并不消耗体力
    }
    int j;
    //长度为2开始合并
    for (int len = 2; len <=n ; ++len) {
//        合并len长度的堆
        for (int i = 1; i+len - 1 <= n ; ++i) {
            j = i +len - 1;
            //划分，计算那种划分方式结果最小
            for (int k = i; k +1 <= j ; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+ 1][j] + (sum[j] - sum[i - 1]));
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}

