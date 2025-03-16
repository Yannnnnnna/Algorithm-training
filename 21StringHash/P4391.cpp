//
// Created by WYR on 2025/3/15.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
int nex[1000005];
void getNext(char s[]){
    int len = strlen(s);
    int i = 1; //主串
    int j = 0; //模式串
    nex[0] = -1;
    nex[1] = 0;
    while (i + 1 <= len){
        if(j == -1 || s[i] == s[j]){
            i++;
            nex[i] = j + 1;
            j++;
        } else{
            j = nex[j];
        }
    }
}

int main(){
    int l;
    scanf("%d", &l);
    getchar();
    char s[1000005];
    scanf("%s", &s);
    nex[0] = -1, nex[1] = 0;
    getNext(s);
    printf("%d", l - nex[l]);
    return 0;
}
