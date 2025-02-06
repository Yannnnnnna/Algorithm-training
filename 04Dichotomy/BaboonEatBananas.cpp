//
// Created by WYR on 2025/2/6.
//喜欢吃香蕉的狒狒
//
//

#include<iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
bool judge(int mid, vector<int>& piles, int h){
    int  cur = 0;
    for (int i = 0; i < piles.size(); ++i) {
        cur += piles[i] / mid;
        if (piles[i] % mid != 0){
            ++cur;
        }
    }
    return (cur <= h);
}
int minEatingSpeed(vector<int>& piles, int h) {
    int res;
    int l = 1, r = 0;
    for (int i = 0; i < piles.size(); ++i) {
        if(piles[i] > r){r = piles[i];}
    }
    int mid;
    while (l <= r){
        mid = (l + r) / 2;
        if(judge(mid, piles, h)){
            res = mid;
            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }
    return res;
}
int main(){
    vector<int> piles = {30,11,23,4,20};
    int h = 6;
    cout << minEatingSpeed(piles, h) << endl;
    return 0;
}
