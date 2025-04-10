//
// Created by WYR on 2025/4/8.
//
#include <bits/stdc++.h>
using namespace std;
int n;
int d[100005];
int ans;
int main(){
    cin >> n;
    for (int i = 1; i <=n ; ++i) {
        cin >> d[i];
    }
    for (int i = 1; i <=n ; ++i) {
        if(d[i] > d[i-1]){
            ans += d[i] - d[i-1];
        }
    }
    cout << ans;
    return 0;
}