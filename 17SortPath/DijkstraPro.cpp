//
// Created by WYR on 2025/3/9.
// 优化版Dijkstra算法
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int, int> PII;
int n,m, s;
int dis[105];
struct edge{
    int to,next,w;
}e[10005];
int head[105]; //head[i]表示以i为起点的第一条边
int cnt;   //边的数量
//链式前向星存储边
void add(int x, int y, int w){
   e[cnt].to = y;
   e[cnt].w = w;
   e[cnt].next = head[x];
   head[x] = cnt;
   ++cnt;
}
//优先队列,first存储距离，second存储点
priority_queue<PII, vector<PII>, greater<PII>> q;
int flag[105];  //标记是否访问过
void Dijkstra(){
    //初始化dis数组为无穷大
    memset(dis, 0x3f, sizeof(dis));
    memset(head, -1, sizeof(head));
    dis[s] = 0; //起点到自己的距离为0
    q.push({0, s}); //将起点加入队列
    while (q.size()){
        PII t = q.top();
        q.pop();
        int x = t.second;
        int dist = t.first;
        //如果该点已经访问过，则跳过
        if(flag[x] == 1) continue;
        flag[x] = 1;
        //遍历以x为起点的边
        for (int i = head[x]; i != -1 ; i = e[i].next) {
            int y = e[i].to;
            //如果y未访问过且dis[y] > dis[x] + e[i].w,则更新dis[y]
            if(flag[y] == 0 && dis[y] > dis[x] + e[i].w){
                dis[y] = dis[x] + e[i].w;
                q.push({dis[y], y});
            }
        }
    }

}
int main(){
    scanf("%d%d", &n, &m);
    scanf("%d", &s);
    int x, y, w;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &x, &y, &w);
        add(x, y, w);
    }
    Dijkstra();
    for (int i = 1; i <= n; ++i) {
        printf("%d ", dis[i]);
    }
    return 0;
}
