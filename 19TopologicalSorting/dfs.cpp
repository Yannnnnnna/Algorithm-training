//
// Created by WYR on 2025/3/12.
//
#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#define maxn 5005
using namespace std;
int n, m;
struct edge{
    int to, next;
}e[maxn];
int cnt;  //边集数组下标
int head[maxn];
int visit[maxn]; //访问数组
int topo[maxn], k;//拓扑数组和下标
int flag;
stack<int> s;
void add(int x, int y){
    cnt++;
    e[cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;

}
void dfs(int u){
    visit[u] = 1;  //处于搜索中
    int v;
    for(int i = head[u]; i != -1; i++){
        v = e[i].to;
        if(visit[v] == 1){
            flag = 1;  //有环
            return;
        }
        else if(visit[v] == 0){
            dfs(v);
            if(flag == 1){
                return;
            }
        }
    }
    visit[u] = 2; //完成搜索
    s.push(u);
}
int main() {
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    int x, y;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0) {
            dfs(i);
        }
    }
    if(flag == 0){
        while (!s.empty()){
            printf("%d ", s.top());
            s.pop();
        }
    } else{
        printf("有环\n");
    }

    return 0;
}