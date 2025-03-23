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
        /*建树*/
        update(i, a[i]);
    }
    int p, x, y, k;
    for (int i = 1; i <= m ; ++i) {
        scanf("%d", &p);
        if(p == 1){
            scanf("%d %d", &x, &k);
            update(x, k);
        } else{
            scanf("%d %d", &x, &y);
            printf("%lld\n", ask(y) - ask(x - 1));
        }
    }

    return 0;
}