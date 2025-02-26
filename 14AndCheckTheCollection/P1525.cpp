//
// Created by WYR on 2025/2/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct prime{
    int a, b, c;
}x[100005];
int n, m, f[20005];
int find(int k){
    if(f[k] == k){
        return k;
    }
    f[k] = find(f[k]);  /*路径压缩*/
    return f[k];
}
int comp(prime i, prime j){
    return i.c > j.c;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
        f[i + n] = i + n;   //i的天敌
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &x[i].a, &x[i].b, &x[i].c);
    }
    //排序,对sort函数进行改写
    sort(x + 1, x + m + 1, comp);
    int res = 0;
    for (int i = 1; i <= m; ++i) {
        int fa = find(x[i].a);
        int ffa = find(x[i].a + n);
        int fb = find(x[i].b);
        int ffb = find(x[i].b + n);
        if(fa == fb || ffa == ffb){     //两个不得不分在一起，就是结果
            res = x[i].c;
            break;
        } else{
            //分开属于两个监狱
            f[fa] = ffb;
            f[fb] = ffa;
        }
    }
    printf("%d\n", res);

    return 0;
}