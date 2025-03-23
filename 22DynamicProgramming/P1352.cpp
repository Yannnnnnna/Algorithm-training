//
// Created by WYR on 2025/3/21.
//树形DP
//
#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 60005
using namespace std;
int n, r[maxn];
bool v[maxn];  //标记是否有父节点，用于寻找根节点
int f[maxn][2];
vector<int> tree[maxn];
void dfs(int x){  //以x为根的子树的最大快乐值
    f[x][1] = r[x]; //只有x去
    f[x][0] = 0; //x不去
    int y;
    for(int i = 0;i < tree[x].size();i++){
        y = tree[x][i];
        dfs(y);
        f[x][1] += f[y][0];
        f[x][0] += max(f[y][1], f[y][0]);
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> r[i];
    }
    int l,k;
    for(int i = 1; i <= n -1 ;i++){
        cin >> l>>k;
        v[l] = 1;
        tree[k].push_back(l);

    }
    int root;
    for(int i = 1;i <= n; i++){
        if(v[i] == 0){
            root = i;
            break;
        }

    }
    dfs(root);
    cout<<max(f[root][1], f[root][0]);
    return 0;
}
