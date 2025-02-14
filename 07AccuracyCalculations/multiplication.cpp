//
// Created by WYR on 2025/2/14.
//
#include <iostream>

using namespace std;
int a[1000], b[1000], c[1000];
int init(int x[]){
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        x[i] = s[len - i- 1] - '0';
    }
    return len;
}
int main(){
    int aLen = init(a);
    int bLen = init(b);
    int cLen = aLen + bLen;
    //进行乘法运算
    for (int i = 0; i < aLen; ++i) {
        for (int j = 0; j < bLen; ++j) {
            c[i + j] += a[i] * b[j];
        }
    }
//    进位
    for (int i = 0; i < cLen; ++i) {
        if(c[i] >= 10){
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
//    消除前导0
    while (cLen > 0 && c[cLen] == 0)
        cLen--;
//    输出结果
    for (int i = cLen; i >= 0; --i) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}