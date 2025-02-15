//
// Created by WYR on 2025/2/15.
//老鼠和奶酪
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    int res = 0;
    int n = reward1.size();
    vector<int> diff(n);
//    先将reward2全部加到res中
    for (int i = 0; i < n; ++i) {
        res += reward2[i];
//        计算reward1和reward2的差值
        diff[i] = reward1[i] - reward2[i];

    }
//    对差值进行排序
    sort(diff.begin(), diff.end());
//    将最大的k个差值加到res中
    for (int j = n - 1; j >= n - k; --j) {
        res += diff[j];
    }
    return res;


}
int main(){
    int k, n, x;
    cin >> k >> n;
    vector<int> reward1(n), reward2(n);
//    读入数据
    for (int i = 0; i < n; ++i) {
        cin >> x;
        reward1.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        cin >> x;
        reward2.push_back(x);
    }
    int res = miceAndCheese(reward1, reward2, k);
    cout << res << endl;
    return 0;
}