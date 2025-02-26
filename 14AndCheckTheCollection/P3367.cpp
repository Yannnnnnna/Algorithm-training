//
// Created by WYR on 2025/2/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int n, m, x, y, z;
int f[200005];
int find(int k){
    if(f[k] == k){
        return k;
    }
    f[k] = find(f[k]);  /*路径压缩*/
    return f[k];
}
int main(){
    scanf("%d%d", &n, &m);
//    初始化fi
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d",&z, &x, &y);
        if(z == 1){
           f[find(x)] = find(y);
        }
        if(z == 2){
            if(find(x) == find(y)){
                printf("Y\n");
            } else{
                printf("N\n");
            }
        }
    }

    return 0;
}