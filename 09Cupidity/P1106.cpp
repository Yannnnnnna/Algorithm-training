//
// Created by WYR on 2025/4/9.
//要保持原来的顺序，去掉两个最大的数的子序列
#include<bits/stdc++.h>
using namespace std;
char n[255];
int num[255];
int k;
int main(){
    scanf("%s", n + 1);
    cin >> k;
    int len = strlen(n+1);
    for(int i = 1; i<= len;i++){
        num[i] = n[i] - '0';
    }
    vector<int> ans;
    for(int i = 1; i <= len ;i++){
        while (k > 0 && !ans.empty() && ans.back()> num[i]){
            ans.pop_back();
            k--;
        }
        ans.push_back(num[i]);
    }
    //前面全为递增，删除结尾
    while (k--){
        ans.pop_back();
    }
    //删除前导0
    while (ans.front() == 0 && ans.size() > 1) {ans.erase(ans.begin());}
    for (int an : ans) {
        cout<<an;
    }
    return 0;
}