//
// Created by WYR on 2025/2/13.
//
#include <iostream>
using namespace std;
int a[1000], b[1000], c[1000];
int  init(int x[],string s){
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        x[i] = s[len - i - 1] - '0';
    }
    return len;
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int aLen = init(a, s1);
    int bLen = init(b, s2);
    //判断是否要输出负号
    if(aLen < bLen || (aLen == bLen && s1 < s2)){
        cout << "-";
        swap(a, b);
        swap(aLen, bLen);
    }
    int cLen = max(aLen, bLen);
//    计算，并判断是否要结借位
    for (int i = 0; i < cLen; ++i) {
        if(a[i] < b[i]){
            a[i] += 10;
            a[i + 1]--;
        }
        c[i] = a[i] - b[i];
    }
//    消除前导0
    cLen--;
    while (c[cLen] == 0 && cLen > 0){
        --cLen;
    }
    for (int i = cLen; i >=0 ; --i) {
        cout << c[i];
    }
    return 0;
}