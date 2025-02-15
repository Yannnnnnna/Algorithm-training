//
// Created by WYR on 2025/2/15.
//跳跳
//
#include <iostream>
#include <algorithm>        //sort函数

using namespace std;
int n;
int h[305];
int main(){
    cin >> n;
//    读入数据
    for (int i = 1; i <=n ; ++i) {
        cin  >> h[i];
    }
    h[0] = 0;
    long long res = 0;
//    双指针
    int l = 0, r = n;
//    排序
    sort(h, h + n + 1);
//    计算
    while(l < r){
//        两端的差值的平方
        res += (h[r] - h[l]) * (h[r] - h[l]);
        l++;
        res += (h[r] - h[l]) * (h[r] - h[l]);
        r--;
    }
    cout << res << endl;
    return 0;
}
