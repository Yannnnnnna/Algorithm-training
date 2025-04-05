//
// Created by WYR on 2025/4/5.
//
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
vector<int> s;
int minSubArrayLen(int target, vector<int>& nums) {
    int res = INT_MAX;
    int n = nums.size();
    int l = 0;
    int sum = 0;
    for (int r = 0; r < n; ++r) {
        sum += nums[r];
        while (r >= l && sum - nums[l] >= target){
            sum -= nums[l];
            l++;
        }
        if(sum >= target){
            res = min(res, r- l + 1);
        }
    }
    return res == INT_MAX ? 0 : res;
}
int main(){
    int n, m;
    cin>> n >> m;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s.push_back(x);
    }
    cout << minSubArrayLen(m, s);
    return 0;
}