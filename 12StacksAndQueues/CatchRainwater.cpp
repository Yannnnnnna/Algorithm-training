//
// Created by WYR on 2025/2/21.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <cstdio>

using namespace std;
int trap(vector<int>& height) {
    int n = height.size();
    int res = 0;
    stack<int> s;
//    将下标0入栈
    s.push(0);
    for (int i = 1; i < n; ++i) {
//        如果栈不为空且当前高度大于栈顶高度
        while (!s.empty() && height[i] > height[s.top()]){
            int mid = s.top();
            s.pop();    /*栈顶出栈*/
            if(!s.empty()){     /*栈不为空*/
//              计算宽度和高度
                int t = s.top();
                int w = i - t - 1;
                int h = min(height[i],height[t]) - height[mid];
                res += w * h;
            }
        }
//      当前下标入栈
        s.push(i);
    }
    return res;
}
int main(){
    int n;
    scanf("%d", &n);
    vector<int> h;
    int x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        h.push_back(x);
    }
    int res = trap(h);
    printf("%d\n", res);
    return 0;
}
