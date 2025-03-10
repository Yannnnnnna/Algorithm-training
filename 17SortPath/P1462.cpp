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
#define  MAXN 10005
#define MAXM 50005
int n,m, b;    //n个点，m条边, b表示血条
int f[MAXN];  //点权
int head[MAXN]; //head[i]表示以i为起点的第一条边
int dist[MAXN]; //存储起点到各个点的距离
struct edge{
    int to, w, next;
}edge[2 * MAXM];
int cnt;    //边的数量
void add(int x, int y, int w){
    edge[cnt].to = y;
    edge[cnt].w = w;
    edge[cnt].next = head[x];
    head[x] = cnt++;
}
int flag[MAXN];
int check(int mid){
    //起点走不出去
    if(mid < f[1]) {
        return 0;
    }
    memset(dist, 0x3f, sizeof(dist));
    memset(flag, 0, sizeof(flag));
    priority_queue<PII, vector<PII>, greater<PII>> q;
    dist[1] = 0;
    q.push({0, 1});
    while (!q.empty()){
        PII t = q.top();
        q.pop();
        int x = t.second;
        if(flag[x] == 1) continue;
        flag[x] = 1;
        for (int i = head[x]; i != -1 ;i = edge[i].next) {
            int y = edge[i].to;
            int w = edge[i].w;
            //交得起过路费才能走
            if(mid >= f[y] && flag[y] == 0 && dist[y] > dist[x] + w){
                dist[y]  = dist[x] + w;
                q.push({dist[y], y});

            }
        }
    }
    /*血量不为负数*/
    if(dist[n] <= b){
        return 1;
    } else{
        return 0;
    }
}
int main(){
    scanf("%d%d%d", &n, &m, &b);
    memset(head, -1, sizeof(head));

    int maxNode = 1;
    //读入点权
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &f[i]);
        maxNode = max(maxNode, f[i]);
    }
    //读入边
    for (int i = 1; i <= m; ++i) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        if(x == y) continue;
        add(x, y, w);
        add(y, x, w);

    }
    //Dijkstra算法
   if(check(maxNode) == 0){
       printf("AFK\n");
       return 0;
   } else{
        //进行二分搜索
        int l = 1, r = maxNode, ans = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(check(mid)){
                r = mid -1;
                ans = mid;
            } else{
                l  = mid + 1;
            }
        }
        printf("%d\n", ans);
   }
    return 0;
}