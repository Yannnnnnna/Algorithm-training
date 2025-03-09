//
// Created by WYR on 2025/3/9.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int s;  //起点
int n, m;  //n个点，m条边
int dis[105];   //存储起点到各个点的距离
struct edge{
    int a, b, w;
}e[10005];
void ford(){
    int x, y, w;
    int flag = 0;
    //n - 1次松弛
    for (int i = 1; i <= n - 1 ; ++i) {
        flag = 0;
        //松弛操作,对每一条边进行松弛
        for (int j = 0; j < m; ++j) {
            x = e[j].a;
            y = e[j].b;
            w = e[j].w;
            //如果dis[y] > dis[x] + w,则更新dis[y]
            if(dis[y] > dis[x] + w){
                dis[y] = dis[x] + w;
                flag = 1;
            }
        }
        //如果没有更新dis,说明没有边可以松弛，则退出循环
        if (flag == 0) {
            break;
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w);
    }
    scanf("%d", &s);
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    ford();
    return 0;
}

