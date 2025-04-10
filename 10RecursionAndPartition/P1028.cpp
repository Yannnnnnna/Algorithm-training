//
// Created by WYR on 2025/4/10.
//用记忆化搜索简化递归次数
#include <bits/stdc++.h>
using namespace std;
int a[105];
int dfs(int n){
    if(n == 1) return 1;
    if(a[n] != 0)return a[n];
    int cnt = 1; //从头开始记录
    for (int i = 1; i <= n/2 ; ++i) {
        cnt+=dfs(i);
    }
    a[n] = cnt;
    return a[n];
}
int main(){
    int n;
    cin >> n;
    cout << dfs(n);
    return 0;
}