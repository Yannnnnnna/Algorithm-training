//
// Created by WYR on 2025/3/17.
//
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char s[55];
int n;
int dp[55][55];
int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    memset(dp, 0x3f, sizeof(dp));
    //初始化
    for (int i = 1; i <= n ; ++i) {
        dp[i][i] = 1;
    }
    //枚举长度
    for (int len = 2; len <= n ; ++len) {
        //枚举左端点
        for (int i = 1; i + len - 1 <= n ; ++i) {
            //确定右端点
            int j = i + len - 1;
            //左右端点相同
            if(s[i] == s[j]){
                //aba == ab || ba
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
            }else{
                //左右端点不同，枚举两个点之间的断点
                for (int k = i; k + 1<= j ; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }

        }
    }
    cout << dp[1][n] << endl;
    return 0;
}