//
// Created by WYR on 2025/3/10.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#define PII pair<int, int>
using namespace std;
int n,m;    //n个点，m条边
int nodeWeight[1005];  //点权
int head[1005]; //head[i]表示以i为起点的第一条边
int dist[1005]; //存储起点到各个点的距离
struct edge{
    int to, w, next;
}edge[20005];
int cnt;    //边的数量
void add(int x, int y, int w){
    edge[cnt].to = y;
    edge[cnt].w = w;
    edge[cnt].next = head[x];
    head[x] = cnt++;
}
int flag[1005]; //标记是否在队列中
void dijkstra(int s){
    priority_queue<PII, vector<PII>, greater<PII>> q;
    dist[s] = 0;
    q.push({0, s});

    while (!q.empty()){
        PII t = q.top();
        q.pop();
        int x = t.second;
        if(flag[x] == 1) continue;
        flag[x] = 1;
        for (int i = head[x]; i != -1 ;i = edge[i].next) {
            int y = edge[i].to;
            int w = edge[i].w;
            if(flag[y] == 0 && dist[y] > dist[x] + w){
                dist[y]  = dist[x] + w;
                q.push({dist[y], y});

            }
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    memset(dist, 0x3f, sizeof(dist));
    //读入点权
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nodeWeight[i]);
    }
    //读入边
    for (int i = 1; i <= m; ++i) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        add(x, y, w + nodeWeight[y]);
        add(y, x, w + nodeWeight[x]);
    }
    //Dijkstra算法
    dijkstra(1);
    printf("%d\n", dist[n] - nodeWeight[n]);
    return 0;
}