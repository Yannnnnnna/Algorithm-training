//
// Created by WYR on 2025/4/10.
//
#include <bits/stdc++.h>
using namespace std;
string digui(){
    int k; // 重复的数字
    char c; //输入的字符
    string s = "";  //结果字符串
    string str = ""; //重复子串
    while (cin >> c){
        if(c == '['){
            cin >> k;
            str = digui();
            while (k--){
                s+= str;
            }
        }
        else if(c == ']'){
            return s;
        } else{
            s += c;
        }
    }
    return s;
}
int main(){
    cout << digui();
}