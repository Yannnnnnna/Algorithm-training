//
// Created by WYR on 2025/3/15.
//自然取余法
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

typedef unsigned long long ull;
using namespace std;

ull base =  131;
ull a[10005]; //a[i] 对应第i个字符的哈希值
char s[10005]; //字符串
int n;
ull StringHash(){
    int len = strlen(s);
    ull ans = 0;
    for (int i = 0; i < len; ++i) {
        ans = ans * base + (ull)s[i];   //超过ll会自动取模
    }
    return ans;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n ; ++i) {
//        memset(s, 0, sizeof(s));
        scanf("%s", s);
        a[i] = StringHash();
    }
    sort(a + 1, a + 1 + n);
    int res = 1;//从第二个开始和前一个比较，默认有一个
    //经过排序，将相同的放在一起，只要前后出现一个不同的答案就+1
    for (int i = 2; i <= n ; ++i) {
        if(a[i] != a[i - 1]){
            res++;
        }
    }
    printf("%d\n", res);
    return 0;
}
