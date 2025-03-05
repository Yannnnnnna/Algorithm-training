//
// Created by WYR on 2025/3/5.
// 将 n写成 k个数相加的形式
//
#include <iostream>
#include <algorithm>
#include<cstring>
#include <vector>
#include <cstdio>

using namespace std;

int n, k, res = 0;
//sum:当前和，cur:当前加到第几个数，last:上一个数
void dfs(int sum, int cur, int last){
    if(cur == k){
        if(sum == n){
            res++;
        }
        return;
    }
    for (int i = last; sum + i * (k - cur) <= n; ++i) {
        dfs(sum + i, cur + 1, i);
    }
}
int main(){
    scanf("%d%d", &n, &k);
    dfs(0,0,1);
    printf("%d\n", res);
    return 0;

}