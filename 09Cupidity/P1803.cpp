//
// Created by WYR on 2025/4/8.
//要按结束时间进行排序，越早结束越要参加
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
struct race{
    int a,b;
}race[MAXN];
int n;
bool comp(struct race n1, struct race n2){
    return n1.b < n2.b;
}
int main(){
    cin >> n;
    for (int i = 1; i <=n ; ++i) {
        cin >> race[i].a >> race[i].b;
    }
    sort(race + 1, race + 1 + n, comp );
    int ans = 1;
    int s = race[1].a, e = race[1].b;
    for (int i = 2; i <= n ; ++i) {
        if(race[i].a >= e){
            s = race[i].a;
            e = race[i].b;
            ans++;
        }
    }
    cout << ans;

    return 0;
}
