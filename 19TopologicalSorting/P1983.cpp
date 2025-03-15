//
// Created by WYR on 2025/3/12.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAXN 1005
using namespace std;
int cnt;
struct edge{
    int to, next;
}e[1000005];
int head[MAXN];

int ido[MAXN];//入度
int leval[MAXN]; //等级
int visit[MAXN][MAXN]; //标记i- j 是否已经建立边
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
            leval[i] = 1;
        }
    }
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = head[x]; i != -1 ; i = e[i].next) {
            int y = e[i].to;
            leval[y] = max(leval[y], leval[x] + 1);
            ido[y]--;
            if(ido[y] == 0){
                q.push(y);
            }
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    memset(head, -1, sizeof(head));
    int s;  //停靠站点
    int isStop[MAXN];    //是否停靠站点i
    int start, end;
    int tmp;
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &s);
        memset(isStop, 0, sizeof(isStop));
        for (int j = 1; j <= s ; ++j) {
            scanf("%d", &tmp);
            isStop[tmp] = 1;    //tmp是停靠站
            if(j == 1)
                start = tmp;
            if(j == s)
                end = tmp;

        }
        //建立图
        for (int j = start; j <= end ; ++j) {
            if(isStop[j] == 1){ //停靠的站点
                for (int k = start; k <= end ; ++k) {
                    //枚举没有停靠的站点
                    if(!isStop[k] && visit[j][k] == 0){
                        add(j, k);
                        visit[j][k] = 1;
                        ido[k]++;
                    }
                }
            }
        }
    }
    kahn();
    int ans = 0;
    for (int i = 1; i <n ; ++i) {
        ans = max(ans, leval[i]);
    }
    printf("%d", ans);

    return 0;
}