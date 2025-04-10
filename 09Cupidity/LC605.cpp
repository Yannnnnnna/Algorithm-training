//
// Created by WYR on 2025/4/8.
//
#include <bits/stdc++.h>
using namespace std;
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if(flowerbed.size()== 0 )return n== 0;
    int len = flowerbed.size();
    int cnt = 1; //0的个数 默认花坛左边有一个0
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        if(flowerbed[i] == 0){
            cnt++;
        } else{
            ans+= (cnt-1)/2;
            cnt = 0;
        }
    }
    //默认花坛右边有一个0
    ans += (cnt+1-1)/2;
    return ans >= n;
}
int main(){
    int n;
    cin >>n;
    vector<int> flower;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        flower.push_back(x);
    }
    cout<<canPlaceFlowers(flower,n);
    return 0;
}