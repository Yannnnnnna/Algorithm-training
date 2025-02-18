//
// Created by WYR on 2025/2/18.
//分治法求最大子段和
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int max_mid(vector<int>& nums, int l, int r, int mid){
    int lmax = INT_MIN, rmax = INT_MIN;
    int sum = 0;
//    从mid到l的最大值
    for (int i = mid; i >= l ; --i) {
        sum += nums[i];
        lmax = max(lmax, sum);
    }
    sum = 0;
//    从mid+1到r的最大值
    for (int i = mid + 1; i <= r; ++i) {
        sum += nums[i];
        rmax = max(rmax, sum);
    }
//    返回最大值
    return lmax + rmax;
}
int maxNum(vector<int>& nums, int l, int r){
    if(l == r){     //递归出口
        return nums[l];
    }
    int mid = (l + r) / 2;
//    递归求解左右两部分
    int lsum = maxNum(nums, l, mid);
    int rsum = maxNum(nums, mid + 1, r);
//    求解中间部分
    int msum = max_mid(nums, l, r, mid);
    return max(max(lsum, rsum), msum);
}


int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    res = maxNum(nums, 0, n - 1);
    return res;
}
int main(){
    int x,n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        a.push_back(x);
    }
    cout <<maxSubArray(a) << endl;
    return 0;
}