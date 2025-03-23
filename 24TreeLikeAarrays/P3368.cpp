//
// Created by WYR on 2025/3/22.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define ll long long
#define N 500005
using namespace std;
int a[N];
int b[N]; //差分数组
int tree[N];
int n,m;
//树状数组的三个函数
ll lowbit(int x){
    return x & (-x);
}
void update(int x, int k){
    //x 位置 加上k
    for (ll i = x; i <= n; i += lowbit(i)) {
        tree[i] += k;
    }
}
//前缀和
ll ask(int x){
    ll sum = 0;
    for (ll i = x; i > 0 ; i -= lowbit(i)) {
        sum += tree[i];
    }
    return sum;
}
int main(){
    cin >> n>>m;
    for (int i = 1; i <= n ; ++i) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= n ; ++i) {
        update(i, b[i]);
    }
    int p, x, y, k;
    for (int i = 1; i <= m ; ++i) {
        scanf("%d", &p);
        if(p == 1){
            //a[x ~y] + k ===> 查分数组的单点修改
            scanf("%d %d %d", &x, &y, &k);
            update(x, k);
            update(y + 1, -k);
        } else{
            scanf("%d", &x);
            printf("%lld\n", ask(x));
        }
    }

    return 0;
}