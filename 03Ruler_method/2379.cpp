//
// Created by WYR on 2025/4/5.
//
//滑动窗口
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
vector<int> s;
int minimumRecolors(string blocks, int k) {
    int n = blocks.size();
    int sum = 0; //白块的个数
    int ans = INT_MAX;
    int l = 0, r= 0;
    while (r < k){
        if(blocks[r] == 'W'){
            sum++;
        }
        r++;
    }
    while (r < n){
        if(blocks[r] == 'W') sum++;
        if(blocks[l] == 'W') sum--;
        l++;
        r++;
        ans = min(ans, sum);
    }
    return ans;
}
int main(){
    string block;
    int k;
    cin >> block >> k;
    cout << minimumRecolors(block,k);
    return 0;
}