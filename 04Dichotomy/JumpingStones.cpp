//
// Created by WYR on 2025/2/4.
//P2678 [NOIP 2015 提高组] 跳石头
//
#include<iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int L;      //总长度
int N;      //起点和终点之间的石头数
int M;      //至多移走的石头数
int stones[50005];  //石头距离起点的位置
int res;
int judge(int mid){
    int x = 0; //需要移动石块的个数
    int nowStone = 0, nextStone = 0;
    while (nextStone < N + 1){
        nextStone++;
        if(stones[nextStone] - stones[nowStone] < mid){
            ++x;    //移走石头
        } else{
            nowStone = nextStone;
        }
    }
    return x > M ? 0 : 1;
}
int main(){
    cin >> L >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> stones[i];
    }
    stones[N + 1] = L;
    int left = 0, right = L - 1;
    int mid;
    while (left <= right){
        mid = (left + right) / 2;
        if(judge(mid) > 0){
            res = mid;
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }
    cout << res << endl;

    return 0;
}