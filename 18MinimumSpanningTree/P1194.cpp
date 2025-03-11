//
// Created by WYR on 2025/3/11.
//
#include <cstdio>
#include <cstring>
#include<iostream>
#include <algorithm>
#define LL long long;
#define PII pair<int, int>

using namespace std;
const int N = 505;
int a, b;//输入b行,a表示每个点的权值
struct edge{
    int u, v, w;
}e[N * N];
int fa[N];
int num, m, ans; //m，边数，ans答案
bool cmp(const edge &x, const edge &y){
    return x.w <y.w;
}
int find(int x){

    return x == fa[x] ? x : fa[x] =find(fa[x]);
}
int main(){
    scanf("%d%d", &a, &b);
    for(int i = 1; i <= b; i++){
        fa[i] = i;
    }
    //建立虚点到其他点的边，b个
    for(int i = 1; i <= b; i++){
        m++;
        e[m].u = 0;
        e[m].v = i;
        e[m].w = a;
    }
    for(int i = 1; i <= b; i++){
        for(int j = 1; j <= b; j++){
            scanf("%d", &num);
            if(num !=0){
                m++;
                e[m].u = i;
                e[m].v = j;
                e[m].w = num;
            }
        }
    }
    sort(e + 1, e + m + 1, cmp);
    for(int i = 1; i <= m; i++){
        int u = find(e[i].u);
        int v = find(e[i].v);
        if(u != v){
            ans += e[i].w;
            fa[u] = v;
        }
    }
    printf("%d\n", ans);
    return 0;
}

