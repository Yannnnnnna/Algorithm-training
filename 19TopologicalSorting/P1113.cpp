//
// Created by WYR on 2025/3/12.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAXN 10005
using namespace std;
int cnt;
struct edge{
    int to, next;
}e[1000005];
int head[MAXN];

int ido[MAXN];//入度
int tim[MAXN]; //每个任务花费的时间
int finish[MAXN]; //每个任务完成的时间
void add(int x, int y){
    cnt++;
    e[cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}
int n,m;
void kahn(){
    queue<int> q;
    for (int i = 1; i <= n ; ++i) {
        if(ido[i] == 0){
            q.push(i);
            finish[i] = tim[i];
        }
    }
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = head[x]; i != -1 ; i = e[i].next) {
            int y = e[i].to;
            finish[y] = max(finish[y], finish[x] + tim[y]);
            ido[y]--;
            if(ido[y] == 0){
                q.push(y);
            }
        }
    }
}
int main(){
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    int x, y, w;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &y);
        scanf("%d", &w);
        tim[y] = w;
        while (1){
            scanf("%d", &x);
            if(x ==0){
                break;
            }
            add(x, y);
            ido[y]++;
        }

    }
    kahn();
    int ans = 0;
    for (int i = 1; i <= n ; ++i) {
        ans = max(ans, finish[i]);
    }
    printf("%d", ans);

    return 0;
}