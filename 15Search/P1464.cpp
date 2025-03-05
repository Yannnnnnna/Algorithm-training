//
// Created by WYR on 2025/3/5.
// 将 n写成 k个数相加的形式
//
#include <iostream>
#include <algorithm>
#include<cstring>
#include <vector>
#include <cstdio>
#define LL long long
using namespace std;

LL dp[25][25][25];
LL w(LL a, LL b, LL c){
    /*如果 a≤0 或 b≤0 或 c≤0 就返回值 1。*/
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    /*如果 a>20 或 b>20 或 c>20 就返回 w(20,20,20)*/
    if(a > 20 || b > 20 || c > 20){
        if(dp[20][20][20] != 0){
            return dp[20][20][20];
        } else{
            return dp[20][20][20] = w(20, 20, 20);
        }
    }
    /*如果 a<b 并且 b<c 就返回 w(a,b,c−1)+w(a,b−1,c−1)−w(a,b−1,c)。*/
    if(a < b && b < c){
        if(dp[a][b][c] != 0){
            return dp[a][b][c];
        } else{
            if(dp[a][b][c - 1] == 0){
                dp[a][b][c - 1] = w(a, b, c - 1);
            }
            if(dp[a][b -1][c] == 0){
                dp[a][b- 1][c] = w(a, b - 1, c);
            }
            if(dp[a][b - 1][c - 1] == 0){
                dp[a][b - 1][c - 1] = w(a, b - 1, c - 1);
            }
            return dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
        }
    }
    /*其它的情况就返回 w(a−1,b,c)+w(a−1,b−1,c)+w(a−1,b,c−1)−w(a−1,b−1,c−1)*/
    if(dp[a][b][c] != 0){
        return dp[a][b][c];
    } else{
        if(dp[a - 1][b][c] == 0){
            dp[a - 1][b][c] = w(a - 1, b, c);
        }
        if(dp[a - 1][b - 1][c] == 0){
            dp[a - 1][b - 1][c] = w(a - 1, b - 1, c);
        }
        if(dp[a - 1][b][c - 1] == 0){
            dp[a - 1][b][c - 1] = w(a - 1, b, c - 1);
        }
        if(dp[a - 1][b - 1][c - 1] == 0){
            dp[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
        }
        return dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
    }

}
int main(){
    LL a, b, c;
    while (scanf("%lld%lld%lld", &a, &b, &c)){
        if(a == -1 && b == -1 && c == -1){
            break;
        }
        LL res = w(a, b, c);
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, res);
    }
    return 0;

}