//
// Created by WYR on 2025/3/15.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
int nex[105];
void getNext(char s[]){
    int len = strlen(s);
    int i = 1; //主串
    int j = 0; //模式串
    while (i + 1 < len){
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
    char p[105], s[105];
    scanf("%s", &p);
    getchar();
    scanf("%s", &s);
    nex[0] = -1, nex[1] = 0;
    getNext(s);
    //KMP
    int pLen = strlen(p);
    int sLen = strlen(s);
    if(pLen == 0 || sLen == 0){
        printf("failed\n");
        return 0;
    }
    int i = 0;
    int j = 0;
    while (i < pLen && j < sLen){
        if(j == -1 || p[i] == s[j]){
            i++;
            j++;
        } else{
            j = nex[j];
        }
    }
    if(j >= sLen){
        printf("%d\n", i - j);
    }
    return 0;
}
