//
// Created by WYR on 2025/3/15.
//双哈希函数法
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

typedef unsigned long long ull;
using namespace std;
ull base = 131;
ull mod1 = 19260817;
ull mod2 = 19660813;
struct data{
    ull x, y;
}a[10005];
char s[10005]; //字符串
int n;
ull StringHash1(){
    int len = strlen(s);
    ull ans = 0;
    for (int i = 0; i < len; ++i) {
        ans = (ans * base + (ull)s[i]) % mod1;   //超过ll会自动取模

    }
    return ans;
}
ull StringHash2(){
    int len = strlen(s);
    ull ans = 0;
    for (int i = 0; i < len; ++i) {
        ans = (ans * base + (ull)s[i]) % mod2;   //超过ll会自动取模

    }
    return ans;
}
bool comp(struct  data x, struct data y){
    return x.x < y.x;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n ; ++i) {
//        memset(s, 0, sizeof(s));
        scanf("%s", s);
        a[i].x = StringHash1();
        a[i].y = StringHash2();

    }
    sort(a + 1, a + 1 + n, comp);
    int res = 1;//从第二个开始和前一个比较，默认有一个
    //经过排序，将相同的放在一起，只要前后出现一个不同的答案就+1
    for (int i = 2; i <= n ; ++i) {
        if(a[i].x != a[i - 1].x || a[i].y != a[i - 1].y ){
            res++;
        }
    }
    printf("%d\n", res);
    return 0;
}
