//
// Created by WYR on 2025/4/7.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b, p;
ll  pow(ll x, ll n){
    ll ans = 1;
    while (n!= 0){
        if(n % 2 == 1) ans = (x*ans) % p;
        x = (x*x)%p;
        n/= 2;
    }
    return ans;
}
int main(){
    cin >> a >> b >> p;
    ll s = pow(a,b) % p;
    printf("%lld^%lld mod %lld=%lld", a,b,p,s);
    return 0;
}