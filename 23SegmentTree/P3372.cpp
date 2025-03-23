//
// Created by WYR on 2025/3/22.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#define ll  unsigned long long
using namespace std;
const int maxn = 100005;
int a[maxn];
struct node{
    ll l,r,sum, lazyTag;
}tree[maxn * 4];
//建树
void build(int i, int l, int r){
    tree[i].l = l;
    tree[i].r = r;
    tree[i].lazyTag = 0;
    if(l == r){
        tree[i].sum = a[l];
        return;
    }
    ll m = (l + r) / 2; // /2
    build(2 * i, l, m);
    build(2 * i + 1, m + 1 ,r);
    tree[i].sum = tree[2 * i].sum + tree[2*i + 1].sum;
}
//单点修改
//void update(int p, int o, int k ){  //要修改的节点， 当前节点， 要加的数
//    if(tree[o].l == tree[o].r){
//        a[o] += k;
//        tree[o].sum += k;
//        return;
//    } else{
//        int mid = (tree[o].l + tree[o].r) / 2;
//        if(p <= mid){
//            update(p, o * 2 , k);
//        } else{
//            update(p, o * 2 + 1, k);
//        }
//        tree[o].sum = tree[o * 2].sum + tree[o *2 + 1].sum;
//    }
//}
//区间修改
void down(ll i){
    tree[2 * i].lazyTag += tree[i].lazyTag;
    tree[2 * i].sum += (tree[2 * i].r - tree[2*i].l + 1)*tree[i].lazyTag;

    tree[2 * i + 1].lazyTag += tree[i].lazyTag;
    tree[2 * i + 1].sum += (tree[2 * i + 1].r - tree[2*i + 1].l + 1)*tree[i].lazyTag;

    tree[i].lazyTag = 0;
}
void update(ll i, ll l, ll r, ll k){ //当前节点，修改区间 l~r 加上的值k
//    完全无关
    if(tree[i].r <l || tree[i].l > r){
        return;
    }
//    刚好覆盖
    if((tree[i].l >=l) && (tree[i].r <= r)){
        tree[i].lazyTag += k;
        tree[i].sum += (tree[i].r - tree[i].l + 1) * k;
        return;
    }
//    部分覆盖
    if(tree[i].lazyTag > 0){
        down(i);
    }
    update(2 * i, l, r, k);
    update(2 * i + 1, l, r, k);
    tree[i].sum = tree[i * 2].sum + tree[i *2 + 1].sum;

}
//区间查询
ll query(ll l, ll r, ll i){
    //    完全无关
    if(tree[i].r <l || tree[i].l > r){
        return 0;
    }
//    刚好覆盖
    if(tree[i].l >=l && tree[i].r <= r){

        return tree[i].sum;
    }
//    部分覆盖
    if(tree[i].lazyTag > 0){
        down(i);
    }
    return query(l,r,2*i) + query(l,r,2*i + 1);
}
int main(){
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n ; ++i) {
        scanf("%d",&a[i]);
    }
    build(1, 1 ,n);
    int v; //判断是什么操作
    for (int i = 1; i <= m ; ++i) {
        scanf("%d", &v);
        if(v == 1){
            int x, y, k;
            scanf("%d %d %d",&x,&y,&k);
            update(1, x, y, k);
        } else{
            ll x, y;
            scanf("%lld %lld",&x,&y);
            ll sum;
            sum=query(x, y, 1);
            printf("%lld\n",sum);

        }
    }
    return 0;
}