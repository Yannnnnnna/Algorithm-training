//
// Created by WYR on 2025/2/21.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int a[3000005], f[3000005];
stack<int> s;
int main(){
    int n;
//    cin >> n;
    scanf("%d", &n);    //输入优化
    for (int i = 1; i <= n; ++i) {
//        cin >> a[i];
        scanf("%d", &a[i]);    //输入优化
    }
    for (int i = n; i >= 1; --i) {
        while (!s.empty() && a[s.top()] <= a[i]){
            s.pop();
        }
        f[i] = (s.empty() == 1) ? 0 : s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; ++i) {
//        cout << f[i] << " ";
        printf("%d ", f[i]);
    }

    return 0;
}