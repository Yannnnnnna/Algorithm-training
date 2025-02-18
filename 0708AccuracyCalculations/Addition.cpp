//
// Created by WYR on 2025/2/13.
//
#include <iostream>

using namespace std;
int a[1000], b[1000], c[1000];
int  init(int x[]){
    string  s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        x[i] = s[len - i - 1] - '0';
    }
    return len;
}
int main(){
    int aLen = init(a);
    int bLen = init(b);
    int cLen = max(aLen, bLen);
    for (int i = 0; i < cLen; ++i) {
        c[i] += a[i] + b[i];
        if(c[i] >= 10){
            c[i] -= 10;
            c[i + 1]++;
        }
    }
    if(c[cLen] > 0){
        cout << c[cLen];
    }
    for (int i = cLen - 1; i >= 0 ; --i) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}