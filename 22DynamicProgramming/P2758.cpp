//
// Created by WYR on 2025/3/16.
//
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char a[2005], b[2005];
int dp[2005][2005];
int main(){
    std::scanf("%s", a + 1);
    getchar();
    scanf("%s", b + 1);
    int al = strlen(a + 1);
    int bl = strlen(b + 1);
    //初始化
    for (int i = 1; i <= al ; ++i) {
        dp[i][0] = i;  //把a字符串全部删掉
    }
    for (int i = 1; i <= bl ; ++i) {
        dp[0][i] = i;  //把空串转化成有字符的串，全部添加操作
    }
    for (int i = 1; i <= al; ++i) {
        for (int j = 1; j <=bl ; ++j) {
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1];
            } else{
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j -1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    cout << dp[al][bl];
    return 0;
}