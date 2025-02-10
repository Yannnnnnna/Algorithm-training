//
// Created by WYR on 2025/2/10.
// 埃氏筛法
//
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int isPrime[1000005];
int prime[1000005], cnt = 0;
int main(){
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        isPrime[i] = 1;
    }
    isPrime[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if(isPrime[i]){
            prime[cnt++] = i;
            for (int j = i*2; j <= n; j += i) {
                isPrime[j*i] = 0;
            }
        }
    }
    for (int i = 0; i < cnt; ++i) {
        cout << prime[i] << " ";
    }
    return 0;
}
