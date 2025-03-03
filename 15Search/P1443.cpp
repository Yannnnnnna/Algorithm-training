//
// Created by WYR on 2025/3/3.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int dx[8] = {-2, -2, 2, 2, 1, -1, 1, -1};
int dy[8] = {-1, 1, -1, 1, 2, -2, -2, 2};
struct node{
    int x, y;
};
queue<node> q;
int n, m ,res[405][405], sx, sy;
int visit[405][405];
int main(){
    scanf("%d%d%d%d", &n, &m, &sx, &sy);
    memset(res, -1, sizeof (res));
    struct node s, a, next;
    s.x = sx;
    s.y = sy;
    q.push(s);
    res[sx][sy] = 0;
    visit[sx][sy] = 1;
    while (!q.empty()){
        a = q.front();
        for (int i = 0; i < 8; ++i) {
            next.x = a.x + dx[i];
            next.y = a.y + dy[i];
            if(next.x >= 1 && next.x <= n
              && next.y >= 1 && next.y <= m
              && visit[next.x][next.y] == 0){
                q.push(next);
                visit[next.x][next.y] = 1;
                res[next.x][next.y] = res[a.x][a.y] + 1;
            }
        }
        q.pop();
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%-5d", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}