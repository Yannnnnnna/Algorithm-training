//
// Created by WYR on 2025/4/6.
//
#include <iostream>
#include <cstdio>
using namespace std;
//prime 数组用于存储分解质因数得到的质因数，cnt 数组用于存储每个质因数的指数。
int cnt[300010];    //记录i在分解中出现的次数
int prime[300010];  //记录分解结果
int s[10005];
int m1, m2, n;
int  primeFactorization(int m){
    int x = 0;
    for (int i = 2; i * i<= m ; ++i) {
        if(m % i == 0){  //z找到一个因数
            prime[++x] = i;//加入因数数组
            while (m % i == 0){//记录因数出现的次数
                cnt[x]++;
                m /= i;
            }

        }
    }
    //现在>1说明本身是质数
    if(m > 1){
        cnt[++x] = 1;
        prime[x] = m;
    }
    for (int i = 1; i <= x; ++i) {
        cnt[i] = cnt[i] * m2;
    }
    return x;
}
int main(){
    cin >> n >>m1 >>m2;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    if(m1 == 1){
        cout << 0;
        return 0;
    }
    int ans  = 0x7fffffff;
    int num = primeFactorization(m1);
    for (int i = 1; i <= n ; ++i) {     //遍历每一个细胞
        int time = 0;
        //内层循环遍历 m1 的所有质因数。
        for (int j = 1; j <=num ; ++j) {
            //出现s没有的质因数,一定无法除尽
            if(s[i] % prime[j] != 0){
                time = 0x7fffffff;
                break;
            }
            //记录当前因数出现的次数
            int k = 0;
            while (s[i] % prime[j] ==0){
                k++;
                s[i] /= prime[j];
            }
            //如果 cnt[j] 不能被 c 整除，需要多花一秒时间，tmp 为 1，否则为 0。
            int tmp = cnt[j] % k == 0 ? 0:1;
            //更新 ans 为 ans 和 cnt[j]/c + tmp 中的较大值，因为要满足所有质因数的要求，所以取最大值。
            time = max(time, cnt[j] / k + tmp);
        }
        ans = min(ans, time);
    }
    cout << (ans == 0x7fffffff?-1:ans);
    return 0;
}