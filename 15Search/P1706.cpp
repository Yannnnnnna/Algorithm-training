//
// Created by WYR on 2025/3/3.
//时间复杂度O(n!)
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int res[15];    //存储结果
bool visit[15]; //标记是否访问过
int n;
void dfs(int k){
    if(k > n){
        for (int i = 1; i <= n; ++i) {
            printf("%5d", res[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if(visit[i] == false){
            visit[i] = true;  //标记为访问过
            res[k] = i;
            dfs(k + 1);
            visit[i] = false;   //标记为未访问,避免影响下一次回溯
        }
    }
}
int main(){
    scanf("%d", &n);
    dfs(1);
    return 0;
}