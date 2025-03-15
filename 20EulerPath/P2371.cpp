//
// Created by WYR on 2025/3/14.
//
#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;
int m; //边的个数
int g[505][505]; //邻接矩阵存图
int du[505]; //度
int start = -1;
int minn = 0x3f3f3f3f;
stack<int> s;

void dfs(int x) {
    for (int i = 1; i <= 500; ++i) {
        if (g[x][i] >= 1) {
            g[x][i]--;
            g[i][x]--;
            dfs(i);
        }
    }
    s.push(x);
}

int main() {

    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y]++;
        g[y][x]++;
        du[x]++;
        du[y]++;
        minn = min(min(x, y), minn);//最小编号，不一定是1
    }
    for (int i = 1; i <= 500; ++i) {
        if (du[i] % 2 == 1) {
            start = i;
            break;
        }
    }
    if (start != -1) {    //欧拉路径
        dfs(start);

    } else {     //欧拉回路
        dfs(minn);
    }
    while (!s.empty()) {
        printf("%d\n", s.top());
        s.pop();
    }

}

