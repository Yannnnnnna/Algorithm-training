//
// Created by WYR on 2025/3/12.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

#define maxn 5005
using namespace std;
int n, m;
struct edge{
    int to, next;
}e[maxn];
int cnt;  //边集数组下标
int head[maxn];
int ind[maxn]; //入度数组
int topo[maxn], k;//拓扑数组和下标
void add(int x, int y){
    cnt++;
    e[cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;

}
bool kahn() {
    int u, v;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        u = q.front();
        q.pop();
        k++;
        topo[k] = u;
        for (int i = head[u]; i != -1; i = e[i].next) {
            v = e[i].to;
            ind[v]--;
            if (ind[v] == 0) {
                q.push(v);
            }


        }
    }
    if (k == n) {
        return 1;
    } else {
        return 0;
    }
}
    int main()
    {
        scanf("%d%d", &n, &m);
        memset(head, -1 , sizeof(head));
        int x, y;
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &x, &y);
            add(x, y);
            ind[y]++;
        }
        if(kahn()){
            for(int i = 1; i <= k; i++){
                printf("%d ", topo[i]);
            }
        }else{

            printf("有环\n");
        }
        return 0;
    }