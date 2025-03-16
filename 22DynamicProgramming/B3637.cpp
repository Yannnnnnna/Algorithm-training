//
// Created by WYR on 2025/3/16.
//
#include <iostream>
#include <cstdio>
using namespace std;
int n, a[5005], dp[5005],ans;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n ; ++i) {
        scanf("%d", &a[i]);
        dp[i] = 1;
    }
    for (int i = 2; i <= n ; ++i) {
        //在前面每一个子序列尝试接上当前数字，是否符合条件
        for (int j = 1; j <= i - 1 ; ++j) {
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (int i = 1; i <= n ; ++i) {
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}