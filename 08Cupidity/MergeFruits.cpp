//
// Created by WYR on 2025/2/15.
//合并果子
//
#include <iostream>
#include <queue>
using namespace std;

int n, x, y;
long long res = 0;
//    优先队列默认是大根堆，所以要用greater<>来改变比较方式
priority_queue<long long , vector<long long>, greater<>> q;

int main(){
    cin >> n;
//    读入果子数并将果子放入优先队列
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        q.push(temp);
    }
//    每次取出两个最小的果子合并，再放入优先队列
    for (int i = 1; i < n; ++i) {
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        res += x + y;
        q.push(x + y);
    }
//    输出结果
    cout << res << endl;
    return 0;
}