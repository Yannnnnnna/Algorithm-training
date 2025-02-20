//
// Created by WYR on 2025/2/20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

int q, a[100005], b[100005];
stack<int> s;

int main(){
    cin >> q;
    while (q--){
//        清空栈
        while (!s.empty()){
            s.pop();
        }
//       清空数组
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int j = 0;
        for (int i = 0; i < n; ++i) {
            s.push(a[i]);
            while (s.top() == b[j]){
                s.pop();
                ++j;
                if(s.empty())break;
            }
        }
        if(s.empty()){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;

        }
    }
    return 0;
}