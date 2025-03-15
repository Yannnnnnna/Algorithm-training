//
// Created by WYR on 2025/3/13.
//

#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
const int maxv = 100005;
struct edge{
    int v;
    int visit;  //标记是否访问
};
vector<edge> v[100005];
int in[maxv];     //出度-入度的差值
stack<int> s;
int st[maxv];   //标记当前应该访问第几个

//弧优化 O(m + n)
void dfs(int x){
    for (int i = 0; i < v[x].size(); i = max(st[x], i + 1)) {
        if(v[x][i].visit == 1){
            continue;
        }
        st[x] = i + 1;      //当前应该访问第几个
        v[x][i].visit = 1;
        dfs(v[x][i].v);
    }
    s.push(x);
}
bool comp(edge x, edge y){
    return x.v < y.v;
}
int main(){
    scanf("%d%d", &n, &m);
    struct edge e;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
       // x -> y
       in[x]++;
       in[y]--;
       e.v = y;
       e.visit = 0;
       v[x].push_back(e);

    }

    //判断图是不是（半）欧拉图
    int fs = 0, fe = 0; //终点和起点的个数
    int ps = 1;  //防止是欧拉图，所有都为0，默认为最小点
    int pe = 0; //终点
    for (int i = 1; i <= n ; ++i) {
        if(in[i] > 1 || in[i] < -1){
            printf("No\n");
            return 0;
        }
        if(in[i] == 0) continue;
        if(in[i] == 1){
            fs++;
            ps = i;
        }
        if(in[i] == -1){
            fe++;
            pe = i;
        }
        if(fs > 1 || fe > 1){
            printf("No\n");
            return 0;
        }

    }
    //进行排序
    for (int i = 1; i <= n; ++i) {
        sort(v[i].begin(), v[i].end(), comp);
    }
    dfs(ps);
    while (!s.empty()){
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
    return 0;
}