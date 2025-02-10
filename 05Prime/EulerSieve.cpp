//
// Created by WYR on 2025/2/10.
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
    isPrime[0] = 0;
    for (int i = 2; i <= n; ++i) {
        if(isPrime[i]) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt; j++) {     //遍历已有的素数
            if(i * prime[j] > n){   //如果i*prime[j]超过了n，就不用再继续了
                break;
            }
                isPrime[prime[j] * i] = 0;  //以倍数i倍将prime[j]标记为非素数
//            isPrime[i * prime[j]] = 0;  //以倍数i倍将prime[j]标记为非素数
            if(i % prime[j] == 0){  //只筛选到prime[j]为最小质因数的数
                break;
            }
        }
    }
    for (int i = 0; i < cnt; ++i) {
        cout << prime[i] << " ";
    }
    return 0;
}
