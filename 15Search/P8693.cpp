//
// Created by WYR on 2025/3/3.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXLEN 90000   //最大状态数
using namespace std;
//上下左右移动坐标变化
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct node{
    int x, y, time;
};
struct node q[MAXLEN + 5];  //循环队列
int flag = 2;   //开始属于 5*5 状态
int n, k;
char map[305][305];
int visit[305][305];    //标记是否访问过
int main(){

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", &map[i][1]);
    }
    struct node start, now, next;
    start.x = 3;
    start.y = 3;
    start.time = 0;
    visit[3][3] = 1;
    int front = 0, rear = 0;
    q[rear++] = start;  //入队
    while (front != rear){
        //出队
        now = q[front];
        front = (front + 1) % MAXLEN;
        if(now.time == k){
            flag = 1;   //瘦身成3*3
        } else if(now.time == 2*k){
            flag = 0;   //瘦身成1*1
        }
        //不动, 瘦身成1*1之前,都可以在原地休息
        if(flag != 0){
            next.x = now.x;
            next.y = now.y;
            next.time = now.time + 1;
            q[rear] = next;
            rear = (rear + 1) % MAXLEN;
        }
        //动
        for (int i = 0; i < 4; ++i) {   //上下左右四个方向走
            next.x = now.x + dx[i];
            next.y = now.y + dy[i];
            if(next.x >= 1 && next.x <= n
            && next.y >= 1 && next.y <= n
            && visit[next.x][next.y] == 0){
//               判断是否可以走
                int ok = 1;
//                检查胖的部分是否越界或者有障碍物
                for (int nx = next.x - flag; nx <=next.x + flag ; ++nx) {
                    for (int ny = next.y - flag; ny <= next.y + flag ; ++ny) {
                        if(nx < 1 || nx > n || ny < 1 || ny > n || map[nx][ny] == '*'){
                            ok = 0;
                            break;
                        }

                    }
                    if(ok == 0){
                        break;
                    }
                }
//                可以走
                if(ok){
//                    判断是否到达终点
                    if(next.x == n - 2 && next.y == n - 2){
                        printf("%d\n", now.time + 1);
                        return 0;
                    } else{
//                        没有到达终点,走next
                        visit[next.x][next.y] = 1;
                        next.time = now.time +1;
                        q[rear] = next;
                        rear = (rear + 1) % MAXLEN;
                    }
                }
            }
        }

    }
    return 0;
}