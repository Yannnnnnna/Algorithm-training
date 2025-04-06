//
// Created by WYR on 2025/4/6.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#define LL long long
using namespace std;
LL n,l,k;
LL road[100005];
int check(LL x){
    LL cnt = 0;
    for(int i = 1; i < n; i++){
        if(road[i+1] - road[i] > x){
            cnt += (road[i+1] - road[i] -1) / x ;
        }
    }
    if(cnt > k) return 0;
    return 1;
}
int main(){
    cin >> l >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> road[i];
    }
    LL ll = 1;  //需要从1开始，如果从0开始，长度为 0会报错
    LL rr = l;
    LL ans = INT_MAX;
    while (ll <= rr){
        LL mid = (ll + rr) >> 1;
        if(check(mid)){
           rr = mid - 1;
            ans = min(ans , mid);
        } else{
            ll = mid + 1;
        }

    }
    cout << ans;
    return 0;
}