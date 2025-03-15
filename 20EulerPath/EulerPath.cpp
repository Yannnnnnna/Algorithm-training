//
// Created by WYR on 2025/3/13.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
//无向欧拉图，找链式前向星， 时间复杂度O(m * ( n + m))
int n, m;
const int maxv = 1005;
const int maxe = 1005;
struct edge{
    int to, next;
    int visit;  //标记是否访问
    int eid; //边的编号
}e[2 * maxe];
int head[maxv];
int cnt;
stack<int> resV;
void add(int x, int y){

    e[cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
    e[cnt].visit = 0;
    e[cnt].eid = cnt;
    ++cnt;  //与边的id对应，防止e[i ^ 1].visit = 1;的时候出现奇偶混乱
}
//void dfs(int x){
//    for (int i = head[x]; i != -1 ; i = e[i].next) {
//        if(e[i].visit == 1){
//            continue;
//        }
//        e[i].visit = 1;
//        e[i ^ 1].visit = 1;
//        dfs(e[i].to);
//    }
//    resV.push(x);
//}
//弧优化 O(m + n)
void dfs(int x){
    for (int i = head[x]; i != -1 ; i = head[x]) {
        if(e[i].visit == 1){
            head[x] = e[i].next;
            continue;
        }
        e[i].visit = 1;
        e[i ^ 1].visit = 1;
        dfs(e[i].to);
    }
    resV.push(x);
}

int main(){
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    dfs(1);
    while (!resV.empty()){
        printf("%d ", resV.top());
        resV.pop();
    }
    return 0;
}