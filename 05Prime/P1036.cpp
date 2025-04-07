//
// Created by WYR on 2025/4/6.
//
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int prime[5000005], idx;
int isPrime[500005];
int n,k;
int arr[25];
int ans;
void eulor(){
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i <= 500000; ++i) {
        if(isPrime[i] > 0){
            prime[idx++] = i;
        }
        for (int j = 0; j < idx; ++j) {
            if(i*prime[j] > 500000)break;
            isPrime[i*prime[j]] = 0;
            if(i % prime[j] == 0)break;
        }
    }
}
void dfs(int x, int sum, int now){
    //已经枚举到最后一个
    if(now == k){
        if(isPrime[sum]) ans++;
        return;
    }
    //枚举剩下的k-idx个数
    for(int i = x; i < n; i++){
        dfs(i + 1, sum + arr[i], now + 1);
    }
}
int main(){
    cin >> n >> k;
    eulor();
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dfs(0,0,0);
    cout << ans;
    return 0;
}