//
// Created by WYR on 2025/4/10.
//
#include <bits/stdc++.h>
using namespace std;
int m,s,t;
int main(){
    cin >> m >> s>>t;
    int magicS = 0; //用魔法+等待组合的距离
    int ans = 0; //最终跑的距离
    for (int i = 0; i < t; ++i) {
        if(m >= 10){ //能用魔法用魔法
            magicS+= 60;
            m -=10;
        } else{ //不能用魔法等待恢复
            m+=4;
        }
        ans += 17;  //计算如果跑步的距离是多少
        ans = max(ans, magicS);
        //选择跑步的情况是还没到使用魔法的点数,但是离终点不需要60m这时候跑步会更快到达终点
        if(ans >= s){
            cout << "Yes"<< endl << i + 1 << endl;
            return 0;
        }
    }
    cout << "No"<< endl << ans << endl;
    return 0;

}