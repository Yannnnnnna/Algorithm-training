//
// Created by WYR on 2025/2/20.
//
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> res;
    int n = asteroids.size();
    for (int i = 0; i < n; ++i) {
        if(res.empty() || asteroids[i] > 0){
            res.push_back(asteroids[i]);
        } else{
            while (!res.empty() && res.back() > 0
            && res.back() < abs(asteroids[i])){
                res.pop_back();
            }
            if(res.empty() || res.back() < 0){
                res.push_back(asteroids[i]);

            } else if (res.back() == abs(asteroids[i])){
                res.pop_back();
            }
        }
    }
    return res;
}
int main(){
    vector<int>  a;
    vector<int> res;
    int x, n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    res = asteroidCollision(a);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}