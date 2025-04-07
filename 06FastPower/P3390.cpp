//
// Created by WYR on 2025/4/7.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;
const int MAXN = 105;
LL n,k;
LL mapp[MAXN][MAXN];
LL ans[MAXN][MAXN];
void jzcf(LL res[][MAXN], LL m1[][MAXN], LL m2[][MAXN]){
    LL tmp[MAXN][MAXN] = {0};
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            for (int l = 1; l <=n ; ++l) {
                tmp[i][j] = (tmp[i][j] +  m1[i][l] * m2[l][j]) % mod;
            }
        }
    }
    memcpy(res,tmp,sizeof (tmp));
}
void pow(){
    // 初始化ans为单位矩阵
    for (int i = 1; i <= n; ++i) ans[i][i] = 1;
    while (k != 0){
        if(k %2 == 1){
            jzcf(ans, ans, mapp);
        }
        jzcf(mapp,mapp,mapp);
        k /= 2;
    }
}
int main(){
    cin >> n >>k;
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            cin >> mapp[i][j];
        }
    }
    pow();
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}