//
// Created by WYR on 2025/2/13.
// 快速幂 n^x
// 时间复杂度O(logx)
//
#include <iostream>
using namespace std;
int n, x;
int res = 1;
int main(){
    cin >> n >> x;
    while (x != 0){
        if(x % 2 == 1){
            res *= n;
        }
        n *= n;
        x /= 2;
    }
    cout << res << endl;
    return 0;
}