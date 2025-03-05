//
// Created by WYR on 2025/3/5.
// 邻接表用二维vector实现
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
vector<vector<int>> adj;
int n, m;
int v[105];
void dfs(int u){
    if(v[u] == 1){
        return;
    }
    printf("%d\n", u);
    v[u] = 1;
    for (int i = 0; i < adj[u].size(); ++i) {
        int t = adj[u][i];
        if(v[t] == 0){
            dfs(t);
        }
    }
}
int main(){

    int x, y;
    scanf("%d%d", &n, &m);
    adj.resize(n + 1);  //邻接表
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
       if(v[i] == 0){
           dfs(i);
       }
    }
}