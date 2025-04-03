//
// Created by WYR on 2025/4/1.
//
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#define maxn 200005
#define LL long long
using namespace std;
//前缀和 + 二分

LL n, m, s; //石头个数， 区间数目， 均值
int v[maxn];	//价值数组
int w[maxn];	//重量数组
int l[maxn];
int r[maxn];
LL y;
LL ans = INT64_MAX;
int maxw, minw=0x3fffffff;
LL wi[maxn];
LL vi[maxn];
int check(LL mid){
    memset(wi, 0,sizeof(wi));
    memset(vi, 0, sizeof(vi));
    for(int i = 1; i <= n; i++){
        wi[i] = (LL)wi[i - 1] + (w[i] >= mid);
        vi[i] = (LL)vi[i-1] + (w[i] >= mid ? v[i] : 0);
    }
    y = 0;
    for(int i = 1; i <= m; i++){
        y += (wi[r[i]]- wi[l[i] - 1]) * (vi[r[i]] - vi[l[i] - 1]);
    }

    if(y > s){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &w[i], &v[i]);
        maxw = max(maxw, w[i]);
        minw = min(minw, w[i]);
    }
    for(int i = 1; i <= m;i++){
        scanf("%d %d", &l[i], &r[i]);
    }
    int ll = minw;
    int rr = maxw;
    while(ll <= rr){
        LL mid = (ll + rr) >> 1;
//		如果多了，就说明通过线（W）太低了，就往上调，否则就说明通过线高了，往下调。
        if(check(mid)){
            ll = mid + 1;
        }else{
            rr = mid - 1;
        }
        ans = min(ans, abs(s-y));
    }
    cout << ans;
    return 0;
}