//
// Created by WYR on 2025/4/3.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long

using namespace std;
double n, p;   //n个设备， 每秒p电量的充电宝
double a[100005]; //每秒消耗ai
double b[100005]; //开始存储bi的电量
double t;
//最大化最小值
int check(double x){
    double maxt = p * x;
    double sum = 0;
    for(int i = 1; i <= n; i++){
        if(x*a[i] <= b[i]) continue;
        sum += x*a[i] - b[i];
    }
    if(sum > maxt)return 0;
    return 1;
}
int main(){
    scanf("%lf %lf", &n, &p);
    double sum = 0;
    for(int i = 1; i<= n; i++){
        scanf("%lf %lf", &a[i], &b[i]);
        sum += a[i];
    }
    if(p >= sum) {
        cout << -1;
        return 0;
    }
    double l = 0, r = 1e10;
    while (r - l > 1e-6){
        double mid = (l + r) / 2;
        if(check(mid)){
            l = mid;
            t = max(t, mid);
        } else{
            r = mid;
        }
    }
    cout << t;
    return 0;
}