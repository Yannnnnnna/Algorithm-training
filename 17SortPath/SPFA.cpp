//
// Created by WYR on 2025/3/9.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
int n,m, s;
int dis[105];
int use[105]; //记录点的访问次数，最多n - 1次，如果超过n - 1次，则说明存在负环
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

int flag[105];  //标记是否访问过
void spfa(){
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(head, -1, sizeof(head));
    dis[s] = 0;
    flag[s] = 1;   //标记s是否在队列中, 标记在上一轮中有没有被松弛
    q.push(s);
    use[s]++;
    while (q.empty()){
        int x = q.front();
        q.pop();
        flag[x] = 0;
        for (int i = head[x]; i != -1 ; i = e[i].next) {
            int y = e[i].to;
            if(flag[y] == 0 && dis[y] > dis[x] + e[x].w){
                dis[y] = dis[x] + e[x].w;
                q.push(y);
                ++use[y];
                flag[y] = 1;
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
    spfa();
    for (int i = 1; i <= n; ++i) {
        printf("%d ", dis[i]);
    }
    return 0;
}
