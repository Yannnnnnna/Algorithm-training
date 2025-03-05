//
// Created by WYR on 2025/3/5.
//
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to; //终点
    int w;  //边权
    int next;   //具有相同起点的下一条边

}edge[10005];
int head[105];  //head[i]表示以i为起点的第一条边
int n,m;    //n个点，m条边
int cut;    //边的数量
int v[105]; //标记是否访问过
void add(int x, int y, int w){
    edge[cut].to = y;
    edge[cut].w = w;
    edge[cut].next = head[x];
    head[x] = cut++;
}
void dfs(int i){
    if (v[i] == 1) {
        return;
    }
    printf("%d\n", i);
    v[i] = 1;
    for (int j = head[i]; j != -1 ; j = edge[j].next) {
        if(v[edge[j].to] == 0){
            dfs(edge[j].to);
        }

    }
}
int main(){
    int x, y, w;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    cut = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &x, &y, &w);
        add(x, y, w);
        add(y, x, w);

    }
    for (int i = 1; i <= n; ++i) {
        if(v[i] == 0){
            dfs(i);
        }
    }
    return 0;
}