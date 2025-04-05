//
// Created by WYR on 2025/4/5.
//
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size();
    int res = 0;
    int l = 0;
    int num = 1;
    for(int r = 0; r < n; r++){
        num *= nums[r];
        while(l <= r && num >= k){
            num /= nums[l];
            l++;
        }
        res += r - l + 1;
    }
    return res;
}
int main(){
    int n, m;
    vector<int> s;
    cin>> n >> m;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s.push_back(x);
    }
    cout << numSubarrayProductLessThanK(s, m);
    return 0;
}