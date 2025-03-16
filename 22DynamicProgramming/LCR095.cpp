//
// Created by WYR on 2025/3/16.
//
#include <iostream>
#include <cstdio>

using namespace std;
int dp[1005][1005];
int longestCommonSubsequence(string text1, string text2) {
    int l1 = text1.length();
    int l2 = text2.length();
    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            if(text1[i - 1] == text2[j - 1]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            } else{
                dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
            }

        }
    }
    return dp[l1][l2];
}
int main(){
    string l1, l2;
    cin >> l1 >> l2;
    cout << longestCommonSubsequence(l1,l2)<< endl;
    return 0;
}